# System Call에 대해 설명하시오

## 답안

User mode로 실행되는 응용프로그램이 프로세서 제어나 파일 조작 등 Kernel mode에서의 명령어 수행이  필요한 경우 운영체제에 요청하여 kernel mode에서 명령어를 실행할수 았도록 제공하는 서비스

---

## 자료 조사

- CPU Mode
    
    시스템의 안전성을 위해 운영체제는 프로세서애 대해 두 가지 접근 모드를 지원함
    
    - 미숙한 사용자나 해커가 시스템의 중요 파일을 함부로 변조나, 삭재 하는 것을 막기 위해
    - User Mode
        
        일반적인 응용프로그램은 기본적으로 User Mode에서 실행됨
        
        시스템 데이터에 대해 제한된 접근,  하드웨어에 대한 직접 접근 불가
        
    - Kernel Mode
        
        시스템의 모든 자원에 대해 접근, 명령을 할 수 있음. 
        
        OS나 드라이버 등이 실행
        
- System call
    
    운영체제의 커널이 제공하는 서비스에 대해, 응용프로그램의 요청에 따라 커널에 접근하기 위한 인터페이스
    
    - C나 C++ 같이 고급 언어로 작성된 프로그램의 경우 직접적으로 system call을 사용할 수 없어 고급 API를 통해 system call에 접근함
        - fork(), open(), sleep()
    1. User mode로 실행되는 응용프로그램이  I/O와 같이 User mode에서 실행 불가능한 명령어를 처리 하는 경우 System call
    2. System call을 통해 user mode에서 kernel mode로 변경 후 kernel에서 명령을 처리
    3. Kelnel에서 처리가 끝나면 user mode로 다시 전환되며 응용 프로그램이 계속 실행됨

[https://t1.daumcdn.net/cfile/tistory/25333241535CCEE810](https://t1.daumcdn.net/cfile/tistory/25333241535CCEE810)

- System call의 종류
- 프로세스 컨트롤
    - 프로세스 생성 및 종료
    - 메모리에 로드, 실행
    - 프로세스 속성 값 확인, 지정
    - wait 이벤트, signal 이벤트
    - 메모리 할당
- 파일 메니지먼트
    - 파일 생성, 파일 삭제
    - 열기, 닫기
    - 읽기, 쓰기, Reposition
    - 파일 속성 값 확인, 지정
- 디바이스 매니지먼트
    - 디바이스 요청 및 해제
    - 읽기, 쓰기, Reposition
    - 디바이스 속성 확인, 지정
    - 비 물리적인 디바이스 해제 및 장착
- 정보 관리
    - 시간 확인, 시간 지정
    - 시스템 데이터 확인, 지정
    - 프로세스, 파일, 디바이스 속성 가져오기
    - 프로세스, 파일, 디바이스 속성 설정하기
- 커뮤니케이션
    - 커뮤니케이션 연결 생성 및 삭제
    - 메시지 송신, 수신
    - 상태 정보 전달
    - remote 디바이스 해제 및 장착
- 보안
    - Permission 획득
    - Permission 설정

---

## 꼬리 질문

---

## Ref

[https://ko.wikipedia.org/wiki/시스템_호출](https://ko.wikipedia.org/wiki/%EC%8B%9C%EC%8A%A4%ED%85%9C_%ED%98%B8%EC%B6%9C)

[https://fjvbn2003.tistory.com/306](https://fjvbn2003.tistory.com/306)

[https://velog.io/@nnnyeong/OS-시스템-콜-System-Call](https://velog.io/@nnnyeong/OS-%EC%8B%9C%EC%8A%A4%ED%85%9C-%EC%BD%9C-System-Call)