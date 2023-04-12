# Blocking/Non-blocking & Synchronous/Asynchronous에 대해 설명해주세요.

- **자료 조사**
    
    동기/비동기는 우리가 일상 생활에서 많이 들을 수 있는 말이다. Blocking과 Synchronous, 그리고 Non-blocking과 Asynchronous를 서로 같은 개념이라고 착각하기 쉽다.
    
    각자 어떤 의미를 가지는지 살펴보자.
    
    ![Blocking/Non-blocking & Synchronous/Asynchronous Matrix](https://github.com/BangDori/CS_interview_Study/blob/main/network/img/Matrix.png)
    
    - **Blocking/Non-blocking (어른, 응애)**
        
        Blocking/Non-blocking은 간단히 말해서 **호출된 함수**가 **호출한 함수**에게 제어권을 건네주는 유무의 차이라고 볼 수 있다.
        
        함수 A, B가 있고, A 안에서 B를 호출했다고 가정해보자. 이때 호출한 함수는 A고, 호출한 함수는 B가 된다. 현재 B가 호출되면서 B는 자신의 일을 진행해야 한다. (제어권이 B에게 주어진 상황)
        
        - Blocking: 함수 B는 내 할 일을 다 마칠 때까지 제어권을 가지고 있는다. A는 B가 다 마칠 때까지 기다려야 한다.
        - Non-blocking: 함수 B는 할 일을 마치지 않았어도 A에게 제어권을 바로 넘겨준다. A는 B를 기다리면서도 다른 일을 진행할 수 있다.
        
        즉, 호출된 함수에서 일을 시작할 때 제어권을 리턴해주느냐, 할 일을 마치고 리턴해주느냐에 따라 Blocking과 Non-blocking이 나누어진다고 볼 수 있다.
        
    - **Synchronous/Asynchronous (참을성X, 참을성O)**
        
        Synchronous/Asynchronous는 일을 수행 중인 **동시성**이라고 생각하자.
        
        아까처럼 함수 A와 B라고 똑같이 생각했을 때, B의 수행 결과나 종료 상태를 A가 신경쓰고 있는지에 대한 유무의 차이라고 생각하면 된다.
        
        - Synchronous: 함수 A는 함수 B가 일을 하는 중에 기다리면서, 현재 상태가 어떤지 계속 체크한다.
        - Asynchronous: 함수 B의 수행 상태를 B 혼자 직접 신경쓰면서 처리한다. (Callback)
        
        즉, 호출된 함수(B)를 호출한 함수(A)가 신경쓰는지, 호출된 함수(B) 스스로 신경쓰는지를 Synchronous/Asynchronous 라고 생각하면 된다.
        
        비동기는 호출시 Callback을 전달하여 작업의 완료 여부를 호출한 함수에게 답하게 된다. (Callback이 오기 전까지 호출한 함수는 신경쓰지 않고 다른 일을 할 수 있음)
        
    - **Example**
        
        ### 1) Blocking & Synchronous
        
        ```jsx
        나 : 사장님 치킨 한마리만 포장해주세요
        사장님 : 네 금방되니까 잠시만요!
        나 : 넹
        -- 사장님 치킨 튀기는 중--
        나 : (아 언제 되지?..궁금한데 그냥 멀뚱히 서서 치킨 튀기는거 보면서 기다림)
        ```
        
        제어권이 사장님에게 있어서 물어보지도 못함, 사장님 눈치 보면서 현재 상태를 계속 체크
        
        ---
        
        ### 2) Blocking & Asynchronous
        
        ```jsx
        나 : 사장님 치킨 한마리만 포장해주세요
        사장님 : 네 금방되니까 잠시만요!
        나 : 앗 넹
        -- 사장님 치킨 튀기는 중--
        나 : (언제 되는지 알빠노, 잠시만이래서 기다리는 중)
        ```
        
        제어권이 사장님 한테 있지만, 눈치 안보면서 기다리는 중
        
        ---
        
        ### **3) Non-blocking & Synchronous**
        
        ```jsx
        나 : 사장님 치킨 한마리만 포장해주세요
        사장님 : 네~ 주문 밀려서 시간 좀 걸리니까 볼일 보시다 오세요
        나 : 넹
        -- 사장님 치킨 튀기는 중--
        (5분뒤) 나 : 제꺼 나왔나요?
        사장님 : 아직이요
        (10분뒤) 나 : 제꺼 나왔나요?
        사장님 : 아직이요ㅠ
        (15분뒤) 나 : 제꺼 나왔나요?
        사장님 : 아직이요ㅠㅠ
        ```
        
        제어권이 나한테 있고, 눈치 보면서 계속 물어보는 중
        
        ---
        
        ### **4) Non-blocking & Asynchronous**
        
        ```jsx
        나 : 사장님 치킨 한마리만 포장해주세요
        사장님 : 네~ 주문 밀려서 시간 좀 걸리니까 볼일 보시다 오세요
        나 : 넹
        -- 사장님 치킨 튀기는 중--
        나 : (앉아서 유튜브 보는 중)
        ...
        사장님 : 치킨 나왔습니다
        나 : 잘먹겠습니다~
        ```
        
        제어권이 나한테 있고, 눈치 안보니까 걍 유튜브 봄
        
- **답안**
    
    블로킹과 논블로킹의 차이는 제어권을 누가 가지고 있냐에 대한 차이로, 블로킹의 경우 A 함수가 B 함수를 호출할 때 B 함수가 작업이 종료되기 전까지 A 함수에게 제어권을 돌려주지 않는 것을 의미합니다. 반면, 논 블로킹은 A 함수가 다른 일을 할 수 있도록 제어권을 넘겨주는 것입니다.
    
    그리고 동기와 비동기의 차이는 호출한 함수를 누가 처리하느냐에 대한 차이로, 동기의 경우 A 함수가 B 함수를 호출할 때, B 함수의 결과를 A 함수가 처리하고, 비동기의 경우 A 함수가 B 함수를 호출할 때, B 함수의 결과를 B 함수가 처리하게 하는 것 입니다.
    
- **참고 자료**
    1. [Github - gyoogle/tech-interview-for-developer](https://github.com/gyoogle/tech-interview-for-developer/blob/master/Computer%20Science/Network/%5BNetwork%5D%20Blocking%2CNon-blocking%20%26%20Synchronous%2CAsynchronous.md)
    2. [Blocking, Non-blocking, Sync, Async의 차이](https://jh-7.tistory.com/25)
