# MVVM(Model-View-ViewModel) 패턴과 MVC 패턴의 차이점은 무엇인가요? 각각의 장단점을 설명해주세요.

- 자료조사

  ### MVVM의 이란

- Model + View + View Model를 합친 용어
- 모델과 뷰는 MVC와 동일
- Command 패턴과 Data Binding 두 가지 패턴을 사용하여 구현되었습니다.
  - Command 패턴과 Data Binding을 이용하여 View와 View Model 사이의 의존성을 없앴습니다.
- View Model과 View는 1:n 관계입니다.
- Command 패턴
  - 요청을 객체의 형태로 캡슐화하여 사용자가 보낸 요청을 나중에 이용할 수 있도록 매서드 이름, 매개변수 등 요청에 필요한 정보를 저장 또는 로깅, 취소할 수 있게 하는 패턴
- Data Binding
  - 공급자와 소비자의 데이터 소스를 함께 바인딩하고 동기화하는 일반적인 기술
  - 일반적으로 XML 데이터 바인딩 및 UI 데이터 바인딩에서와 같이 언어가 다른 두 개의 데이터/정보 소스로 수행
  - UI 데이터 바인딩에서 언어는 같지만 논리 기능이 다른 데이터 및 정보 개체가 함께 바인딩
  - 각 데이터 변경 사항은 데이터에 바인딩된 요소에 의해 자동으로 반영
  - 데이터 바인딩이라는 용어는 요소에 있는 데이터의 외부 표현이 변경되고 기본 데이터가 자동으로 업데이트되어 이 변경 사항을 반영하는 경우에도 사용

---

### MVVM의 구조

![Structure_Of_MVVM](https://github.com/JungMunGyu/CS_interview_Study/blob/main/common&design_pattern/img/Structure_Of_MVVM.png?raw=true)

- View Model
  - View를 표현하기 위해 만든 View를 위한 Model입니다. View를 나타내 주기 위한 Model이자 View를 나타내기 위한 데이터 처리를 하는 부분입니다.

---

### MVVM의 동작

1. 사용자의 Action들은 View를 통해 들어오게 됩니다.
2. View에 Action이 들어오면, Command 패턴으로 View Model에 Action을 전달합니다.
3. View Model은 Model에게 데이터를 요청합니다.
4. Model은 View Model에게 요청받은 데이터를 응답합니다.
5. View Model은 응답 받은 데이터를 가공하여 저장합니다.
6. View는 View Model과 Data Binding하여 화면을 나타냅니다.

---

### MVVM의 장점과 단점

- 장점
  - Command 패턴과 Data Binding을 사용하여, View와 Model 사이의 의존성이 없다.
  - 모듈화 하여 개발할 수 있다.
- 단점
  - View Model의 설계가 쉽지 않다.

---

### MVC패턴의 장점과 단점

- 장점
  - 널리 사용되고 있는 패턴이라는 점에 걸맞게 가장 단순
- 단점

  - View와 Model 사이의 의존성이 높다는 것입니다. View와 Model의 높은 의존성은 어플리케이션이 커질 수록 복잡해지고 유지보수가 어렵게 만들 수 있다.

- 답안
  > MVVM패턴은 MVC의 단점을 보안하고자 착안된 패턴중 하나이며, Model + View + View Model를 합친 용어이다. MVC는 다른 패턴의 시초이기도 하며, 가장 단순하다는 장점이 있지만 뷰와 모델 사이의 의존성이 높아 개발하는 프로젝트의 크기가 클수록 복잡해지고 유지보수가 어려워 진다는 단점이 있다. 하지만 MVVM패턴은 코맨드 패턴과 Data Binding을 사용하여 뷰와 모델의 의존성을 업애고 각각의 부분을 모듈화 하여 개발할 수 있다는 장점이 있다. 하지만 MVVM은 그만큼 View Model의 설계가 정확해야 하며, 설계가 쉽지만은 않다는 단점이 있다.
- reference
  [[디자인패턴] MVC, MVP, MVVM 비교](https://beomy.tistory.com/43)
