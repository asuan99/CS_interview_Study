# DHCP 요청에서 UDP를 사용하는 이유에 대해서 설명해주세요.

- **자료 조사**
    
    **동적 호스트 구성 프로토콜**(DHCP)는 호스트의 IP주소와 각종 TCP/IP 프로토콜의 기본 설정을 클라이언트에게 자동적으로 제공해주는 프로토콜을 말합니다. DHCP는 네트워크에 사용되는 IP주소를 DHCP서버가 중앙집중식으로 관리하는 클라이언트/서버 모델을 사용하게 됩니다. DHCP지원 클라이언트는 네트워크 부팅과정에서 DHCP서버에 IP주소를 요청하고 이를 얻을 수 있습니다.
    
    - **DHCP Client-Server Scenario**
        
        ![DHCP 시나리오](https://github.com/BangDori/CS_interview_Study/blob/main/network/img/DHCPScenario-%EA%B0%95%EB%B3%91%EC%A4%80.png)
        
        
        1. DHCP discover (Client → Server)
            - Client는 DHCP가 있는지 Broadcast로 네트워크에 연결된 모든 호스트에게 전송해 확인합니다.
        2. DHCP offer (Server → Client)
            - DHCP가 존재하며 사용할 수 있는 IP가 있다고, Broadcast로 전달합니다.
            - **BroadCast로 클라이언트들에게 전달하는 이유?**
                
                서버로부터 요청 받은 클라이언트가 제공 받은 IP 주소를 사용할 수도 있기 때문에, 서버는 브로드캐스트로 모든 클라이언트에게 현재 클라이언트가 서버에서 제공한 IP주소를 사용할 수도 있다는 것에 대해 알리기 위함
                
        3. DHCP request (Client → Server)
            - offer을 확인한 후, 서버에 연결을 요청
        4. DHCP ACK (Server → Client)
            - IP 주소가 할당 되었다는 확인 메시지를 클라이언트에게 전달
        
        만약, 클라이언트가 이전에 할당된 네트워크 주소를 기억하고 재사용한다면, discover과 offer 단계는 생략될 수 있습니다.
        
    - **DHCP지원 클라이언트 (부가 설명)**
        
        DHCP 지원 클라이언트는 네트워크에서 IP 주소와 같은 구성 정보를 동적으로 할당받을 수 있는 클라이언트입니다. 이 클라이언트는 네트워크 시작 시 DHCP 서버에 요청을 보내고, DHCP 서버는 해당 클라이언트에 대해 유효한 IP 주소, 서브넷 마스크, 기본 게이트웨이, DNS 서버 등과 같은 네트워크 구성 정보를 동적으로 할당합니다. 이후 클라이언트는 할당받은 IP 주소를 사용하여 네트워크에 연결할 수 있습니다. 대부분의 네트워크기기는 DHCP 클라이언트로서 작동할 수 있습니다.
        
        - **DNS(Domain Name System)**
            
            > 도메인 이름 시스템(DNS)은 사람이 읽을 수 있는 도메인 이름(예: www.amazon.com)을 컴퓨터, 머신이 읽을 수 있는 IP 주소(예: 192.0.2.44)로 변환하는 시스템입니다.
            > 
    - **TCP(Transmission Control Protocol)**
        
        TCP에서는 송신자가 데이터를 수신자에게 전송했을 경우, 항상 수신자가 데이터를 제대로 수신했는지 확인해야 합니다. 또한 여기에서 에러가 발생하지는 않았는지, 그리고 수신자의 수신 속도에 비해 송신하는 데이터의 전송 속도가 너무 빠르지는 않는지, 네트워크가 혼잡하지는 않는지 확인을 합니다. 이러한 서비스를 제공하기 때문에 TCP는 높은 신뢰성을 보장 할 수 있습니다.
        
        하지만, TCP 프로토콜의 처리 방식은 높은 오버헤드를 가질 수 있습니다. 전송하는 데이터의 헤더 사이즈도 커질 뿐만 아니라, 만약 전송이 되지 않았다면 패킷을 재전송해야 하는 추가적인 동작이 필요합니다.
        
        **특징**
        
        1. 연결형 프로토콜
        2. 순차적인 데이터 전송
        3. Flow Control, Congestion Control
    - **UDP(User Datagram Protocol)**
        
        UDP 통신 프로토콜은 신뢰성을 보장하지는 않지만 TCP 비하여 빠른 전송 속도를 제공합니다. UDP는 비연결을 지향하기 때문에 데이터를 재전송할 필요가 없고, 흐름 제어나 에러 체크도 항상 필요로 하지 않습니다. 그로 인해 전송에 필요한 헤더 사이즈가 줄어들게 되어 결과적으로 데이터 송/수신 과정이 매우 빨라집니다. 이러한 이유들 때문에 신뢰성 보장보다는 연속성과 성능이 중요시되는 서비스에서는 UDP가 사용됩니다.
        
        **특징**
        
        1. 비연결형 프로토콜
        2. 독립적인 데이터 전송
        3. Flow Control, Congestion Control X
- **답안**
    
    UDP는 비연결형 프로토콜로, TCP와 달리 세션을 설정하거나 연결을 유지할 필요가 없어 클라이언트는 더욱 간단하게 DHCP 서버와 통신할 수 있으며, DHCP 서버도 더 높은 성능과 효율성을 얻을 수 있습니다.
    
    또한, UDP는 TCP보다 헤더 크기가 작고, 신뢰성과 흐름 제어 등의 기능이 없기 때문에 데이터 전송에 대한 부가적인 오버헤드가 적습니다. 이로 인해 DHCP 클라이언트와 서버 간의 대화가 빠르고 경량화되며, 더 많은 클라이언트를 동시에 처리할 수 있습니다.
    
    따라서, 이러한 이유로 DHCP 요청에서는 UDP 프로토콜을 사용하고 있습니다.
    
- **참고 자료**
    1. 네트워크 - (박영덕 교수님)
    2. DHCP - Microsoft Learn ([url](https://learn.microsoft.com/ko-kr/windows-server/networking/technologies/dhcp/dhcp-top))
    3. DHCP란? - 개발자를 꿈꾸는 프로그래머 ([url](https://jwprogramming.tistory.com/35))
    4. DNS란 무엇인가요? - aws ([url](https://aws.amazon.com/ko/route53/what-is-dns/))
