# CS_Study 네트워크&데이터 통신(3/26)

## ICMP 프로토콜이 무엇이고, 대표적인 예시는 무엇인가요?

- 자료조사
    
    정의 
    
    ICMP(Internet Control Message Protocol)는 TCP/IP 네트워크에서 발생하는 오류 메시지를 전송하기 위한 프로토콜입니다.
    
    메시지 포멧
    
    ![Untitled](CS_Study%20%E1%84%82%E1%85%A6%E1%84%90%E1%85%B3%E1%84%8B%E1%85%AF%E1%84%8F%E1%85%B3&%E1%84%83%E1%85%A6%E1%84%8B%E1%85%B5%E1%84%90%E1%85%A5%20%E1%84%90%E1%85%A9%E1%86%BC%E1%84%89%E1%85%B5%E1%86%AB(3%2026)%200fd793a76add473fa67dc86d93d816ac/ICMP_set.png)
    
    대표적인 Type의 종류
    
    ![Untitled](CS_Study%20%E1%84%82%E1%85%A6%E1%84%90%E1%85%B3%E1%84%8B%E1%85%AF%E1%84%8F%E1%85%B3&%E1%84%83%E1%85%A6%E1%84%8B%E1%85%B5%E1%84%90%E1%85%A5%20%E1%84%90%E1%85%A9%E1%86%BC%E1%84%89%E1%85%B5%E1%86%AB(3%2026)%200fd793a76add473fa67dc86d93d816ac/ICMP_EX.png)
    
    - 예시
        
        **Destination unreachable message(3 : 목적지 도달 불가)**
        
        - 코드 필드엔 데이터그램을 전달 할 수 없었던 이유를 명시한다.
        - ex) 0: 하드웨어 고장, 2: 상위 프로토콜 도달 불가, 4: 단편화 불가 (Don't fragment)
        
        **Source Quench Message (4 : 혼잡으로 인한 데이터 폐기)**
        
        - IP는 흐름제어 기능이 없기 때문에 발신자 쪽에서 데이터를 너무 빨리 보내면 오버플로가 발생할 수도 있고, 이럴 경우 데이터그램을 그냥 폐기
        - ICMP는 이를 발신자에게 통보하여 송신을 억제
        
        **Time Exceeded Message (11 : Timeout or TTL = 0)**
        
        두가지 경우가 있다.
        
        - Code = '0' 인 경우, Time to live필드가 0이 되어 데이터그램이 폐기된 경우
        - Code = '1' 인 경우, 단편이 지정된 시간내에 도착하지 않아 재조립에 실패한 경우
        - TTL와 Timeout의 차이
            
            Timeout 
            
            특정 작업을 수행하는 데 소요되는 시간이 지나면 작업이 실패한 것으로 간주하는 시간입니다.
            
            TTL
            
            네트워크에서 패킷이 유효한 시간을 의미합니다. TTL은 네트워크 패킷의 헤더에 포함되어 있으며, 패킷이 라우팅되는 동안 감소됩니다
            
        
        **Parameter Problem Message (12 : IP 패킷이나 헤더 오류)**
        
        데이터그램의 헤드에 에러가 있거나 부족한 부분이 있을 경우
        
        - Code = '0' 인 경우, 필드 중에 불명료하거나 빠진 것이 있는 경우이다.
        - Code = '1' 인 경우, 옵션의 요구사항이 빠져 있는 경우이다.
        
        **Redirection Message (5 : 경로 재지정)**
        
        - 라우터가 봤을때 자신이 아닌 다른 라우터를 경유 하는게 최종 목적지로 가는데 유리 할 경우 올바른 경로를 알려 준다.
        - ICMP가 전달하는 메세지 중 특별한 경우이다. IP 데이터그램을 폐기시키지 않고 그냥 메세지만 전달한다.
- 답변
    
    TCP/IP 네트워크에서 오류 발생 시 전달되는 오류메시지로, 목적지에 도달이 되지 않았을 때 전달되는 Type 3의 destination unreachable, timeout이 되거 ttl=0이 되었을 때 전달되는 type 4의  time exceed 메세지가 대표적이다.
    
- Reference
    
    [따라하면서 배우는 IT 유튜브](https://www.youtube.com/watch?v=JaBCIUsFE74&t=42s)
    
    [ICMP 위키백과](https://ko.wikipedia.org/wiki/%EC%9D%B8%ED%84%B0%EB%84%B7_%EC%A0%9C%EC%96%B4_%EB%A9%94%EC%8B%9C%EC%A7%80_%ED%94%84%EB%A1%9C%ED%86%A0%EC%BD%9C)