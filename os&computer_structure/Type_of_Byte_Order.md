# Byte Order

# Byte Order와 방식에 대하여 설명해주세요

- Byte Order(바이트오더)
    - 컴퓨터 메모리에 바이트가 저장되는 순서
    - 시스템마다 내부적으로 1바이트 이상의 데이터를 처리하는 방식, 바이트 오더가 다르기 때문에 서로 다른값으로 인식할 수 있음
    - 인텔 계열의 80x86: 리틀엔디안
    - Power PC, ARM: 빅엔디안
- MSB와 LSB
    
    ![MSB_and_LSB](Byte%20Order%20d44a119096b5498ea018ff8c62a1ea37/Untitled.png)
    
    - 데이터를 Bit 단위로 놓고 봤을 때 사용되는 용어
    - 99를 2진수로 변환하면 01100011 여기서 가장 왼쪽의 비트를 MSB 가장 오른쪽의 비트를 LSB
    - MSB(Most Significant Bit)
        - 가장 큰 자릿수의 비트, 즉 가장 왼쪽 비트
    - LSB(Least Significant Bit)
        - 가장 작은 자릿수의 비트, 즉 가장 오른쪽 비트
        
- Big-endian(빅엔디안)
    
    ![Big_Endian](Byte%20Order%20d44a119096b5498ea018ff8c62a1ea37/Untitled%201.png)
    
    - 낮은 주소에 데이터의 높은 바이트부터 저장하는 방식
    - 네트워크에서 데이터를 전송할 때 주로 사용됨
    - 평소에 숫자나 문자를 읽는 방식과 같은 선형 방식. 메모리에 저장된 순서 그대로 읽을 수 있기 때문에 이해하기 쉬움
    
    ![Big_Endian_Example](Byte%20Order%20d44a119096b5498ea018ff8c62a1ea37/Untitled%202.png)
    
- Little-endian(리틀엔디안)
    
    ![Little_Endian](Byte%20Order%20d44a119096b5498ea018ff8c62a1ea37/Untitled%203.png)
    
    - 낮은 주소에 데이터의 낮은 바이트부터 저장하는 방식
    - 마이크로프로세서에서 주로 사용됨
    - 빅 엔디안 방식과는 반대로 거꾸로 읽는 방식, 대부분의 인텔 CPU 계열에서는 이러한 방식 사용
    
    ![Little_Endian_Example](Byte%20Order%20d44a119096b5498ea018ff8c62a1ea37/Untitled%204.png)
    
- 답안
    
    ![Big_Endian_and_Little_Endian](Byte%20Order%20d44a119096b5498ea018ff8c62a1ea37/Untitled%205.png)
    
    - 바이트 오더란 데이터가 저장되는 순서를 의미한다. 바이트 오더의 방식에는 빅엔디안과 리틀엔디안이 있으며 빅엔디안은 주로 네트워크에서 사용되며 낮은 주소에 데이터의 높은 바이트부터 저장하는 방식이고, 리틀엔디안은 주로 마이크로프로세서에서 사용되며 낮은 주소에 데이터의 낮은 바이트부터 저장하는 방식이다.
- 참고자료
    
    [[기술면접] CS 기술면접 질문 - 운영체제 (5/8)](https://mangkyu.tistory.com/92)
    
    [[OS] Byte Order(바이트 오더) - 빅 엔디안(Big endian), 리틀 엔디안(Little endian)](https://cocoon1787.tistory.com/770)
    
    [바이트순서(byte order) 그리고 빅엔디안(Big-endian)과 리틀엔디안(Little-endian)](https://6kkki.tistory.com/20)
    
    [](https://www.hackerschool.org/Sub_Html/HS_University/HardwareHacking/24.html)