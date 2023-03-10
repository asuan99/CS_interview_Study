 
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
    3 7 8 9
