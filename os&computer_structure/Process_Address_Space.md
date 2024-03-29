# 프로세스 주소 공간에 대해서 설명해주세요.

- **자료 조사**
    
    > **프로세스 주소 공간**은 하나의 프로세스가 실행되기 위해 운영체제로부터 할당받은 메모리 공간을 의미합니다. 이 메모리 공간은 프로세스가 실행되는 동안 필요한 텍스트, 데이터, 스택 등의 정보를 저장하고 관리하는데 사용됩니다.
    > 
    
    프로세스 주소 공간은 일반적으로 다음과 같이 구성됩니다.
    
    ![[그림 1] 프로세스 주소 공간](https://github.com/BangDori/CS_interview_Study/blob/main/os%26computer_structure/img/Process_Address_Space.png)
    
    - **스택(Stack)**
        - 스택은 프로세스 주소 공간의 일부로, 함수 호출 시 지역 변수, 매개 변수, 리턴 주소 등을 저장하는 영역입니다.
        - 메모리의 상위 주소에서 아래 방향으로 할당되는 후입선출(LIFO) 방식으로 동작합니다.
        - 함수의 호출 시 스택에 새로운 프레임이 추가되며, 함수 호출이 끝나면 해당 프레임이 스택에서 제거됩니다.
    - **힙(Heap)**
        - 힙은 동적 메모리 할당에 사용되는 영역으로, 프로세스가 실행 중에 필요한 메모리를 동적으로 할당하고 해제하는 데 사용됩니다.
        - **런타임에 크기가 결정되는** 영역이다.
        - 힙은 데이터 영역 바로 다음에 위치하며, 스택과는 반대로 낮은 주소에서 높은 주소로 증가합니다.
        - 사용자에 의해 공간이 동적으로 할당 및 해제된다.
        - 힙은 일반적으로 c언어에서 `malloc()`, `calloc()`, `realloc()`과 같은 함수를 사용하여 메모리를 할당하고, `free()` 함수를 사용하여 할당된 메모리를 해제합니다.
    - **데이터(Data)**
        - 데이터 영역은 전역 변수, 정적(static) 변수, 초기화된 데이터 등을 저장하는 영역입니다.
        - 데이터 영역은 프로그램이 실행되기 전에 초기화되며, 프로그램이 종료될 때까지 유지됩니다.
        - 데이터 영역은 텍스트 영역 바로 다음에 위치하며, 크기는 컴파일러가 결정합니다.
    - **텍스트(Text)**
        - 텍스트 영역은 프로그램 코드를 저장하는 영역으로, CPU가 실행하는 명령어들이 위치합니다.
        - 텍스트 영역은 실행 파일의 일부로 저장되며, 실행 파일이 로드될 때 메모리에 적재됩니다.
        - 텍스트 영역은 읽기 전용으로 처리되며, 프로그램 실행 중에 수정될 수 없습니다.
    
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    
    int glob;
    
    int main(void) {
        int local, *dynamic;
        dynamic = malloc(1303);
    
        printf("Local = %p\n", &local);
        printf("Dynamic= %p\n", dynamic);
        printf("Global = %p\n", &glob);
        printf("main = %p\n", main);
    
    		printf("%d\n", show(1));
        return 0;
    }
    
    int show(int val) {
    		return val;
    }
    ```
    
    - **위 코드에서, 스택, 힙, 데이터, 텍스트 영역에 뭐가 저장될까요?**
        - **정답**            
            ![[그림 2] Example of Process Image in Linux](https://github.com/BangDori/CS_interview_Study/blob/main/os%26computer_structure/img/Process_Image_In_Linux.png)
            
            - 스택 영역 - 지역 변수 local이 저장되고, printf, show 함수 호출 시 스택에 임시 변수들이 생성되며, 함수가 끝나면 스택에서 제거됩니다.
            - 힙 영역 - dynamic 포인터가 가리키는 메모리 블록 저장
            - 데이터 영역 - 전역 변수인 glob
            - 텍스트 영역 - 프로그램 코드 전체
- **답안**
    
    프로세스 주소 공간은 컴퓨터에서 실행되는 프로그램의 메모리 공간을 나타냅니다. 메모리 공간은 일반적으로 4GB로 제한되며, 주소 공간의 크기는 운영체제와 시스템 아키텍처에 따라 다를 수 있습니다.
    
    프로세스 주소 공간은 크게 네 가지 영역으로 구분할 수 있습니다. 코드 부분이 저장되는 텍스트 영역, 전역 변수, 정적 변수, 초기화된 전역 변수가 저장되는 영역인 데이터 영역, 함수 호출 시 사용되는 지역 변수, 매개 변수, 함수 호출 시 반환 주소 등이 저장되는 스택 영역, 마지막으로 동적 할당된 메모리 공간이 저장되는 힙 영역이 있습니다.
    
    프로세스 주소 공간은 각각의 영역이 서로 겹치지 않도록 분리되어 있으며, 프로세스가 실행될 때 운영체제가 주소 공간을 할당하게 됩니다. 이러한 분리된 영역들은 프로세스의 안정성과 보안을 유지하는 데 큰 역할을 합니다.
    
- **참고 자료**
    1. 운영체제 - 곽종욱 교수님
    2. [https://velog.io/@klm03025/운영체제-프로세스-주소-공간](https://velog.io/@klm03025/%EC%9A%B4%EC%98%81%EC%B2%B4%EC%A0%9C-%ED%94%84%EB%A1%9C%EC%84%B8%EC%8A%A4-%EC%A3%BC%EC%86%8C-%EA%B3%B5%EA%B0%84)
    3. ChatGPT
