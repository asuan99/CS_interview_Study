# 공인 IP, 사설 IP

# ****공인(public) IP와 사설(private) IP의 차이에 대해 설명해주세요.****

- IP
    
    ![IP](https://github.com/WooJJam/CS_interview_Study/blob/main/network/img/IP.png)
    
    - IP(Internet Protocol) 란 인터넷에 연결되어 있는 모든 장치들을 식별할 수 있도록 각각의 장비에 부여되는 고유 주소
    - IP 주소의 종류
        - IPv4 (구)
            - IP version 4의 약자로 전 세계적으로 사용된 첫 번째 인터넷 프로토콜
            - IPv4는 약 43억개의 주소를 가질 수 있지만, 인터넷 사용자 수가 급증하면서 주소가 고갈될 위기에 처함
        - IPv6 (신)
            - IP version 6의 약자로, IPV4의 주소체계를 128비트 크기로 확장한 차세대 인터넷 프로토콜 주소
            - 네트워크 속도, 보안적인 측면에서 뛰어나지만, 비용이 많이 들어 아직 상용화는 되지 않음
- 공인 IP
    - ICANN이라는 기관이 국가별로 사용할 IP 대역을 관리하고 우리나라는 KISA에서 국내 IP 주소들을 관리
    - ISP를 부여받고, 통신사 가입을 통해 IP를 제공받아 인터넷을 사용하게 되는데 이것이 공인 IP
- 사설 IP
    - 공유기를 사용한 인터넷 접속 환경일 경우 공유기까지는 공인 IP 할당
    - 공유기에 연결되어 있는 가정이나 회사의 각 네트워크 기기에는 사설 IP를 할당
    - 즉, 사설 IP는 어떤 네트워크에서만 내부적으로 사용되는 고유한 주소, 로컬 IP라고도 불림
    - 공인 IP는 전 세계에서 유일하지만, 사설 IP는 하나의 네트워크에서만 유일
- 답안
    - 공인 IP는 ISP가 제공하는 IP 주소이며, 외부에도 공개되어 있는 IP주소이고 사설 IP는 일반 가정이나 회사 내 등에 할당된 네트워크 IP 주소이며, IPv4의 주소 부족으로 인해 서브넷팅된 ip이므로 라우터에 의해 로컬 네트워크상의 PC나 장치에 할당된다.
- 참고자료
    
    [신입 개발자 기술면접 질문 정리 - 네트워크](https://dev-coco.tistory.com/161)
    
    [[NW] 🌐 IP 기초 (사설IP / 공인IP / NAT) 개념 정말 쉽게 정리](https://inpa.tistory.com/entry/WEB-🌐-IP-기초-사설IP-공인IP-NAT-개념-정말-쉽게-정리)
