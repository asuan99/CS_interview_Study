# 싱글톤 패턴은 무엇이고 종류는 어떤것이 있나요?

- **자료 조사**
    
    ### 싱글톤 패턴이란?
    
    ![[그림 1] 싱글톤 패턴](https://github.com/BangDori/CS_interview_Study/blob/main/common%26design_pattern/img/singleton_pattern.png)
    
    싱글톤(Singleton) 패턴의 정의는 단순하다. 객체의 인스턴스가 오직 1개만 생성되는 패턴을 의미한다. 
    
    싱글톤 패턴을 구현하는 방법은 여러가지가 있지만, 여기서는 객체를 미리 생성해두고 가져오는 가장 단순하고 안전한 방법을 소개하겠다.
    
    ```java
    public class Singleton {
    
        private static Singleton instance = new Singleton();
    
        private Singleton() {
            // 생성자는 외부에서 호출못하게 private 으로 지정해야 한다.
        }
    
        public static Singleton getInstance() {
            return instance;
        }
    
        public void say() {
            System.out.println("hi, there");
        }
    }
    ```
    
    ### 싱글톤 패턴을 사용하는 이유
    
    위와 같이 인스턴스를 오직 한개만 생성하는 것에는 어떤 이점이 있을까?
    
    싱글톤 패턴은 객체 지향 프로그래밍에서 사용되는 디자인 패턴 중 하나로, 특정 클래스의 인스턴스가 단 하나만 생성되도록 보장하는 것을 의미합니다. 이 패턴은 다른 객체들이 항상 동일한 인스턴스를 사용할 수 있게 하여, 객체 간의 데이터 공유와 일관성을 제공합니다.
    
    1. **인스턴스 생성 비용 감소**
        
        싱글톤 패턴은 클래스의 인스턴스가 단 하나만 생성되므로, 여러 번의 인스턴스 생성을 피할 수 있습니다.
        
        인스턴스 생성에는 시간과 자원이 소모되기 때문에, 싱글톤 패턴을 사용하면 이러한 비용을 줄일 수 있습니다.
        
    2. **빠른 접근 속도**
        
        싱글톤 인스턴스는 전역적으로 접근 가능한 단일 인스턴스이므로, 다른 객체들이 해당 인스턴스에 빠르게 접근할 수 있습니다.
        
        인스턴스를 생성하고 초기화하는 작업을 반복하지 않고도 필요할 때마다 인스턴스를 사용할 수 있기 때문에 성능이 향상될 수 있습니다.
        
    3. **객체 상태의 일관성 유지**
        
        싱글톤 패턴은 동일한 인스턴스를 사용하므로, 객체의 상태가 유지됩니다. 이는 여러 객체 간에 데이터를 공유할 때 유용합니다.
        
        예를 들어, 어플리케이션에서 로깅을 위한 싱글톤 인스턴스를 사용한다면, 여러 곳에서 로그를 기록할 수 있고, 로그의 일관성을 유지할 수 있습니다.
        
    4. **리소스 공유 및 관리**
        
        싱글톤 패턴은 인스턴스가 단 하나만 존재하기 때문에, 해당 인스턴스를 공유하여 리소스 사용을 최적화할 수 있습니다.
        
        예를 들어, 데이터베이스 연결, 네트워크 연결 또는 파일 시스템 접근과 같은 리소스를 관리할 때, 여러 객체가 동시에 인스턴스를 생성하지 않고 싱글톤 패턴을 사용하면 리소스를 효율적으로 공유할 수 있습니다.
        
    
    ### 싱글톤 패턴의 종류
    
    싱글톤 패턴은 다양한 방식으로 구현될 수 있으며, 일반적으로 다음과 같은 종류의 싱글톤 패턴이 사용됩니다.
    
    - **이른 초기화 방식 (Eager initialization)**
        - 한 번만 미리 만들어두는, 가장 직관적이면서도 심플한 기법
        - **`static final`** 이라 멀티 쓰레드 환경에서도 안전함
        - **`static`** 멤버는 당장 객체를 사용하지 않더라도 메모리에 적재하기 때문에 만일 리소스가 큰 객체일 경우, 공간 자원 낭비가 발생함
        - 예외 처리를 할 수 없음
        
        <aside>
        💡 **Tip**
        
        만일 싱글톤을 적용한 객체가 그리 크지 않은 객체라면 이 기법으로 적용해도 무리는 없다.
        
        </aside>
        
        ```java
        class Singleton {
            // 싱글톤 클래스 객체를 담을 인스턴스 변수
            private static final Singleton INSTANCE = new Singleton();
        
            // 생성자를 private로 선언 (외부에서 new 사용 X)
            private Singleton() {}
        
            public static Singleton getInstance() {
                return INSTANCE;
            }
        }
        ```
        
    - **정적 초기화 블럭 방식 (Static block initialization)**
        - **`static block`** 을 이용해 예외를 잡을 수 있음
        - **`static`**의 특성으로 사용하지도 않는데도 공간을 차지함
        
        ```java
        class Singleton {
            // 싱글톤 클래스 객체를 담을 인스턴스 변수
            private static Singleton instance;
        
            // 생성자를 private로 선언 (외부에서 new 사용 X)
            private Singleton() {}
            
            // static 블록을 이용해 예외 처리
            static {
                try {
                    instance = new Singleton();
                } catch (Exception e) {
                    throw new RuntimeException("싱글톤 객체 생성 오류");
                }
            }
        
            public static Singleton getInstance() {
                return instance;
            }
        }
        ```
        
    - **늦은 초기화 방식 (Lazy initialization)**
        - 객체 생성에 대한 관리를 내부적으로 처리
        - 메서드를 호출했을 때 인스턴스 변수의 null 유무에 따라 초기화 하거나 있는걸 반환하는 기법
        - Eager, Static block에서 발생하였던 고정 메모리 차지의 한계점을 극복
        - 쓰레드 세이프(Thread Safe) 하지 않는 치명적인 단점을 가지고 있음
        
        ```java
        class Singleton {
            // 싱글톤 클래스 객체를 담을 인스턴스 변수
            private static Singleton instance;
        
            // 생성자를 private로 선언 (외부에서 new 사용 X)
            private Singleton() {}
        	
            // 외부에서 정적 메서드를 호출하면 그제서야 초기화 진행 (lazy)
            public static Singleton getInstance() {
                if (instance == null) {
                    instance = new Singleton(); // 오직 1개의 객체만 생성
                }
                return instance;
            }
        }
        ```
        
        ### **⚠ 멀티 쓰레드 환경에서의 치명적인 문제점**
        
        대부분의 자료에서 보통 위 코드를 싱글톤 패턴의 정석이라고 소개하지만, 사실 위 코드에는 치명적인 문제점이 있다.
        
        자바는 멀티 쓰레드 언어인데, 이 멀티 쓰레드 환경에서 쓰레드 세이프 하지 않다는 것이다.
        
        각 스레드는 자신의 실행단위를 기억하면서 코드를 위에서 아래로 읽어간다. 따라서 다음과 같은 동시성으로 인한 코드 실행 문제점이 발생할 수 있게 된다.
        
        ① 스레드 **A**, 스레드 **B**가 존재한다고 가정해보자.
        
        ② 스레드 **A**가 if문을 평가하고 인스턴스 생성 코드로 진입하였다. (초기화는 진행 X)
        
        ③ 그런데 그 때 스레드 **B**가 if문을 평가한다. 아직 스레드 **A**가 인스턴스화 코드를 실행 시키지 않았기 때문에 B가 평가하는 if문도 참이 되게 된다.
        
        ④ 결과적으로 스레드 **A**와 **B**가 인스턴스 초기화 코드를 두 번 실행하는 꼴이 된다. (원자성 결여)
        
    - **쓰레드 안전 초기화 방식 (Thread safe initialization)**
        - **`synchronized`** 키워드를 통해 메서드에 쓰레드들을 하나하나씩 접근하게 하도록 설정한다. (동기화)
        - 하지만, 여러 개의 모듈들이 매번 객체를 가져올 때 **`synchronized`** 메서드를 매번 호출하여 동기화 처리 작업에 overhead가 발생해 성능 하락이 발생한다.
        
        <aside>
        💡 **Info**
        
        synchronized 키워드는 멀티 쓰레드 환경에서 두 개 이상의 쓰레드가 하나의 변수에 동시에 접근할 때 Race condition(경쟁 상태)이 발생하지 않도록 한다.
        한마디로 쓰레드가 해당 메서드를 실행하는 동안 다른 쓰레드가 접근하지 못하도록 잠금을 거는 것처럼 보면 된다.
        아래 그림 처럼 thread-1이 메서드에 진입하는 순간 나머지 thread-2 ~ 4의 접근을 제한하고, thread-1이 완료가 되면 다음 스레드를 접근시킨다.
        
        ![[그림 2] thread safe](https://github.com/BangDori/CS_interview_Study/blob/main/common%26design_pattern/img/thread_safe.png)
        
        </aside>
        
        ```java
        class Singleton {
            private static Singleton instance;
        
            private Singleton() {}
        
            // synchronized 메서드
            public static synchronized Singleton getInstance() {
                if (instance == null) {
                    instance = new Singleton();
                }
                return instance;
            }
        }
        ```
        
    
    ### 싱글톤 패턴의 문제점
    
    1. **모듈간 의존성이 높아진다.**
        
        대부분의 싱글톤을 이용하는 경우, 인터페이스가 아닌 클래스의 객체를 미리 생성하고 정적 메소드를 이용해 사용하기 때문에 클래스 사이에 강한 의존성과 높은 결합이 생기게 된다.
        
        즉, 하나의 싱글톤 클래스를 여러 모듈들이 공유를 하니까, 만약 싱글톤의 인스턴스가 변경되면 이를 참조하는 모듈들도 수정이 필요하게 된다.
        
        또한, 클라이언트 코드에서 너무 많은 곳에서 사용하면 클래스간의 결합도가 높아져 오히려 패턴을 사용 안하느니만 못하게 될 수도 있다.
        
    2. **S.O.L.I.D 원칙에 위배되는 사례가 많다.**
        
        우선 싱글톤 인스턴스 자체가 하나만 생성하기 때문에 여러가지 책임을 지니게 되는 경우가 많아 단일 책임 원칙(SRP)를 위반하기도 하고, 싱글톤 인스턴스가 혼자 너무 많은 일을 하거나, 많은 데이터를 공유시키면 다른 클래스들 간의 결합도가 높아지게 되어 개방-폐쇄 원칙(OCP)에도 위배된다.
        
        그리고 의존 관계쌍 클라이언트가 인터페이스와 같은 추상화가 아닌, 구체 클래스에 의존하게 되어 의존 역전 원칙(DIP)도 위반하게 된다.
        
        따라서 싱글톤 인스턴스를 너무 많은 곳에서 사용할 경우 잘못된 디자인 형태가 될 수도 있다.
        
        그래서 싱글톤 패턴을 객체 지향 프로그래밍의 안티 패턴이라고 불리기도 한다.
        
    3. **TDD 단위 테스트에 애로사항이 있음**
        
        마지막으로 싱글톤 클래스를 사용하는 모듈을 테스트하기 어렵다는 것이다.
        
        단위 테스트를 할 때, 단위 테스트는 테스트가 서로 독립적이여야 하며 테스트를 어떤 순서로든 실행 할 수 있어야 하는데, 싱글톤 인스턴스는 자원을 공유하고 있기 때문에, 테스트가 결함없이 수행되려면 매번 인스턴스의 상태를 초기화 시켜주어야 한다. 그렇지 않으면 어플리케이션 전역에서 상태를 공유하기 때문에 테스트가 온전하게 수행되지 못할 수도 있다.
        
        많은 테스트 프레임워크가 Mock 객체를 생성할 때 상속에 의존하기 때문에 싱글턴의 클라이언트 코드를 테스트하기 어렵다.
        
- **답안**
    
    싱글톤 패턴은 객체 지향 프로그래밍에서 사용되는 디자인 패턴 중 하나로, 특정 클래스의 인스턴스가 단 하나만 생성되도록 보장하는 것을 의미합니다. 이 패턴은 전역적으로 접근 가능한 단일 인스턴스를 제공하여 객체 간의 데이터 공유와 일관성을 유지할 수 있습니다.
    
    싱글톤 패턴의 종류에는 Eager initialization, Static block initialization, Lazy initialization, Thread safe initialization 방식 등이 있습니다.
    
- **참고 자료**
    
    [https://tecoble.techcourse.co.kr/post/2020-11-07-singleton/](https://tecoble.techcourse.co.kr/post/2020-11-07-singleton/)
    
    [https://chat.openai.com/](https://chat.openai.com/)
    
    [https://inpa.tistory.com/entry/GOF-💠-싱글톤Singleton-패턴-꼼꼼하게-알아보자#싱글톤_패턴_구현_기법_종류](https://inpa.tistory.com/entry/GOF-%F0%9F%92%A0-%EC%8B%B1%EA%B8%80%ED%86%A4Singleton-%ED%8C%A8%ED%84%B4-%EA%BC%BC%EA%BC%BC%ED%95%98%EA%B2%8C-%EC%95%8C%EC%95%84%EB%B3%B4%EC%9E%90#%EC%8B%B1%EA%B8%80%ED%86%A4_%ED%8C%A8%ED%84%B4_%EA%B5%AC%ED%98%84_%EA%B8%B0%EB%B2%95_%EC%A2%85%EB%A5%98)
