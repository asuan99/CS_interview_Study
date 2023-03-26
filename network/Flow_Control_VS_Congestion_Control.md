# Flow Control과 Congestion Control의 차이를 설명해보세요.

---

- 자료조사
    
    ## Flow Control이란?
    
    수신자가 패킷을 처리하는 속도에 비하여 송신자가 패킷을 보내는 속도가 빠를 경우, 수신자가 수용할 수 있는 버퍼에 오버플로우가 발생하여 패킷이 손실된다. 패킷이 손실될 경우, 패킷을 재전송해야하므로 네트워크가 혼잡해질 우려가 있다.
    
    Flow Control은 송신자가 수신자에게 너무 많은 데이터를 너무 빠르게 보내는 것을 방지하여 버퍼 오버플로우를 막음으로써 패킷 손실 및 네트워크 성능 저하를 방지한다.
    
    ![TCP 패킷 구조.png](Flow%20Control%E1%84%80%E1%85%AA%20Congestion%20Control%E1%84%8B%E1%85%B4%20%E1%84%8E%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%85%E1%85%B3%E1%86%AF%20%E1%84%89%E1%85%A5%E1%86%AF%E1%84%86%E1%85%A7%E1%86%BC%20695e9ee5dc214bfd8df2bfeb13d1cfbd/TCP_%25ED%258C%25A8%25ED%2582%25B7_%25EA%25B5%25AC%25EC%25A1%25B0.png)
    
    Transport layer에서 다루는 TCP 패킷의 구조이다. (상위 5줄이 TCP 헤더)
    
    - 수신자는 TCP 헤더에 있는 ‘Window Size(RWND)’ 공간에 수용할 수 있는 버퍼 크기를 적어 송신자에게 알려준다.
    - 송신자는 수신자가 수용할 수 있는 만큼의 데이터를 전송한다.
    
    ```
    Q. 수신자의 버퍼가 가득 찼을 경우, 송신자는 데이터 전송을 멈춘다. 송신자는 언제 데이터 전송을 재개할 수 있을까?
    
    1. 수신자가 송신자에게 데이터를 보낼 때, 송신자는 수신자의 헤더를 확인하여 버퍼 크기를 확인 할 수 있다. **그러나, 송신자는 수신자가 데이터를 보낼 때까지 대기하여야 한다. 수신자가 데이터를 보낼 일이 없다면 송신자는 수신자의 버퍼에 공간이 생겼는지 알 수 없다.**
    2. 송신자가 주기적으로 1 byte 짜리 probe segment를 전송한다. 만일 수신자의 버퍼에 공간이 생겼다면, 수신자는 해당 probe segment를 처리하여 송신자에게 응답 메시지를 보낼 것이다. 이때 송신자는 헤더에 담겨있는 수신자의 버퍼 크기를 확인할 수 있다.
    ```
    
    ```
    Q. 송신자가 수신자에게 처음으로 패킷을 전송하려고 할 때, 수신자의 버퍼 크기에 대한 정보가 없다. 어떻게 확인할 수 있을까?   
    
    통신 시작 전, 3-handshaking을 하는 과정에서 수신자의 버퍼 크기 정보를 교환한다.
    ```
    
    ## Congestion Control이란?
    
    네트워크가 혼잡할 경우, 네트워크로 패킷을 보낼 경우 패킷이 손실될 수 있으며 네트워크를 더 악화시킬 수 있다. 따라서, 네트워크가 혼잡할 경우 송신자 측에서 패킷을 내보내는 양을 조절해야 한다. 이것이 바로 Congestion Control이다.
    
    ![congestion control.png](Flow%20Control%E1%84%80%E1%85%AA%20Congestion%20Control%E1%84%8B%E1%85%B4%20%E1%84%8E%E1%85%A1%E1%84%8B%E1%85%B5%E1%84%85%E1%85%B3%E1%86%AF%20%E1%84%89%E1%85%A5%E1%86%AF%E1%84%86%E1%85%A7%E1%86%BC%20695e9ee5dc214bfd8df2bfeb13d1cfbd/congestion_control.png)
    
    - 송신자가 네트워크 상에 패킷을 보내는 Window Size(CWND)는 초기에 1MSS이다.
    - Slow Start: cwnd 크기를 2배씩 증가시킨다. 네트워크 상에 보내는 패킷의 양을 확 늘린다.
    - Congestion Avoidance: cwnd 크기가 정해놓은 thresh에 도달하면 cwnd 크기를 1씩 증가시킨다. 네크워크 상에 보내는 패킷의 양을 찔끔 늘린다.
    - 패킷 손실이 발생하였다고 판단하였을 때, thresh를 현재 cwnd 크기의 절반으로 설정하고 cwnd도 줄인 뒤 다시 반복한다.
    
    ```
    Q. 패킷 손실이 발생하였다고 판단하는 근거는 무엇인가?    

    1. Triple duplicated ACK
    2. Time out

    Time out이 발생하였다는 것은 응답조차 받을 수 없을 정도로 네트워크가 혼잡하다는 의미이므로 더 심각한 상황이다. 그림처럼 비교적 덜 심각한 Triple duplicated ACK인 경우 Congestion Avoidance 단계부터 시작하도록 cwnd 크기를 thresh만큼 줄이고, 비교적 더 심각한 Time out인 경우 cwnd 크기를 1만큼 줄이는 방식을 택할 수 있다.
    ```
    
    ```
    Q. dulicated ACK이 발생하는 이유
    
    수신 측은 자신이 정상적으로 처리한 데이터에 대해서만 ACK를 보내기 때문에 송신 측이 보낸 세그먼트 순서가 잘못되었거나, 아에 손실되었을 경우 중복된 ACK을 보내게 된다. 동일한 승인 번호를 세 번이나 받은 상황은 어떤 이유로 인해 수신 측이 특정 시퀀스 번호 이후의 데이터를 제대로 처리하지 못한 상황이라고 볼 수 있다.
    ```
    
- 답안
    
    Flow Control과 Congestion Control은 모두 데이터의 흐름을 조절함으로써 버퍼 오버플로, 패킷 손실 및 네트워크 혼잡 등이 발생하는 것을 방지하여 네트워크 성능과 신뢰성을 유지합니다. 차이점은 Flow Control은 수신자가 송신자로부터 받는 트래픽 속도를 제어하는 것이고, Congestion  Control은 송신자가 네트워크로 보내는 트래픽 속도를 제어하는 것입니다.
    
- Reference
    
    컴퓨터 네트워크 및 실습 강의 자료 (박영덕 교수님)
    
    [Difference between Flow Control and Congestion Control - GeeksforGeeks](https://www.geeksforgeeks.org/difference-between-flow-control-and-congestion-control/)
    
    [[정리] TCP의 기능과 패킷 구조 - 1](https://mr-zero.tistory.com/36)
    
    [TCP flow control](https://velog.io/@zigje9/TCP-flow-control)
    
    [사이 좋게 네트워크를 나눠 쓰는 방법, TCP의 혼잡 제어](https://evan-moon.github.io/2019/11/26/tcp-congestion-control/)
