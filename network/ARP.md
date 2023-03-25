# ARP(Address Resolution Protocol)

### 2. ARP에 대해 설명해보세요

> 소프트웨어적으로 할당된 논리 주소인 `IP 주소`(L3, 네트워크 계층)를 실제적인 물리 주소인 `MAC 주소`(Media Access Control /L2, 데이터링크 계층)로 바꾸어주는 역할을 하는 주소 해석 프로토콜 입니다.
> 
- ARP(Address Resolution Protocol)
    
    같은 네트워크 대역에서 통신을 하기 위해 필요한 MAC주소를 IP주소를 이용해서 알아오는 프로토콜
    
    같은 네트워크 대역에서 통신을 한다고 하더라도 데이터를 보내기 위해서는 7계층부터 캡슐화를 통해 데이터를 보내기 때문에 IP주소와 MAC주소 모두 필요하다. → L2와 L3 사이에서 동작
    
    이때, IP주소는 알고 MAC 주소는 모르더라도 ARP를 통해 통신이 가능
    
    즉, IP주소를 이용해 MAC주소를 알아온다.
    
    - RARP(Reverse Address Resolution Protocol)
        
        해당 MAC 주소에 맞는 IP값을 알아오는 프로토콜
        
- ARP을 활용하여 IP주소에 대응하는 이유는?
    
    ![why_use_ARP](https://user-images.githubusercontent.com/88701965/227702126-23bf85e8-582b-4ff2-93b7-51901ef792db.png)
    
    - IP주소
        
        인터넷에 연결되어 있는 호스트나 라우터 장비의 인터페이스에 할당된 주소.
        
    
    즉, PC에 할당된 주소가 아니라 네트워크에 할당된 주소이다. 그러므로 IP를 활용하여 메시지를 보내고자 하는 PC의 네트워크까지만 접근할 수 있다.
    
    위의 그림처럼 우체국이 A빌딩에 가서 누구에게 편지를 전달해야 하는지 모르는 경우가 되는 것. 그렇기에 ARP프로토콜을 활용하여 MAC 주소를 알아내서 정확한 위치를 찾아내야 함.
    
- ARP 동작 과정
    1. 송신자는 목적지 IP Address를 지정해 패킷을 송신
    2. IP 프로토콜이 ARP 프로토콜에게 ARP Request 메시지를 생성하도록 요청
    3. 메시지는 데이터링크 계층으로 전달되고 이더넷 프레임으로 Encapsulation됨
    4. 모든 호스트와 라우터는 프레임을 수신 후 자신의 ARP 프로토콜에게 전달
    5. 목적지 IP Address가 일치하는 시스템은 자신의 물리주소를 포함하고 있는 ARP Reply 메시지를 보냄
    6. 최초 송신 측은 지정한 IP Address에 대응하는 물리 주소 획득

- 참고자료
    
    [[Network] ARP(주소 결정 프로토콜)에 대하여](https://coding-factory.tistory.com/720)