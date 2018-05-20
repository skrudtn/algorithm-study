#include <iostream>
#include <queue>
#include <utility>
#include <math.h>

using namespace std;

int m,n;
bool isVisit[1001][1001];
int map[1001][1001];
int result;

int dx[] = {0,0,1,-1};
int dy[] = {1,-1,0,0};
queue<pair<int,int> > q;

bool isOnMap(int y, int x){
	return x>=0 && x<m && y>=0 && y<n;
}

void bfs(){

	while(!q.empty()){		
		int x,y;
		pair<int,int> p = q.front();
		q.pop();
		y = p.first;
		x = p.second;
		
		for(int d=0; d<4; d++){
			if(isOnMap(y+dy[d],x+dx[d]) && !isVisit[y+dy[d]][x+dx[d]] && map[y+dy[d]][x+dx[d]] != -1){
				map[y+dy[d]][x+dx[d]] = map[y][x]+1;
				result = max(result, map[y+dy[d]][x+dx[d]]);
				q.push(make_pair(y+dy[d], x+dx[d]));
				isVisit[y+dy[d]][x+dx[d]] = true;
			}
		}
		
	}
}

int getZeroNum(){
	int ret=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(map[i][j]==0)
				ret++;
		}
	}
	return ret;
}

int main(){
	cin>>m>>n;
	result = 0;
	
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			cin>>map[i][j];
			if(map[i][j]==1){
				q.push({i,j});
				isVisit[i][j] =true;
			}
		}
	}
	
	if(getZeroNum()==0){
		cout<<0<<endl;
		return 0;
	}
	
	bfs();

	if(getZeroNum()==0){
		cout<<result-1<<endl;
	} else{
		cout<<-1;
	}
}

/* 
 시간초과: 토마토가 있는 좌표를 모두다 큐에넣고 BFS를 시작하기. 
 메모리초과: 토마토의 사방에 있는 좌표로 진행할 때 미리 방문한다고 체크하고 들어가야 다른 좌표에서 접근하는 것을 막을 수 있음.  
*/
