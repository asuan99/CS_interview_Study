# 우선 순위 큐를 어떻게 구현할 수 있을까요? 가장 효율적인 방법은 무엇일까요?

- 자료조사
    
    ### 우선 순위 큐
    
    - 우선순위를 가진 데이터를 저장하는 큐
    - 우선순위가 높은 순서대로 삭제
    
    예) 운영체제의 작업 스케줄링
    
    ### 우선 순위 큐를 구현하는 방법
    
    ![우선순위큐](https://user-images.githubusercontent.com/99192837/222913808-53d0a44c-e83b-4014-8d0f-538c7361354f.png)
    
    - 배열(Array) / 연결리스트(List)
        - 구현이 비교적 간단하다.
        - 삽입, 삭제 연산의 시간복잡도가 높다.
    - 힙(Heap)
        - 구현이 비교적 복잡하다.
        - 삽입, 삭제 연산의 시간복잡도가 O(log2 n)으로 효율적이다.
    
    ### Heap
    
    - 최대 힙(Max Heap) :  최대 트리이면서 완전 이진 트리
    - 최소 힙(Min Heap) :  최소 트리이면서 완전 이진 트리
        
        ![힙](https://user-images.githubusercontent.com/99192837/222913833-9d360b68-48cd-4197-8ccc-9b6aaa1ca0da.jpg)
    
    - 최대 트리 : 부모 노드 ≥ 자식 노드
    - 최소 트리 : 부모 노드 ≤ 자식 노드
    - 완전 이진 트리
        - 마지막 레벨을 제외하고 모든 레벨이 채워진 형태
        - 마지막 레벨은 왼쪽부터 채워져야 한다.
    
    ### Max Heap - 삭제 연산 / 삽입 연산 구현
    
    Q. Heap은 일반적으로 배열을 사용하여 구현한다. 그 이유는?
    
    A. 완전 이진 트리이므로 배열로 구현이 가능하다.
    
    만일 연결 리스트로 구현할 경우, 왼쪽/오른쪽 자식 노드에 대한 포인터 정보를 저장해야 하므로 메모리를 더 많이 사용하게 된다.
    
    - 삽입 - O(log2 n)
        - 마지막 노드에 삽입
        - 마지막 노드에서 부모 노드와 비교해가며 트리 재구성
    
    ![최대 힙 - 삽입](https://user-images.githubusercontent.com/99192837/222913865-6a9b6be3-fe7b-4556-bf30-890d7bcbd4bc.png)
    
    - 삭제 - O(log2 n)
        - root에서만 삭제되며, 마지막 노드를 root로 변경
        - root에서 자식 노드와 비교해가며 트리 재구성
        
        ![최대 힙 - 삭제](https://user-images.githubusercontent.com/99192837/222913859-b9c47138-3e43-4028-b8dc-bd4088b4972c.png)
        
    
    ### Min Heap - 삭제 연산 / 삽입 연산 구현
    
    Max Heap에서 부등호 방향만 반대
    
- 답안
    
    우선 순위 큐는 배열, 연결 리스트, 힙을 통해 구현할 수 있습니다. 삽입, 삭제 연산을 할 때 배열과 연결 리스트의 경우 시간 복잡도가 O(n), 힙의 경우 시간 복잡도가 O(log2 n)입니다. 따라서 힙을 사용하여 우선 순위 큐를 구현하는 것이 가장 효율적입니다.
    
- 코드 예시
    
    ```java
    public class MaxHeap {
        private int[] heap;
        private int size;
        private int capacity;
    
        public MaxHeap(int capacity) {
            this.capacity = capacity;
            this.heap = new int[capacity];
            this.size = 0;
        }
    
        private int parent(int i) {
            return (i - 1) / 2;
        }
    
        private int leftChild(int i) {
            return 2 * i + 1;
        }
    
        private int rightChild(int i) {
            return 2 * i + 2;
        }
    
        private void swap(int i, int j) {
            int temp = heap[i];
            heap[i] = heap[j];
            heap[j] = temp;
        }
    
        public void insert(int value) {
            if (size >= capacity) {
                throw new IndexOutOfBoundsException("Heap is full");
            }
            heap[size] = value; // 마지막 노드에 삽입
            int current = size;
            size++;
            while (heap[current] > heap[parent(current)]) {
                swap(current, parent(current));
                current = parent(current);
            }
        }
    
        public int extractMax() {
            if (size <= 0) {
                throw new IndexOutOfBoundsException("Heap is empty");
            }
            int max = heap[0]; // root에서 삭제
            heap[0] = heap[size - 1]; // 마지막 노드를 root로 변경
            size--;
            heapify(0);
            return max;
        }
    
        private void heapify(int i) {
            int left = leftChild(i);
            int right = rightChild(i);
            int largest = i;
            if (left < size && heap[left] > heap[largest]) {
                largest = left;
            }
            if (right < size && heap[right] > heap[largest]) {
                largest = right;
            }
            if (largest != i) { // 트리 재구성을 해야한다면 swap
                swap(i, largest);
                heapify(largest);
            }
        }
    }
    ```
    
- 참고자료
    
    [이진 트리 구현 배열 vs 리스트](https://velog.io/@keum0821/이진-트리-구현-배열-vs-리스트)
    
    [Heap](https://medium.com/@jyw198908/heap-45bbad579e0c)
    