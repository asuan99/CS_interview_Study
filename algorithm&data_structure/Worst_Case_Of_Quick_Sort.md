# Quick Sort를 사용할 때 최악의 경우는 무엇일까?

- 자료조사
    
    ### Quick Sort
    
    - pivot을 기준으로 작은 값은 왼쪽, 큰 값은 오른쪽 서브파일로 분해시키는 방식으로 정렬
    
    ![Quick_Sort_01](https://user-images.githubusercontent.com/99192837/224106068-b336c67b-52a6-46ee-b25a-1df498767922.jpeg)
    ![Quick_Sort_02](https://user-images.githubusercontent.com/99192837/224106152-d851c4f8-7188-4e00-b477-24d3bcdecb4c.jpeg)
    ![Quick_Sort_03](https://user-images.githubusercontent.com/99192837/224106189-81ba7fa7-b737-45bd-80c0-898bee57ebfb.jpeg)
    ![Quick_Sort_04](https://user-images.githubusercontent.com/99192837/224106221-340846cb-0a84-4de4-8d0e-92fbac06eba7.jpeg)s
    
    ### Quick Sort의 특징
    
    - 위치에 관계없이 임의의 pivot을 분할 원소로 사용할 수 있다.
    - 정렬 방식 중에서 가장 빠른 방식이다.
    - 분할 정복법(Divide and Conquer)을 통해 자료를 정렬한다.
        - 분할: 기준값인 pivot을 중심으로 정렬할 자료들을 2개의 부분집합으로 나눈다.
        - 정복: 부분집합의 원소들 중 pivot보다 작은 원소들은 왼쪽, pivot보다 큰 원소들은 오른쪽 부분집합으로 정렬한다.
    - 평균 수행 시간 복잡도는 O(NlogN)이고, 최악의 수행 시간 복잡도는 O(n^2)이다.
    
- 답안
    
    Quick Sort는 정렬된 순서로 pivot을 택했을 때 최악의 복잡도를 가지게 됩니다. Quick Sort는 pivot을 택한 뒤, pivot을 기준으로 좌우로 분해시키는 방식입니다. 만일 이미 정렬되어 있는 배열에서 가장 앞에 있는 원소를 pivot으로 택한다면, 좌우로 골고루 분배되지 않게 됩니다. 정렬이 계속되어도 분해되는 배열의 크기는 크게 줄지 않게 되는데, 이는 좌우로 분해하기 위해 비교해야하는 원소의 수가 크게 줄지 않는다는 의미입니다. 이 경우 O(n)만큼 연산을 수행하기 때문에 최종적으로 O(n^2)의 시간 복잡도를 가지게 됩니다.
    
    그러나, 정렬된 순서로 pivot을 택하는 경우는 드물기 때문에 Quick Sort는 평균적으로 O(nlogn)의 시간 복잡도를 가진다고 보통 말합니다.
    
- 참고자료
    
    2023 시나공 정보처리기사 필기, 길벗
    
    [[자료구조 알고리즘] 퀵정렬(Quicksort)에 대해 알아보고 자바로 구현하기](https://www.youtube.com/watch?v=7BDzle2n47c&t=139s)
