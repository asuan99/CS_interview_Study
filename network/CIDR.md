# CIDR(Classless Inter-Domain Routing)가 무엇인가요.

- 자료조사
    
    ### 과거: Classful Addressing
    
    ![classful addressing.png](CIDR(Classless%20Inter-Domain%20Routing)%E1%84%80%E1%85%A1%20%E1%84%86%E1%85%AE%E1%84%8B%E1%85%A5%E1%86%BA%E1%84%8B%E1%85%B5%E1%86%AB%E1%84%80%E1%85%A1%E1%84%8B%20a308845ff4314805b8c434795d59f1de/classful_addressing.png)
    
    과거 사용하였던 Classful Addressing 방법이다. Network Address 부분과 Host Address 부분을 나누는 방식을 Class별로 나누어 IP 주소를 할당하였다.
    
    Q. Classful Addressing의 문제점은 무엇이었을까?
    
    A. 힘 있는 기관이 host를 많이 수용할 수 있는 Class를 독점한다. 필요한 만큼 host 가져가면 더 효율적인텐데, 굳이 저렇게 나눠야 하나 싶다.
    
    ### 현재: Classless Addressing(CIDR)
    
    CIDR(Classless Inter-Domain Routing, 사이더)는 클래스 없는 도메인 간 라우팅 기법으로 IP 주소 할당 방법이다.
    
    ![옥텟.png](CIDR(Classless%20Inter-Domain%20Routing)%E1%84%80%E1%85%A1%20%E1%84%86%E1%85%AE%E1%84%8B%E1%85%A5%E1%86%BA%E1%84%8B%E1%85%B5%E1%86%AB%E1%84%80%E1%85%A1%E1%84%8B%20a308845ff4314805b8c434795d59f1de/%25EC%2598%25A5%25ED%2585%259F.png)
    
    IP를 표현하는 방식이다. 현재 사용하고 있는 IPv4 체계에서, 4개의 8bit 옥텟을 사용하여 IP를 표현한다. 각 옥텟은 2의 8승 = 256가지의 정보를 가질 수 있다. (0.0.0.0~255.255.255.255)
    
    ![subnet mask 24 example.jpg](CIDR(Classless%20Inter-Domain%20Routing)%E1%84%80%E1%85%A1%20%E1%84%86%E1%85%AE%E1%84%8B%E1%85%A5%E1%86%BA%E1%84%8B%E1%85%B5%E1%86%AB%E1%84%80%E1%85%A1%E1%84%8B%20a308845ff4314805b8c434795d59f1de/subnet_mask_24_example.jpg)
    
    CIDR는 subnet mask 값을 통해 host addressing 범위를 지정한다.
    
    subnet mask가 24인 경우, IP 주소의 왼쪽부터 24번째 이후부터 host addressing이 가능하다. 그림에서 223.1.1.0/24의 경우를 보면, 223.1.1.0 ~ 223.1.1.255 범위의 IP를 자신의 도메인 내에서 자유롭게 할당이 가능하다.
    
- 답안
    
    CIDR은 Network Address와 Host Address를 구분하기 위해 서브넷 마스크를 사용합니다. 이전 Classful Addressing 방법에 비하여 더욱 유연한 네트워크 크기를 제공하기 때문에 IP 주소 공간을 더 효율적으로 사용할 수 있습니다.
    
- Reference
    
    컴퓨터 네트워크 및 실습 강의 자료 (박영덕 교수님)
    
    [[네트워크] CIDR이란?(사이더 란?)](https://kim-dragon.tistory.com/9)