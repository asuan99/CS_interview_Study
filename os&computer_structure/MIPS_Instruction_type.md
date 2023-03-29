# MIPS 명령어 타입

### 2. MIPS 명령어는 어떤 형식으로 구성되어 있으며, 각 명령어의 핵심 필드에 대해 설명해주세요.

> MIPS 명령어는 크게 R 타입, I 타입, J 타입으로 분류됩니다.
R타입은 주로 연산 명령어, I타입은 load/store, J타입은 jump 명령어로 사용됩니다.
각각의 필드는 명령어의 기능을 결정하는 데 중요한 역할을 합니다. 예를 들어, R 타입 명령어에서 Function code 필드는 연산의 종류를 추가적으로 구분하는 데 사용됩니다. 또한, I 타입 명령어에서 Immediate 필드는 연산에 사용될 상수 값을 지정하는 데 사용됩니다. 이러한 필드의 조합에 따라서 MIPS 아키텍처에서 사용되는 다양한 명령어들이 구성됩니다.
> 

- MIPS
    - 전형적인 RISC ISA
    - MIPS는 고정된 길이(32bits)와 형식(R/I/J)를 갖는다
        
        32bits 기준으로 0~31까지 32개의 레지스터가 존재한다.
        
    - 모든 명령어들에 대해 3개의 operands(피연산자)를 가진다.
    - MIPS 명령어는 **register-register arithmetic instruction**이다.
        
        즉, 메모리에 액세스하기 위해서는 무조건 register로 데이터를 가져온다.
        
        연산 후에는 결과를 메모리에 저장하는 구조로 동작한다.
        
    - **load/store machine**이라고 불리기도 한다.
        
        모든 작업을 메모리로부터 load → 연산 → 메모리에 store하는 구조로 동작하기 때문
        
    - ISA(Instruction set architecture)
        - 명령어 집합 구조
        - 마이크로프로세서가 인식해서 기능을 이해하고 실행할 수 있는 기계어 명령어
    
- MIPS 명령어
    
    ![MIPS_Instruction_type](https://user-images.githubusercontent.com/88701965/228523543-f0eb58bd-d3e8-4e1b-a515-8c6f70ec3195.png)
    
    - R 타입 - Computational(계산) 모델
        
        R 타입 명령어는 레지스터를 대상으로 하는 연산을 수행하는 명령어
        
        | opcode(6) | rs(5) | rt(5) | rd(5) | shamt(5) | funct(6) |
        
        - Opcode(6 bits): 연산의 종류를 나타내는 필드입니다.
        - Rs(5 bits): 첫 번째 소스 레지스터를 나타내는 필드
        - Rt(5 bits): 두 번째 소스 레지스터를 나타내는 필드
        - Rd(5 bits): 결과를 저장할 대상 레지스터를 나타내는 필드
        - Shift(5 bits): 시프트 연산 시 사용할 비트 수를 나타내는 필드
        - **Function code(6 bits): 연산의 종류를 추가적으로 구분하는 필드**
    - I 타입 - Load/Store 모델
        
        I 타입 명령어는 상수를 대상으로 대부분 데이터 전송과 분기 명령어
        
        | opcode(6) | rs(5) | rt(5) | immediate(16) |
        
        - Opcode(6 bits): 연산의 종류를 나타내는 필드
        - Rs(5 bits): 첫 번째 소스 레지스터를 나타내는 필드
        - Rt(5 bits): 대상 레지스터를 나타내는 필드
        - **Immediate(16 bits): 연산에 사용될 상수 값을 나타내는 필드**
    - J 타입 - Jump and Branch 모델(명령어의 실행 흐름을 바꾸는 것)
        
        J 타입 명령어는 대부분 점프 명령어로
        
        | opcode(6) |      jump(26)     |
        
        - Opcode(6 bits): 연산의 종류를 나타내는 필드
        - **Address(26 bits): 점프할 메모리 주소를 나타내는 필드**
- 참고자료
    
    [[컴퓨터구조] MIPS](https://velog.io/@apphia39/컴퓨터구조-MIPS)
    
    컴퓨터구조 - 곽종욱 교수님 수업