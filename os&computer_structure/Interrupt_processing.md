# 5주차(운영체제/컴퓨터구조)

# 1. Interrupt의 처리과정을 설명하시오.

### Interrupts의 공통적 기능

Interrupt : 디바이스에서 발생하는 모든 동작

- 인터럽트 전송은 모든 서비스의 주소를 포함한 Interrupt vector라는 것을 통해 ISR(interrupt service routine)을 제어한다.
- Interrupt architecture는 인터럽트된 명령어의 주소를 저장한다.
- 인터럽트가 처리되는 동안 들어오는 **다른 인터럽트들은 비활성화**된다.
    
    (ISR 처리시 다른 interrupt 비활성화→동시에 처리할 수 없기 때문에)
    
- 트랩은 오류 또는 사용자의 요구에 의해 발생하는 소프트웨어 생성 인터
럽트이다.
    
    (trap : 소프트웨어에 의해 OS에 인터럽트 요청을 보내는 것)
    
    - 인터럽트는 하드웨어에 의해 생성된다.
    - 예외처리와 비슷하다.
    - Divide by zero, segmentation/page fault, system call 등
- 운영체제는 인터럽트를 구동시킨다.

### Interrupt 비교

### Interrupt

외부 인터럽트 - CPU 밖에 있으면 외부

- 비동기적
- 외부 하드웨어 장치에 의해 생성된다.

내부 인터럽트

- 내부 인터럽트는 아래와 같이 나눠진다.
    - Fault
        
        현재 명령어를 저장한다→ISR→오류상태로 돌아간다.
        
        ex) page fault, memory space fault
        
    - Trap
        
        현재 명령어를 저장한다→ISR→다음 명령어를 실행한다.
        
        ex) system call, exception handling
        
    - Abort
        
        ISR→현재 작업이 불가능하므로 현재 작업을 중단한다.
        
        ex) divide by zero
        

### Interrupt 처리

OS는 CPU의 상태를 레지스터와 프로그램 카운터를 저장함(context switching)으로써 CPU의 상태를 보존한다.

발생하는 인터럽트의 종류 : 

- Vectored Interrupt system
- Polling system - 문맥 교환을 하지 않고 끝날 때까지 기다린다.
    - 핸드쉐이킹을 통해 장치의 상태를 결정한다 - busy waiting
    - 장점: 빠른 반응 속도, context switching(작업을 다른 곳에 맡아두고 다른 작업 실행) overhead가 없다.
        - 단점: CPU cycle의 낭비
    - 요구사항
        - **빠른 I/O 장치**
        - **짧은 I/O 서비스 루틴**
        - **드물게 일어나야 한다.**

낭비된 코드 세그먼트는 각 인터럽트 종류에 따라 취해진 행동을 결정한다. → Interrupt Service (Handling) Routine

![Interrupt_processing](https://github.com/Tentennball/CS_interview_Study/blob/main/os&computer_structure/img/Interrupt_processing.png?raw=true)

### 답변

Interrupt가 발생하면 OS가 IVT(interrupt vector table)로 이동 시키고 IVT에서 인터럽트의 종류를 찾아서 ISR(interrupt service routine)을 통해 인터럽트를 처리하고 fault, trap, abort에 따라 다음 명령어를 실행한다.

### ref

곽종욱 교수님 강의자료
