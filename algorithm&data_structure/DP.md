# 동적 프로그래밍에 대해 설명하라

---
## 답안
> 복잡한 문제를 같단한 여러 개의 문제로 나누어 푸는 방법으로, 각 하위 문제의 해결을 계산한 뒤, 그 값을 저장한다. 이후 같은 하위 문제가 나왔을경우 저장한 값을 활용하여 문제를 해결하는 방식으로 부분 반복 문제와 최적 부분 구조를 가지고 있는 문제에 대해 성능향상을 목적으로 사용한다.
---



## 자료

### Dynamic Programing(동적 프로그래밍)
> 복잡한 문제를 간단한 여러 개의 하위 문제로 나누어 푸는 방법<br>
> 각 하위 문제의 해결을 계산한 뒤, 그 값을 `저장`하여, 후에 같은 하위 문제가 나왔을 경우 저장한 값을 활용해 문제를 해결한다.<br>
> 부분 반복 문제와 최적 부분 구조를 가지고 있는 알고리즘에 대해 성능향상을 목적으로 사용한다.

### 동적 프로그래밍의 조건
>   - 부분 반복 문제(Overlapping Subproblem) : 동일한 하위 문제들이 반복됨.<br>
>   - 최적 부분 구조(Optimal Substructure) : 큰 문제를 하위 문제로 나눌 수 있으며, 나눈 하위 문제의 답을 모아 큰 문제를 해결할 수 있음.

- Ex) fivo(7)을 구하는 과정
    ![fivo(7)](https://velog.velcdn.com/images%2Fgillog%2Fpost%2Feb96e602-b7bf-47eb-9c49-2eda8465e158%2F1231313133.png)
    > fivo(7)은 다음과 같이 분할 할 수 있으며, 위의 그래프에서 fivo(5), fivo(4), fivo(3) ... 가 반복됨을 볼 수 있다.
    ```c
    fivo(7) = fivo(6) + fivo(5);
    fivo(6) = fovo(5) + fivo(4);
    ...
    ```

### Memoization
> 프로그렘이 동일한 계산을 반복해야 할 때, 이전에 계산한 값을 메모리에 저장함으로써 동일한 계산의 반복 수행을 제거하여 프로그렘 전체 실행 속도를 빠르게 하는 기술. 동적 계획법의 핵심이 되는 기술이다.
> - Tabulation : Memoization과 같이 결과값을 저장하고 재활용한다는 점에서 개념적으로 큰 차이는 없으나 결과값을 저장하는 테이블을 index = 0부터 채워 나간다는 개념으로 `Bottom-up`방식에서는 Tabulation이라는 표현을 사용 한다. 추가적으로 반복물을 통해 테이블을 채워나가는 것을 table-filling이라 한다. 

### 구현 방식 : Top-down & Bottom-up
#### Top-down
- Memoization
- 재귀함수
- 점화식이 직관적
```c
int TD_table[MAX_TABLE_SIZE] = { 0, 1 };
int TopDownFivo(int n) {
	if (n < 2) { return n; }
	if (!TD_table[n]) {
		TD_table[n] = TopDownFivo(n - 1) + TopDownFivo(n - 2);
	}
	return TD_table[n];
}
```
#### Bottom-up
- Tabulation
- 반복문
- 함수 오버해드로 인한 성능저하가 없음
```c
int BU_table[MAX_TABLE_SIZE] = { 0, 1 };
int BottomUpFivo(int n) {
	if (n < 2) { return n; }
	if (BU_table[n]) { return BU_table[n]; }
	for (int i = 2; i <= n; i++) {
		if (!BU_table[i]) {
			BU_table[i] = BU_table[i - 1] + BU_table[i - 2];
		}
	}
	return BU_table[n];
}
```
---



## 꼬리질문

- DP의 조건

- Memoization

- Top-down, Bottom-up의 차이점

- 분할정복과의 공통점과 차이점
    - 두 알고리즘 "최적 부분 구조"를 가진 문제가 조건이며, 이러한 문제를 하위 문제로 분할하여 해결하는 방식을 가진다는 공통점을 가진다. 
    - 차이점은 DP의 경우 "부분 반복 문제" 조건을 충족하여 하위 문제의 값을 저장하여 이를 활용하는 Memoization을 활용한다. 이에반해 분할정복의 경우 위와 같은 조건을 만족하지 않으므로 모든 하위문제에 대해 값을 구하고 이를 병합하는 형태로 문제를 해결한다.
---



## Ref
https://ko.wikipedia.org/wiki/%EB%8F%99%EC%A0%81_%EA%B3%84%ED%9A%8D%EB%B2%95<br>
https://velog.io/@kimdukbae/%EB%8B%A4%EC%9D%B4%EB%82%98%EB%AF%B9-%ED%94%84%EB%A1%9C%EA%B7%B8%EB%9E%98%EB%B0%8D-Dynamic-Programming#%ED%83%91%EB%8B%A4%EC%9A%B4top-down-vs-%EB%B0%94%ED%85%80%EC%97%85bottom-up<br>
https://hongjw1938.tistory.com/47<br>


