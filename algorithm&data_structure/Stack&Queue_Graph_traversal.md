# cs스터디 1주차

### 질문1. 스택과 큐의 공통점과 차이점

스택(Stack)은 리스트의 한쪽 끝에서 자료의 삽입과 삭제가 이루어지는 자료구조로, 가장 최근에 들어온 자료가 가장 먼저 나가게 되는 LIFO(Last-In First-Out / 후입선출) 형태로 DFS나 재귀함수를 구현할 때 사용됩니다.

따라서 배열과 비슷하지만 삽입, 삭제 등이 더 제한적으로 중간부분에서 데이터를 추가 및 삭제하는 것이 불가능하다는 특징을 갖고 있습니다.

사용되는 메소드로는 init(리스트를 초기화하는 함수), push (데이터 입력), pop(마지막 데이터 삭제), peak(마지막 데이터 반환), count(현재 리스트의 크기를 반환), isEmpty(현재 리스트의 크기가 비어있는지 체크) 가 있습니다.

활용 예시는 웹 브라우저 방문기록 (뒤로 가기), 역순 문자열 만들기, 실행 취소 (undo), 후위 표기법 계산 등이 있습니다.

여기서 후위 표기법이란? 연산자가 피연산자 뒤에 위치하는 표기법입니다. ex) *ABC*∗+

큐(Queue)는 한쪽에서는 추가, 다른 한쪽에서는 삭제가 이루어지는 자료구조로, 먼저 들어온 자료가 가장 먼저 나가는 FIFO(First - In - First - Out / 선입선출) 형태로 BFS나 캐시를 구현할 때 사용됩니다.

여기서 Cache란? 자주 사용하는 데이터나 값을 미리 복사해 놓는 임시 장소를 가리킵니다.

→ i-cache 명령어. d-cache 데이터. 순차적인 진행을 위해 선입선출.

→ 인터넷 상 cache 로그인상태 저장. 사용자 상태 유지. 일정 시간이 지나면 사라짐.

→ cache와 세션. 내가 지우기전까지 계속 유지되는 건 세션.  ex) 카톡, 넷플

사용되는 메소드로는 init(리스트를 초기화하는 함수), enqueue(데이터 입력), dequeue(첫번째 데이터 삭제), peak(첫번째 데이터 반환), removeAll(모든 데이터 삭제), count(현재 리스트의 크기를 반환), capacity(리스트의 최대 허용 공간 크기를 반환), isFull(리스트가 모두 찼는지 체크), isEmpty(현재 리스트의 크기가 비어있는지 체크) 가 있습니다.

활용 예시는 은행 업무, 콜센터 고객 대기시간, 프로세스 관리 등이 있습니다.

**질문 답변**

**삽입, 삭제의 위치와 방법이 제한되어있는 유한 순서 리스트 형태의 자료구조라는 공통점을 가지고 있습니다.**

**같은 유한 순서 리스트 형태라도 스택은 LIFO 즉, 늦게 들어온 자료가 먼저 나가게 되는 후입선출구조이고, 큐는 FIFO 즉, 먼저 들어온 자료가 먼저 나가게 되는 선입선출 구조입니다. 따라서 가장 큰 차이점으로 자료를 삭제할 때입니다. Stack은 가장 마지막에 추가되 있던 자료를 삭제하고, Queue는 가장 처음으로 들어와 있던 자료를 삭제합니다.**

---

### 질문2. DFS 와 BFS 는 어떤 경우에 사용할까?

DFS(깊이 우선 탐색)와 BFS(너비 우선 탐색)는 그래프 탐색 알고리즘입니다. 

DFS는 깊이 우선 탐색이라고 부르며, 그래프에서 하나씩 타고 들어가보면서 깊은 부분을 우선적으로 탐색하는 알고리즘으로 스택 자료구조(혹은 재귀함수)를 이용하여 구현합니다.

BFS는 너비 우선 탐색이라고도 부르며, 그래프에서 가까운 노드부터 우선적으로 탐색하는 알고리즘으로 큐 자료구조를 이용하여 구현합니다.

**질문 답변**

**DFS는 모든 노드를 방문하고자 하는 경우에 주로 사용하고, ex) 미로찾기.** 

**BFS는 두 노드 사이의 최단거리, 최소비용 경로를 찾고자 하는 경우에 주로 사용합니다. ex) 최단거리**
**깊이 우선 탐색(DFS)이 너비 우선 탐색(BFS)보다 좀 더 간단하고, 단순 검색 속도 자체는 재귀함수를 사용하지 않는 너비 우선 탐색(BFS)이 더 빨라 이에 맞는 상황에 따라 둘 다 사용할 수 있지만 효율적인 방법을 골라서 사용할 수 있습니다.** 

BFS & DFS 코드

```java
import java.util.ArrayList;

public class Test {
	static int xy[][]= {{0,1},{1,0},{-1,0},{0,-1}}; // 상하좌우 이동
	static int result[][]=new int[7][7]; // check와 결과 map
	static int count[]=new int[7*7]; // 분리된 공간 크기
	public static void main(String[] args) {
		int map[][]= {{0,1,1,0,1,0,0}, // map 
									{0,1,1,0,1,0,1},
									{1,1,1,0,1,0,1},
									{0,0,0,0,1,1,1},
									{0,1,0,0,0,0,0},
									{0,1,1,1,1,1,0},
									{0,1,1,1,0,0,0}};
		int cnt=0; // 분리된 공간 수

		for(int i=0;i<7;i++) {
			for(int j=0;j<7;j++) {
			// map크기만큼 반복문
				if(map[i][j]==1) {
				// 1인 부분 찾기
					if(result[i][j]==0) {
					// 지나가지 않은 부분인지 확인
						cnt++; // 나누어진 공간 몇개인지 확인하기 위해 count
//						dfs(map,i,j,cnt);
						bfs(map,i,j,cnt);
					}
				}
			}
		}
		// 출력
		for(int i=0;i<7;i++) {
			for(int j=0;j<7;j++) {
				System.out.print(result[i][j]);
			}
			System.out.println();
			}
		System.out.println(cnt);
		for(int i=0;i<cnt;i++) {
			System.out.println(count[i]);
		}
	}
	static void dfs(int map[][],int x,int y,int cnt) {
		if(x<0 || y<0 || x>=7 || y>=7) {
			// 지도 범위 밖을 벗어나지 않는지 확인
			return;
		}
		if(map[x][y]==0) {
			// 지도상으로 갈 수 있는 길인지 확인
			return;
		}
		if(result[x][y]!=0) {
				// 이미 지나간 길인지 확인
			return;
		}
		
		result[x][y]=cnt; // 지나간 길 check
		count[cnt-1]++; // 구역별 공간 크기 count
		for(int i=0;i<4;i++) {
			// 상하좌우로 방문
			dfs(map,x+xy[i][0],y+xy[i][1],cnt);
		}
		
	}
	static void bfs(int map[][],int sx,int sy,int cnt) {
		ArrayList<int []> q = new ArrayList<>(); // queue 공간
		q.add(new int[] {sx,sy}); // 첫 경로 삽입
		result[sx][sy]=cnt; //지나간 길 check
		count[cnt-1]++; // 구역별 공간 크기 count
		while(!q.isEmpty()) { //queue에 아무것도 없을때까지 반복
			int curx = q.get(0)[0]; // queue의 0번째 x값 담음
			int cury = q.get(0)[1]; // queue의 0번째 x값 담음
			q.remove(0); //queue 내부 0번째 값 삭제
			
			for(int i=0;i<4;i++) {
				// 상하좌우로 방문
				int x=curx+xy[i][0];
				int y=cury+xy[i][1];
				if(x>=0 && y>=0 && x<7 && y<7) {
				// 지도 범위 밖을 벗어나지 않는지 확인
					if(result[x][y]==0 && map[x][y]==1) {
					// 지도상으로 갈 수 있는 길인지, 이미 지나간 길인지 확인
						q.add(new int[] {x,y}); // 경로 삽입
						result[x][y]=cnt; // 지나간 길 check
						count[cnt-1]++; // 구역별 공간 크기 count
					}
				}
			}
		}
		
	}
}
```

result
0110200
0110202
1110202
0000222
0300000
0333330
0333000
구역 수: 3 
구역별 공간 크기
7 8 9
