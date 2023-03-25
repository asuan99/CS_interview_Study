# 4-way handshake에서 TIME_WAIT가 필요한 이유

## 답안

> 가령 `TIME_WAIT`상태가 없을 경우 TCP통신이 완전히 종료하지 못할 수도 있다는 문제점이 있다. 4-way handshake에서 마지막으로 보내는 ACK패킷 모종의 이유로 전송 실패 시 Passive closer는 FIN패킷을 보낼 것이다. 이때 `TIME_WAIT`상태가 없다고 가정한다면  Active closer는 ACK를 보내고 바로 `CLOSED`상태로  전환되므로 재 전송 된 FIN패킷을 받지 못한다. 결국 Passive closer는 계속해서 FIN패킷을 보내게 되므로 TCP통신이 종료되지 않는다. 
또한 Passive closer가 FIN패킷을 보내기 전에 보낸 패킷이 모종의 이유로 지연되어 FIN패킷 도착 이후에 도착하게 되었을 때 FIN패킷을 받은 Active closer는 ACK를 보내고 바로 `CLOSED`상태이므로 이후에 도착한 패킷이 유실된다는 문제점도 있다
> 

---

## 자료 조사

- 4-way handshake
    
    > TCP에서 신뢰성 있게 연결을 해제할 때(세션 종료 시)  필요한 프로세스
    > 
- 용어 정리
    - Active closer : 연결을 먼저 끊으려 하는 쪽(주로 Client)
    - Passive closer : Active closer의 통신 대상(주로 Server)
    - ACK : 응답 플래그
    - FIN : 연결 종료 플래그
- 4-way handshake Process
    
    ![https://blog.kakaocdn.net/dn/qUXSw/btqDWsFNWJw/hVdKIneSYb7UK3wc0pj6Z0/img.png](https://blog.kakaocdn.net/dn/qUXSw/btqDWsFNWJw/hVdKIneSYb7UK3wc0pj6Z0/img.png)
    
    1. [Active closer] :  Active closer가 통신을 끝내기 위해 FIN플래그가 담긴 패킷을 보내고 그에 대한 응답을 기다린다(`FIN_WAIT1` 상태로 전환)
    2. [Passive closer] : FIN패킷을 받은 Passive closer는 받은 FIN패킷에 대해 ACK패킷을 보내고, 응용프로그램에게 종료 신호를 보낸다(`CLOSE_WAIT` 상태로 전환)
        - ACK패킷을 받은 [Active closer] 는 `FIN_WAIT2` 상태로 전환
    3. [Passive closer] : 응용프로그램이 종료 준비가 되면 FIN패킷을 보냄( `LAST_ACK`상태로 전환)
    4. [Active closer] : (3)번 단계에서 보낸 FIN패킷에 대해 ACK를 보냄(`TIME_WAIT` 상태로 전환)
        - (4)번 단계의 ACK 받은 [Passive closer]는 통신을 종료함(`CLOSED` 상태로 전환)
        - `TIME_WAIT` 에서 일정 시간(MSL(Maximum segment lifetime)의 두 배)을 기다리고 통신을 종료함(`CLOSED` 상태로 전환)
- `TIME_WAIT`상태가 존재하는 이유
    
    전재 조건 : `TIME_WAIT`가 없고 [Active closer]가 마지막 ACK를 보낸 후  `CLOSED` 로 상태가 전환된다고 가정
    
    1. 모종의 이유로 [Active closer]보낸 마지막 ACK가 전송에 실패할 경우 [Passive closer]는 ACK패킷이 오지 않아 다시 FIN패킷을 보내게 된다. 그런데 [Active closer]가 이미 `CLOSED` 상태이므로  FIN패킷을 받을 수 없다. 이로 인해 [Passive closer]는 계속해서 FIN패킷을 보내야 하므로 통신을 종료할 수 없기 때문이다.
    2. [Passive closer]가 FIN패킷 전송 전에 보낸 패킷이 모종의 이유로 지연 되어 FIN패킷 이후에 도착할 경우 [Active closer]가 이미 `CLOSED` 상태이므로 패킷이 유실될 수도 있음

---

## 꼬리 질문

- 4-way handshake Process의 (1)번 단계에서 전송되는 FIN패킷에 ACK가 포함되어 있는 이유
    - Half-Close 기법을 사용하기 때문
    - Half-Close : 연결을 종료 시 완전히 종료하지 않고 반만 종료.
    - Half-Close 기법을 사용하면 Active closer가 처음 보내는 FIN 패킷에 승인 번호를 함께 담아서 보내게 되는데, 이때 승인 번호의 의미는 **"**일단 연결은 종료할건데 귀는 열어둘게. 이 승인 번호까지 처리했으니까 더 보낼 거 있으면 보내" 가 된다.
- Client만 TIME_WAIT를 가지는가?
    
    TIME_WAIT는 연결을 능동적으로 종료하려는 쪽이 가지게 됨. 즉 Server도 TIME_WAIT를 가질 수 있음
    

## Ref

[TCP 4-way handshake 란?](https://haruhiism.tistory.com/20)

[TCP 통신과 3-way,4-way handshake 그리고 time_wait 소켓의 개념](https://sooolog.dev/TCP-%ED%86%B5%EC%8B%A0%EA%B3%BC-3-way,4-way-handshake-%EA%B7%B8%EB%A6%AC%EA%B3%A0-time_wait-%EC%86%8C%EC%BC%93%EC%9D%98-%EA%B0%9C%EB%85%90/)

[[TCP] 4-way Handshake란? / 와이어샤크, tcpdump 확인](https://sh-safer.tistory.com/146)

[[네트워크] TCP 3-way & 4-way handshake란?](https://seongonion.tistory.com/74)

[TCP와 3-Way, 4-Way Handshake란? (개념/ 동작 방식)](https://jeongkyun-it.tistory.com/180)

[CLOSE_WAIT & TIME_WAIT 최종 분석](https://tech.kakao.com/2016/04/21/closewait-timewait/)