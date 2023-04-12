## ISA가 무엇인가요?

- 자료 조사

### 1. ISA란?

- **ISA**는**Instruction set architecture**의 약자로 한글로 해석하면 명령어 집합 구조이며, 마이크로프로세서가 인식해서 기능을 이해하고 실행할 수 있는 기계어 명령어를 말한다.
  - 마이크로프로세서마다 기계어 코드의 길이와 숫자 코드가 다르다.
  - 명령어의 각 비트는 기능적으로 분할하여 의미를 부여하고 숫자화한다.
  - 프로그램 개발자가 숫자(0과 1로 이루어진 숫자들)로 프로그램하기가 불편하므로 기계어와 일대일로 문자화한 것이 어셈블리어이다.
- 응용 어플리케이션에서 부터 시작하여 다양한 단계를 거쳐서 Software 에서 Hardware로 넘어가게 된다.
  - Software 에서 Hardware 로 넘어가는 단계에서 중재자 역할을 해주는 것이 ISA

<aside>
💡 **ISA 는 하드웨어와 소프트웨어가 서로 어떻게 소통할지 정해놓는 규약**

</aside>

![Location_Of_ISA](https://s3-us-west-2.amazonaws.com/secure.notion-static.com/43e37206-a4de-4e42-9d68-09e04736a879/Location_Of_ISA.png?raw=true)

- ISA는 최하위 레벨의 프로그래밍 인터페이스로, 프로세서가 실행할 수 있는 모든 명령어들을 포함한다.
- 명령어 집합, 곧 명령어 집합 구조는 자료형, 명령어, 레지스터, 어드레싱 모드, 메모리 구조, 인터럽트, 예외 처리, 외부 입출력을 포함한 프로그래밍관련 컴퓨터 아키텍처의 일부이다.

---

### 2. 마이크로 아키텍쳐란?

- 명령어 집합 구조(ISA)를 **물리적으로 구현하는 방법**을 마이크로아키텍처 혹은 컴퓨터 조직이라고 한다.
- 같은 명령어 집합 구조를 서로 다른 마이크로아키텍처로 구현하기도 한다.
  - 인텔의 펜티엄과 AMD의 애슬론은 거의 같은 명령어 집합 구조를 서로 다른 마이크로아키텍처로 구현한 것
- CPU 와 같은 말입니다. 단지 초기의 프로세서보다 작아졌기에 마이크로가 붙음
- 즉, 마이크로 아키텍처는 CPU 의 명령어 처리 방식

  - CPU 아키텍처의 하위 개념이며, CPU 아키텍처는 CISC 와 RISC 등이 있습니다.
  - CISC 와 RISC 의 CPU 아키텍처 기반의 마이크로 아키텍처가 여러 개 존재

- 답안
  명령어 집합 구조이며, 마이크로프로세서가 인식해서 기능을 이해하고 실행할 수 있는 기계어 명령어를 말한다. ISA는 최하위 레벨의 프로그래밍 인터페이스로, 프로세서가 실행할 수 있는 모든 명령어들을 포함한다. 사용자는 응용 어플리케이션에서 부터 시작하여 다양한 단계를 거쳐서 Software 에서 Hardware로 넘어가게 된다. ISA는 Software 에서 Hardware 로 넘어가는 단계에서 중재자 역할을 해준다. 즉, ISA 는 하드웨어와 소프트웨어가 서로 어떻게 소통할지 정해놓는 규약이라고 할 수 있다.
- Reference

  [[컴퓨터구조] ISA(Instruction set architecture)와 마이크로 아키텍쳐란? - Easy is Perfect](https://melonicedlatte.com/computerarchitecture/2019/01/30/192433.html)

  [[컴퓨터구조] ISA(Instruction set architecture)와 마이크로 아키텍쳐란? - Easy is Perfect](https://melonicedlatte.com/computerarchitecture/2019/01/30/192433.html)
