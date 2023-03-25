# REST, RESTful

# REST와 RESTful의 차이는 무엇인가요?

- REST (Representational State Transfer)
    
    ![REST](https://github.com/WooJJam/CS_interview_Study/blob/main/network/img/REST.png)
    
    - 월드 와이드 웹과 같은 분산 하이퍼미디어 시스템을 위한 소프트웨어 아키텍처의 형식
    - 자원을 이름(자원의 표현)으로 구분하여 해당 자원의 상태(정보)를 주고 받는 모든 것을 의미
        - 자원
            - 소프트웨어가 관리하는 모든것
            - EX) 문서, 사진, 데이터 등
        - 자원의 표현
            - 그 자원을 표현하기 위한 이름
            - EX) db의 학생 정보가 자원이라면, ‘students’를 자원의 표현으로 정함
        - 상태(정보) 전달
            - 데이터가 요청되어지는 시점에서 자원의 상태(정보)를 전달
            - JSON, XML 등과 같은 형태로 데이터를 주고 받음
    - HTTP 프로토콜을 그대로 활용하기 대문에, 웹의 장점을 최대한 활용할 수 있는 아키텍처 스타일
    - 즉, 네트워크 상에서 Client와 Server 사이의 통신 방식 중 하나
    - CRUD 연산을 수행하기 위해 URI로 get,post 등의 방식 (Method)를 사용하여 요청을 보내며, 요청을 위한 자원은 특정한 형태로 표현됨
- URI vs URL
    - URL(Uniform Resource Lacator): 인터넷 상 자원의 위치
    - URI(Uniform Resource Identifier): 인터넷 상의 자원을 식별하기 위한 문자열의 구성으로, URI는 URL을 포함하게 된다. URI가 URL보다 포괄적인 범위
- REST의 구성요소
    - 자원(Resource): URI
        - 모든 자원에는 고유한 ID가 존재하고, 이 자원은 Server에 존재
        - 자원을 구별하는 ID는 ‘/student/:student_id’ 와 같은 URI형식
        - Client는 URI를 이용해 자원을 지정하고 해당 자원의 상태에 대한 조작을 Server에 요청
    - 행위(verb): HTTP Method
        - HTTP 프로토콜의 Method를 사용
        - HTTP 프로토콜은 GET, POST, PUT, DELETE와 같은 메서드를 제공
    - 표현(Representation of Resource)
        - Client가 자원의 상태에 대한 조작을 요청하면, Server는 응답을 보냄
        - 해당 응답은 Json, XML, Textm RSS등 여러 형태가 존재
- REST API
    - REST 기반으로 서비스 API를 구현한 것
    - 시스템을 REST 기반으로 분산해 확장성과 재사용성을 높여 유지보수 및 운용을 편리하게 할 수 있음
    - REST는 HTTP 표준을 기반으로 구현하므로, HTTP를 지원하는 프로그램 언어로 클라이언트, 서버를 구현할 수 있음
- REST API 설계 기본 규칙
    
    ![REST_API_design_rules](https://github.com/WooJJam/CS_interview_Study/blob/main/network/img/REST_API_design_rules.png)
    
- RESTful
    - REST 원리를 따르는 시스템을 RESTful이란 용어로 부름
    - 공식적인것은 아님
    - 이해하기 쉽고 사용하기 쉬운 REST API를 만드는 것
- 답안
    
    RESTful은 REST의 설계 규칙을 잘 지켜서 설계한 좀 더 REST 같은것을 RESTful이라고 지칭한다. 차이가 없어보일순 있으나 REST의 원리를 잘 따르는 시스템을 RESTful 이라고 한다.
    
- 참고자료
    
    [[간단정리] REST, REST API, RESTful 특징](https://hahahoho5915.tistory.com/54#REST%25--%EA%25B-%AC%EC%25B-%25B-%EC%25A-%25--%EC%25-D%25B-%25--%EA%25B-%25-C%EB%25--%25--)
    
    [REST란? REST API 와 RESTful API의 차이점](https://dev-coco.tistory.com/97)
    
    [[CS] 📕 Network](https://velog.io/@soosungp33/CS-Network)
