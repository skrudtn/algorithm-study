#include <stdio.h>
#include <queue>

using namespace std;

struct pos{
	int x;
	int y;
}typedef Pos;

int map[501][501];
int isVisit[501][501];
int dx[5] = {1,0,-1,0};
int dy[5] = {0,1,0,-1};
int n,m,cnt,vol;

int _max(int x, int y){
	return x>y?x:y;
}

bool isOnMap(int y, int x){
	return x>=0 && x<m && y>=0 && y<n;
}

void solve(void){
	queue <Pos>q;
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			if(map[i][j] && !isVisit[i][j]){
				cnt++;
				isVisit[i][j] = 1;
				Pos p1={.x=j, .y=i};
				q.push(p1);
				int v=0;
				while(!q.empty()){
					int x,y;
					x=q.front().x;
					y=q.front().y;
					q.pop();
					for(int d=0; d<4; ++d){
						int nx = dx[d]+x;
						int ny = dy[d]+y;
						
						if(isOnMap(ny,nx) && !isVisit[ny][nx] && map[ny][nx]){
							isVisit[ny][nx]=1;
							Pos p2 = {.x=nx, .y=ny};
							q.push(p2);
						}
					}
					v++;		
				}
				vol = _max(vol,v);
			}
		}
	}
	
	printf("%d\n%d",cnt,vol);
}

int main(void){
	scanf("%d%d",&n,&m);
	
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			scanf("%d",&map[i][j]);
		}
	}
	solve();
	
	return 0;
}
