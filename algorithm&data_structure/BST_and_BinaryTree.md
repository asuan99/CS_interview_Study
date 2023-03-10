# BST(Binary Search Tree)와 Binary Tree에 대해서 설명해주세요.

- **자료 조사**
    - **트리(Tree)**
        
        계층적 구조의 자료를 표현할 때 사용하는 비선형 자료구조
        
        정의
        
        - 하나 이상의 노드로 이루어진 유한집합
        - Root라고 하는 노드가 하나 존재
        
        ![Tree](https://user-images.githubusercontent.com/44726494/222750488-cb61fec1-cbc9-4860-9fe5-e25c4a5d3fe4.png)
        
    - **이진 탐색(Binary Search)**
        
        데이터가 정렬되어 있는 배열에서 특정한 값을 찾아내는 알고리즘이다. 배열의 중간에 있는 임의의 값을 선택하여 찾고자 하는 key 값과 비교한다. key 값이 중간 값보다 작으면 중간 값을 기준으로 좌측의 데이터들을 대상으로, key 값이 중간 값보다 크다면 배열의 우측을 대상으로 다시 탐색한다. 동일한 방법으로 중간의 값을 임의로 선택하여 비교한다. 해당 값을 찾을 때까지 이 과정을 반복한다.
        
    - **이진 트리(Binary Tree)**
        
        특징
        - 모든 노드의 차수(degree)는 2를 넘지 않는다.
        - 왼쪽 서브트리와 오른쪽 서브트리가 구분
        
        정의        
        - 유한 개의 노드들의 집합으로서 노드 수는 0이 될 수 있으며, 하나의 root 노드와 왼쪽 서브트리, 그리고 오른쪽 서브트리로 구성
        
        
        ![Binary_tree](https://user-images.githubusercontent.com/44726494/222750531-dfd7d6fa-2837-4d3f-8b3e-19c7f2831d61.png)
        
    - **이진 탐색 트리(Binary Search Tree)**
        
        트리 내에서 특정 데이터(키 값)를 효율적으로 찾도록 하는 트리
        
        정의
        
        - 모든 노드는 유일한 키 값을 가진다.
        - 왼쪽 서브트리에 저장된 키 값 < Root node의 키 값
        - 오른쪽 서브트리에 저장된 키 값 > Root node의 키 값
        
        ![Binary_search_tree](https://user-images.githubusercontent.com/44726494/222750634-39a87b35-8502-4b71-8cdf-f9cd8b2ba8b0.png)

- **답안**
    
    이진 트리는 각각의 노드가 최대 2개의 자식 노드를 가지는 계층적 구조를 가지는 비선형 자료구조로, 자식 노드를 각각 왼쪽 자식 노드와 오른쪽 자식 노드라고 한다. 이진 탐색 트리는 이진 탐색과 연결 리스트를 결합한 자료구조이다. 이진 탐색의 효율적인 탐색 능력을 유지하면서, 빈번한 자료 입력과 삭제가 가능하다는 장점이 있다. 이진 탐색 트리는 왼쪽 트리의 모든 값이 반드시 부모 노드보다 작아야 하고, 반대로 오른쪽 트리의 모든 값이 부모 노드보다 커야 하는 특징을 가지고 있어야 한다.
    
- **참고 자료**
    - 자료구조 수업 - 조행래
    - 위키피디아 ([Tree](https://en.wikipedia.org/wiki/Tree_(data_structure)), [Binary tree](https://en.wikipedia.org/wiki/Binary_tree), [Binary search tree](https://en.wikipedia.org/wiki/Binary_search_tree))
    - [FE 면접 질문 (자료구조)](https://devowen.com/285)
