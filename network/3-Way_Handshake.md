# 3-way handshake의 Process

## 답안

> Client(Active Opener)가 Server(Passive Opener)에게 연결 요청을 하기 위해 SYN플래그가 담긴 패킷을 보내게 되고, `SYN_SENT`상태가 된다. Server가 `LISTEN`상태라면 Client가 보낸 SYN패킷에 대해 ACK와 SYN플래그가 담긴 패킷을 보내게 되고, `SYN_RECV`상태가 된다. Server가 보낸 ACK와 SYN이 담긴 패킷을 받은 Client는 그에대한 ACK패킷을 보내고 `ESTABLISHED`상태가 되고 Server가 ACK를 받아  `ESTABLISHED`상태가 됨으로써 최종적으로 연결이 설정되게 된다.
> 

---

## 자료 조사

- 3-way handshake
    - TCP/IP 프로토콜을 이용해서 통신을 하는 응용프로그램이 데이터를 전송하기 전에 먼저 정확한 전송을 보장하기 위해 상대방 컴퓨터와 사전에 세션을 수립하는 과정
    - 양쪽 모두 데이터를 전송할 준비가 되었다는 것을 보장하고, 실제로 데이터 전달이 시작하기 전에 한 쪽이 다른 쪽이 준비되었다는 것을 알 수 있도록 한다.
- 용어 정리
    - TCP State
        - CLOSED : 포트가 닫힌 상태
        - LISTEN : 포트가 열린 상태로 연결 요청 대기 중
        - SYN_SENT : SYN 요청을 보내고 ACK패킷을 기다리는 상태
        - SYN_RECV : SYN 요청을 받고 SYN + ACK패킷을 보내고 상대방의 응답을 기다리는 상태
        - ESTABLISHED : 연결이 된 상태
    - Flag
        - SYN : 연결 요청 플래그
        - ACK : 응답 플래그
    - Active Opener : 연결 요청자(Client)
    - Passive Opener : 연결 요청 수신자(Server)
- Process
    
    ![https://evan-moon.github.io/static/39c2c760f38c6bd21705f9e01d1aa41c/21b4d/3way-handshake.png](https://evan-moon.github.io/static/39c2c760f38c6bd21705f9e01d1aa41c/21b4d/3way-handshake.png)
    
    1. [Active Opener] : [Passive Opener]에게 SYN패킷을 보내 통신을 요청함(`CLOSED` →`SYN_SENT`상태로 전환) 
    2.  [Passive Opener] : SYN패킷을 받은 [Passive Opener]는 그에 대한 SYN + ACK패킷을 전송(`LISTEN` → `SYN_RECV` 상태로 전환)
    3. [Active Opener] : SYN + ACK패킷을 받은 [Active Opener]는 이에 대한 ACK패킷을 보냄(`SYN_SENT`  → `ESTABLISHED` 상태로 전환)
        - [Active Opener]의 ACK를 받은 [Passive Opener]도 `SYN_RECV` → `ESTABLISHED` 상태로 전환
            
            ---
            

## 꼬리 질문

---

## Ref

[TCP와 3-Way, 4-Way Handshake란? (개념/ 동작 방식)](https://jeongkyun-it.tistory.com/180)

[TCP 통신과 3-way,4-way handshake 그리고 time_wait 소켓의 개념](https://sooolog.dev/TCP-%ED%86%B5%EC%8B%A0%EA%B3%BC-3-way,4-way-handshake-%EA%B7%B8%EB%A6%AC%EA%B3%A0-time_wait-%EC%86%8C%EC%BC%93%EC%9D%98-%EA%B0%9C%EB%85%90/)

[[네트워크] 3-way / 4-way Handshake 란?](https://bangu4.tistory.com/74)

[[네트워크] 3-Way Handshake](https://velog.io/@mmmetr/3-Way-Handshake)

[[네트워크] TCP/UDP와 3 -Way Handshake & 4 -Way Handshake](https://velog.io/@averycode/%EB%84%A4%ED%8A%B8%EC%9B%8C%ED%81%AC-TCPUDP%EC%99%80-3-Way-Handshake4-Way-Handshake)

[TCP가 연결을 생성하고 종료하는 방법, 핸드쉐이크](https://evan-moon.github.io/2019/11/17/tcp-handshake/)