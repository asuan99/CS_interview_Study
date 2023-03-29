# 멀티 프로세스, 멀티 스레드

# 멀티 프로세스와 멀티 스레드의 차이가 무엇인가요?

- 프로세스
    
    ![Process](https://github.com/WooJJam/CS_interview_Study/blob/main/os%26computer_structure/img/Process.png)
    
    - CPU(프로세서)에 의해 실행되는 프로그램
    - 프로그램
        - Application 개발자가 작성한 코드, 실행이 되지 않는다면 그저 데이터의 집합
        - 현대의 모든 컴퓨터들은 폰노이만 구조를 하고 있기 때문에 디스크에 있는 프로그램을 바로 CPU로 전달 불가
        - 메인 메모리에 프로그램을 올리고 메모리에서 코드들을 한줄씩 CPU에 전달하여 실행
        - 메모리에 올라가서 실행 중인 프로그램을 프로세스
    
    ![Process_Structure](https://github.com/WooJJam/CS_interview_Study/blob/main/os%26computer_structure/img/Process_Structure.png)
    
    - Code(Text) 영역
        - Code 영역은 실행 명령을 포함하는 코드들이 들어가는 부분
        - 프로그램을 시작할 때 컴파일한 프로그램(기계어)이 저장되어 있고, 읽기 전용 영역이기때문에 프로세스가 함부로 변경할 수 없고 변경 시 오류를 발생
    - Data 영역
        - 프로그램이 실행될 때 생성되고 프로그램이 종료되면 시스템에 반환
        - 전역변수, 정적변수, 배열, 구조체 등이 저장
        - Data 영역은 다시 Data(GVAR) 영역과 BSS 영역으로 나눌 수 있음
        - 초기화된 데이터는 Data(GVAR) 영역에 저장되고 초기화되지 않은 데이터는 BSS 영역에 저장
    - Heap 영역
        - 메모리를 동적으로 할당할 때 사용하는 메모리 영역
    - Stack 영역
        - 프로그램이 자동으로 사용하는 메모리 영역
        - 함수 호출과 관계되는 지역변수와 매개변수가 저장되며 함수 호출 시 생성되고 함수가 끝나면 반환
- 스레드
    - 프로그램 내에서 실행되는 흐름의 단위
        
        ![Threads](https://github.com/WooJJam/CS_interview_Study/blob/main/os%26computer_structure/img/Threads.png)
        
    
    ![Threads_Structure](https://github.com/WooJJam/CS_interview_Study/blob/main/os%26computer_structure/img/Threads_Structure.png)
    
    - 프로세스 내에서 각각 Stack 만 따로 할당 받고 Code, Data, Heap 영역은 공유
    - 한 프로세스 내에서 동작되는 여러 실행의 흐름으로, 프로세스 내의 주소 공간이나 자원들(heap 공간 등)을 같은 프로세스 내에 스레드끼리 공유하면서 실행
    - 같은 프로세스 안에 있는 여러 스레드들은 같은 heap 공간을 공유하는 반면에 프로세스는 다른 프로세스의 메모리에 직접 접근할 수 없음
- 멀티 프로세스
    - 하나의 응용 프로그램을 여러 개의 프로세스로 구성하여 각 프로세스가 하나의 작업을 처리하도록 하는 것
    - 여러 개의 자식 프로세스 중 하나에 문제가 발생해도 다른 프로세스들이 있기 때문에 시스템에 영향이 확산되지 않음
    - 독립된 구조로 안전성이 높음
    - 메모리 영역이 서로 독립적이기 때문에 작업량이 많다면 Context Switching이 자주 발생하여 오버헤드가 발생하여 성능저하가 발생 할 수 있음
- 멀티 스레드
    
    ![Multi_Threads](https://github.com/WooJJam/CS_interview_Study/blob/main/os%26computer_structure/img/Multi_Threads.png)
    
    - 하나의 프로그램을 여러 개의 스레드로 구성하는 방식
    - Stack을 제외한 자원들을 공유하기 때문에 Context Switching 시에 캐시를 비울 필요가 없어 리소스가 절약됨
    - 같은 데이터를 공유하기에 데이터 동기화에 신경을 써야함
    - 한개의 프로세스의 여러개의 스레드가 있는 구조이므로 프로세스에 문제가 생기면 다른 스레드까지 문제가 생길 가능성이 높음
- 답안
    - 멀티 스레드는 멀티 프로세스보다 적은 메모리 공간을 차지하고 Context Switching이 빠르다는 장점이 있지만, 오류로 인해서 하나의 프로세스에 문제가 생기면 다른 스레드에도 문제가 생길 수 있다는 점과 동기화 문제를 가지고 있다. 반면에 멀티 프로세스는 하나의 프로세스가 문제가 생기더라도 다른 프로세스에는 영향을 끼치지 않는다는 장점이 있지만, 멀티 스레드보다 많은 메모리 공간과 CPU 시간을 차지한다는 단점이 있다.
- 참고자료
    
    [[운영체제] 멀티 프로세스(Multi-Process)와 멀티 스레드(Multi-Thread)](https://velog.io/@younghoondoodoom/멀티-프로세스Multi-Process와-멀티-스레드Multi-Thread)
    
    [CS 정리 운영체제(1)](https://velog.io/@tlatjdgh3778/CS-정리-운영체제1)
    
    [멀티 프로세스(Multi Process)와 멀티 스레드(Multi Thread)](https://wooody92.github.io/os/멀티-프로세스와-멀티-스레드/)
