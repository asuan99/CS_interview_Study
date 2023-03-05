# Dijkstra 알고리즘과 Bellman-Ford 알고리즘의 차이점을 설명하시오.

- 자료조사
    
    ### Dijkstra 알고리즘
    
    ![1](https://user-images.githubusercontent.com/99192837/222913975-50578ad9-ff60-4acd-a31b-6c92a3b08480.png)

    출발 노드를 1로 설정해보자.
    
    ![2](https://user-images.githubusercontent.com/99192837/222913932-d7a706e4-5bf4-47a1-a271-41163f3486f5.png)
    
    1에서 갈 수 있는 가장 짧은 경로는 4로 가는 경로이다.
    
    1에서 4로 가는 최단 거리는 7로 결정되었다.
    
    ![3](https://user-images.githubusercontent.com/99192837/222913939-124e106e-db60-449a-b5b7-8e17d89382b4.png)
    
    3으로 갈 수 있는 경로는 다음 두 가지이다.
    
    **1→ 3** = 9,
    
    **1→ 4 → 3** = 7+10
    
    ![4](https://user-images.githubusercontent.com/99192837/222913941-b97f88d3-4fe6-49a9-a78f-ab87054eaa76.png)
    
    더 짧은 경로를 선택하자.
    
    1에서 3으로 가는 최단 거리는 9로 결정되었다. 
    
    ![5](https://user-images.githubusercontent.com/99192837/222913942-b7afad20-e31c-48c9-9de3-60005c8443b9.png)
    
    2로 갈 수 있는 경로는 다음 2가지이다.
    
    **1 → 2** = 14
    
    **1 → 3 → 2** = 9 + 2
    
    ![6](https://user-images.githubusercontent.com/99192837/222913943-065a4f39-cf50-47fd-b779-7431a6437f5f.png)
    
    더 짧은 경로를 선택하자.
    
    1에서 2로 가는 최단 거리는 11로 결정되었다. 
    
    ![7](https://user-images.githubusercontent.com/99192837/222913944-30f95d73-9067-4a83-88ae-0012ca00bccc.png)
    
    5로 갈 수 있는 경로는 다음 1가지이다.
    
    **1 → 3 → 2 → 5** = 11 + 9
    
    ![8](https://user-images.githubusercontent.com/99192837/222913945-9765bbda-01a4-449c-bb41-bde217bb9a50.png)
    
    1에서 5로 가는 최단 거리는 20으로 결정되었다. 
    
    ![9](https://user-images.githubusercontent.com/99192837/222913946-2f5f2233-c2d1-4ae7-9a7f-a151e0aa15f2.png)
    
    6으로 갈 수 있는 경로는 다음 3가지이다.
    
    **1 → 3 → 2 → 5 → 6**= 20 + 6
    
    **1 → 3 → 6**= 9 + 11
    
    **1 → 4 → 6**= 7+ 15
    
    ![10](https://user-images.githubusercontent.com/99192837/222913923-ff6f5264-92be-4265-b53a-d563c122fe2e.png)
    
    1에서 6으로 가는 최단 거리는 20으로 결정되었다. 
    
    ### Dijkstra 알고리즘의 한계
    
    ![0](https://user-images.githubusercontent.com/99192837/222913917-22e40250-bc2c-4436-be88-f8ea8825001c.png)
    
    Q. 만일 3과 4를 사이 가중치가 -10이라면 어떻게 될까?
    
    ![2 1](https://user-images.githubusercontent.com/99192837/222913930-8a70fe5a-a7cf-4e47-a3ff-2346bd2f88f0.png)
    
    <Dijkstra 알고리즘에서 최단 거리>
    
    ![2 2](https://user-images.githubusercontent.com/99192837/222913931-38fffaab-6fbd-454d-8d37-6ae79cd7aa59.png)
    
    <직관적인 관점에서 최단 거리>
    
    A. 음의 가중치가 있는 경우, Dijkstra 알고리즘으로 최단 거리를 구할 수 없다.
    
    이 경우 Bellman-Ford 알고리즘으로 최단 거리를 구할 수 있다.
    
    Dijkstra은 Greedy 알고리즘(탐욕적인 알고리즘)이다.
    
    미래를 생각하지 않고 각 단계에서 최선의 선택을 하는 것이다.
    
    ### Bellman-Ford 알고리즘
    
    1. 시작 정점을 결정한다.
    2. 시작 정점부터 다른 정점까지 거리 값 모두 무한대로 초기화한다. (시작 정점은 0으로 초기화)
    3. 현재 정점의 모든 인접 정점들을 탐색하며, 기존에 기록된 인접 정점까지의 거리보다 현재 정점을 거쳐 인접 정점에 도달하는 거리가 더 짧다면 인접 정점까지의 거리를 갱신한다.
    4. 3번 과정을 *V*−1번 반복한다.
    5. 위 과정을 모두 마친 후에도 거리가 갱신되는 경우가 있다면 그래프에 음수 사이클이 존재한다는 것을 알 수 있다.
    
    ![3 1](https://user-images.githubusercontent.com/99192837/222913934-406248d4-bb25-42a5-96f9-70d43e040dbe.jpg)
    
    출발 노드를 1로 설정해보자.
    
    | 0 | ∞ | ∞ | ∞ | ∞ |
    | --- | --- | --- | --- | --- |
    
    노드의 개수 길이로 배열을 초기화한다.
    
    | 0 | -4 | 5 | 2 | 3 |
    | --- | --- | --- | --- | --- |
    
    출발 노드부터 갈 수 있는 경로를 조사한다.
    
    그 다음으로
    
    2번 노드를 거쳐서 갈 수 있는 최단 거리
    
    3번 노드를 거쳐서 갈 수 있는 최단 거리
    
    4번 노드를 거쳐서 갈 수 있는 최단 거리
    
    5번 노드를 거쳐서 갈 수 있는 최단 거리를 구해보자.
    
    ![3 2](https://user-images.githubusercontent.com/99192837/222913935-e1d74e8f-6376-4607-bf7a-4df3a857d563.png)
    
    | 0 | -4 | 5 | -5 | 3 |
    | --- | --- | --- | --- | --- |
    
    **1→ 4** = 2
    
    **1→ 2 → 4** = -4 + -1
    
    2번 노드를 거쳐서 갈 수 있는 최단 거리
    
    ![3 3](https://user-images.githubusercontent.com/99192837/222913936-cf77ede5-2083-46c9-8d04-e4c8bfa20258.png)
    
    | 0 | -4 | 5 | -5 | 3 |
    | --- | --- | --- | --- | --- |
    
    **1→ 4** = -5
    
    **1→ 3 → 4** = 5 + -7
    
    3번 노드를 거쳐서 갈 수 있는 최단 거리
    
    ![3 4](https://user-images.githubusercontent.com/99192837/222913937-b896fdf4-d75b-4fd6-b14b-f7f97640164d.png)
    
    | 0 | -4 | 5 | -5 | 1 |
    | --- | --- | --- | --- | --- |
    
    **1→ 5** = 3
    
    **1→ 4 → 5** = -5 + 6
    
    4번 노드를 거쳐서 갈 수 있는 최단 거리
    
    ![3 5](https://user-images.githubusercontent.com/99192837/222913938-a3d1e001-6ef5-428d-bb9f-3b6c829c0af4.png)
    
    | 0 | -4 | 5 | -5 | 1 |
    | --- | --- | --- | --- | --- |
    
    **1→ 4** = -5
    
    **1→ 5 → 4** = 3 + -4
    
    5번 노드를 거쳐서 갈 수 있는 최단 거리
    
    ### Bellman-Ford 알고리즘 - 음의 사이클 찾는 방법
    
    한 노드에서 다른 한 노드까지 도달하는 데, 최대 V-1만큼의 간선이 사용된다.
    
    즉, V 이상의 간선이 중간 경로로 사용된다면 사이클이 존재하는 것이다.
    
    Bellman-Ford 알고리즘에서 각 노드를 중간 경로로 하여 최단 경로를 찾는 과정을 V번 이상 반복하였을 때 경로가 업데이트 된다면, 사이클이 존재하는 것이다.
    
- 답안
    
    Dijkstra 알고리즘과 Bellman-Ford 알고리즘은 한 정점에서 다른 모든 정점까지의 최단 거리를 구하는 알고리즘입니다. 음의 가중치가 존재할 경우 Dijkstra 알고리즘은 최단 거리를 구할 수 없으나, Bellman-Ford 알고리즘은 최단 거리를 구할 수 있습니다. 다만, Bellman-Ford 알고리즘이 Dijkstra 알고리즘 보다 시간복잡도가 크기 때문에 양의 가중치만 존재하는 경우 Dijkstra 알고리즘을 사용하는 것이 효율적입니다.
    
- 참고자료
    
    [데이크스트라 알고리즘](https://ko.wikipedia.org/wiki/데이크스트라_알고리즘)
    
    [[Algorithm] 벨만포드(BellmanFord) 알고리즘 JAVA](https://developer-davii.tistory.com/m/89)
    
    [최단경로 - (2) 벨만-포드(Bellman-Ford) 알고리즘](https://velog.io/@adorno10/최단경로-2-벨만-포드Bellman-Ford-알고리즘)
