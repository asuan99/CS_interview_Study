# 선형구조

## 자료구조에서 선형 구조란 무엇이며 선형 구조를 가지는 자료구조는 무엇이 있나요?

- 구조


    ![Linear-NonLinear](https://user-images.githubusercontent.com/111514410/222891310-51570957-a062-40fd-8e0a-69291e6f7498.png)


- 선형구조(Linear)


    ![Linear](https://user-images.githubusercontent.com/111514410/222891194-ea02d231-61a8-4d74-98b2-5aa68d0483b7.png)
    
    
    - 자료를 구성하는 데이터를 순차적으로 나열시킨 형태
    - 하나의 자료 뒤에, 또 다른 자료가 존재


- 배열 (Array)
    
    ![Array](https://user-images.githubusercontent.com/111514410/222891370-7b17f1f7-146d-4982-9327-595bd4ce66a5.jpg)
    - 같은 Type의 변수들로 이루어져 있음
    - 크기가 정해져 있음
    - 인접한 메모리 위치에 있는 데이터를 모아놓은 집합
    - 중복 허용, 순서가 있음
    - 탐색: O(1), 삽입과 삭제: O(n)
    - 랜덤 접근과 순차적 접근이 가능
        
        → 랜덤접근: 임의의 인덱스에 해당하는 데이터에 접근
        
- 연결리스트 (LinkedList)
    - Data를 감싼 노드를 포인터로 연결해서 공간적인 효율성을 극대화시킨 자료 구조
    - 가장 앞 노드를 head라고 하고, prev 포인터와 next 포인터로 앞과 뒤의 노드를 연결
    - 탐색: O(n), 삽입과 삭제: O(1)
    - 싱글 연결 리스트
        ![Linked-List](https://user-images.githubusercontent.com/111514410/222891738-9c7d5883-0a66-4f2e-9b22-388dcd09a3ea.jpg)
    
    - 이중 연결 리스트
        ![Doubly Linked-List](https://user-images.githubusercontent.com/111514410/222891844-9d2bfeda-9262-4bd5-96fb-80858f957d57.jpg)    
        
    - 원형 이중 연결 리스트


        ![Circular Linkend-List](https://user-images.githubusercontent.com/111514410/222892022-ea2df66f-b9f6-4702-92f7-291d9c41c12c.jpg)


- 배열 vs 연결리스트
    - 배열: 순서대로 나열한 데이터 구조이므로, 인덱스만 알면 해당 데이터를 확인할 수 있다.
    - 연결리스트: 포인터로 연결한 형태의 데이터 구조로, 데이터를 알기 위해선 순차적으로 접근하여야 한다. 랜덤접근(x)

- 스택 (Stack)
    
    
    ![Stack](https://user-images.githubusercontent.com/111514410/222891462-0fb8d34e-5106-47c1-b5ea-f65a9ae21f29.jpg)
    
    
    - LIFO (Last In First Out): 가장 마지막에 들어간 데이터가 가장 첫 번째로 나오는 구조
    - 웹 방문 기록 등에 주로 사용됨
    - 삽입, 삭제: O(1)
    - 탐색: O(n)
- 큐 (Queue)
    
    
    ![Queue](https://user-images.githubusercontent.com/111514410/222891520-9d4a11b2-272f-42ad-bab8-c085bb77bbf1.jpg)
    
    
    - FIFO (First In First Out): 먼저 집어넣은 데이터가 먼저 나오는 성질을 가진 구조
    - CPU 할당을 기다리는 프로세스,  선입선출이 필요한 대기열,  프로세스 관리, 캐시 등에 사용
- 답안
    
    선형 구조란 하나의 데이터 뒤에 한개의 데이터가 존재하는 자료구조로 대표적인 선형구조의 예로 배열, 연결리스트, 스택, 큐가 있다.
    
- 참고
    
    [[자료구조] 자료구조란?(선형구조, 비선형구조)](https://osy0907.tistory.com/84)
    
    [[CS노트] 자료 구조 - 선형 자료 구조](https://velog.io/@tanger2ne/CS노트-자료-구조-선형-자료-구조)
