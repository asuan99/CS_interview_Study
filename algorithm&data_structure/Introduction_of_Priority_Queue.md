# 우선순위 큐(Priority Queue)

# PriorityQueue란 무엇이며 동작 원리가 어떻게 되나요

- 우선순위 큐
    - 우선순위를 가진 데이터들을 저장하는 큐(Queue)
    - 데이터를 꺼낼 때 우선순위가 높은 데이터가 가장 먼저 나옴
    
    ![Queue & Priority_Queue](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Queue%20%26%20Priority_Queue.png)
    
    - 일반적인 큐 vs 우선순위 큐
        - 일반적인 큐: 선형 구조
        - 우선순위 큐: 트리 구조, 최대 힙(Max Heap)을 이용
- 완전 이진트리
    
    ![Complete_Binary_tree](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Complete_binary_tree.png)
    
    - 마지막 레벨을 제외 하고 모든 레벨이 완전히 채워져 있어야 함
    - 노드가 왼쪽에서 오른쪽으로 채워져야 함
- 최대 힙 (Max Heap)
    
    ![Max_Heap](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Max_Heap.png)
    
    ![Not_Max_Heap](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Not_Max_Heap.png)
    
    - 부모 노드가 자식 노드보다 값이 큰 완전 이진트리
    - 루트 노드는 전체 트리에서 가장 큰 값을 가짐
- 동작 구조
    - 삽입
        
        ![Max_Heap_Insert_Ex_01](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Max_Heap_Insert_Ex_01.png)
        
        ![Max_Heap_Insert_Ex_02](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Max_Heap_Insert_Ex_02.png)
        
        ![Max_Heap_Insert_Ex_03](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Max_Heap_Insert_Ex_03.png)
        
        ![Max_Heap_Insert_Ex_04](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Max_Heap_Insert_Ex_04.png)
        
    - 삭제
        
        ![Max_Heap_Delete_Ex_01](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Max_Heap_Delete_Ex_01.png)
        
        ![Max_Heap_Delete_Ex_02](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Max_Heap_Delete_Ex_01.png)
        
        ![Max_Heap_Delete_Ex_03](https://github.com/WooJJam/CS_interview_Study/blob/main/algorithm%26data_structure/img/Max_Heap_Delete_Ex_01.png)
        
- 답안
    - 우선순위 큐는 가장 우선순위가 높은 데이터를 먼저 꺼내기 위한 자료구조이며 완전이진트리를 이용한 힙을 사용하여 구현한다. 힙은 모든 정점이 자신의 자식요소보다 우선순위가 높다는 성질을 가지고 있다. 이 성질을 이용하여 O(logN)의 시간으로 삽입과 삭제연산을 수행할 수 있다.
- 질문
    1. Min Heap으로 구현할 수 있나요?
        
        → Min Heap도 상관은 없으나 숫자가 적은게 우선순위가 높다고 가정하여야 함
        
- 참고자료
    
    [[자료구조] 트리(Tree)의 개념 | 이진 트리,  전 이진 트리, 완전 이진트리, 포화 이진 트리, 이진 탐색트리](https://code-lab1.tistory.com/8)
    
    [🌈 자료구조:: 우선순위 큐(Priority Queue)](https://velog.io/@april_5/자료구조-우선순위-큐Priority-Queue)
