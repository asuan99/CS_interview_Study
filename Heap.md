# 힙(heap)

### 1. 힙(heap)에 대해 설명하시오
- 답변
        
        완전 이진 트리의 일종으로 우선순위 큐를 위해 만들어진 자료구조입니다.
        
        힙을 이용하여 우선순위 큐를 구현하면 데이터를 삽입, 삭제하는데 log n의 시간이 걸리며, 여러 개의 값들 중에서 최댓값이나 최솟값을 빠르게 찾아낼 수 있는 자료구조 입니다.
        
- 힙(heap)
        
        완전 이진 트리의 일종, 우선순위 큐를 위해 만들어진 자료구조
        
    - 우선순위 큐
            
            우선순위에 따라 원소를 삽입하고 제거할 수 있는 자료구조
            
            각 원소는 우선순위와 함께 연관되어 있으며, 우선순위가 높은 원소가 낮은 우선순위를 가진 원소보다 먼저 제거됨
            
    - 트리
        - 이진 트리(binary tree)
                
            모든 노드들이 2개의 서브트리를 갖는 특별한 형태의 트리
                
            각 노드가 자식노드를 최대한 2개까지만 가질 수 있다.
                
        - 이진 탐색 트리(binary search tree)
                
            ![binary_search_tree](https://user-images.githubusercontent.com/88701965/224234894-efaddd8c-ad9d-460a-aecf-8a2965640450.png)
                
            left child: 부모 노드의 데이터보다 값이 작아야함
                
            right child: 부모 노드의 데이터보다 값이 커야함
                
            중위순회(inorder travel)를 적용하면 오름차순 정렬이 된다.
                
        - 완전 이진 트리(complete binary tree)
                
            ![complete binary tree](https://user-images.githubusercontent.com/88701965/224234902-844a80e3-5e00-4dd3-bfb2-1d4388a75410.png)
                
            이진 트리의 일종
                
            모든 노드가 왼쪽에서 오른쪽으로 빠짐없이 채워져 있으며, 마지막 레벨을 제외한 모든 레벨이 꽉 차 있는 트리 구조
                
            마지막 레벨은 왼쪽부터 차례로 노드가 채워져 있다.
                
        
        - heap의 종류
            - 최대 힙(max heap)
                
                부모 노드의 키값 ≥ 자식 노드의 키값
                
                큰 값을 가진 element가 우선순위 위에 위치
                
            - 최소 힙(min heap)
                
                부모 노드의 키 값 ≤ 자식 노드의 키 값
                
                작은 값을 가진 element가 우선순위 위에 위치
                
            
            ![max min_heap](https://user-images.githubusercontent.com/88701965/224234931-d9e6c4bc-1825-4937-98d0-269b6498fac0.png)
            
        - heap의 특징
            - 최대값과 최소값을 O(1)의 속도로 구할 수 있다 → 반정렬 구조
            - 힙을 저장하는 표준적인 자료구조는 배열
            - 구현을 쉽게 하기 위해서 인덱스 1부터 시작한다
            - 특정 위치의 노드 번호는 새로운 노드가 추가되어도 변하지 않는다. (ex. 루트 노트(1)의 오른쪽 노드 번호는 항상 3)
            - 인덱스
                
                ```python
                왼쪽 자식 index = (부모 index) * 2
                오른쪽 자식 index = (부모 index) * 2 + 1
                부모 index = (자식 index) / 2
                ```
                
            
            ![heap_index](https://user-images.githubusercontent.com/88701965/224234971-30175a06-824d-4bfe-b862-32452dcf88a6.png)
            
        - 삽입 / 삭제 연산
            - Max Heap - O(logn)
                - 삽입
                    1. 데이터를 일단 맨 마지막 인덱스에 추가한다.
                    2. 부모 노드와 비교하여 부모 노드보다 작다면 그대로 두고
                    3. 부모 노드보다 크다면, 부모 노드와 위치를 바꿔준다.
                    
                    ![heap_insert_1](https://user-images.githubusercontent.com/88701965/224234988-c26115e6-ec6b-4b43-9afe-a084927334b7.png)
                    
                    ![heap_insert_2](https://user-images.githubusercontent.com/88701965/224234993-b1527c85-b25e-44b7-98e6-9998ebc88d39.png)
                    
                - 삭제
                    1. root 노드를 삭제한다.
                    2. root 노드의 자리에 맨 마지막 노드를 가져온다.
                    3. heap을 재구성한다. (만약 자식 노드보다 크다면 그대로 두고, 작다면 자식노드와 값을 바꾼다.)
                    
                    ![heap_delete_2](https://user-images.githubusercontent.com/88701965/224234999-f79695d0-ab21-45af-9529-9845ecb8cf51.png)

                    ![heap_delete_1](https://user-images.githubusercontent.com/88701965/224235003-1a3d0085-6939-41ed-a006-16e7d8543fce.png)
                    
            - Min Heap
                
                Max Heap에서 부등호 방향 반대
            

- 참고자료
    
    [[자료구조] Heap(힙) - 개념, 종류,  활용 예시, 구현](https://velog.io/@yanghl98/자료구조-Heap힙-개념-종류-활용-예시-구현)
    
    [[자료구조] 트리와 힙](https://velog.io/@humblechoi/자료구조-트리와-힙)
    
    [[자료구조] 이진 트리와 이진 탐색 트리 (BST: Binary Search Tree)](https://velog.io/@yeonkr/자료구조-이진-트리와-이진-탐색-트리-BST-Binary-Search-Tree)