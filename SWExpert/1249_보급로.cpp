#include <stdio.h>
#include <queue>
#include <utility>

using namespace std;

int n,map[100][100],cost[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int isOnMap(int y,int x){
	return y>=0 && y<n && x>=0 && x<n;
}

int main(void){
	int tc,ans;
	scanf("%d",&tc);
	for(int t=1;t<=tc;++t){
		ans=0;
		scanf("%d",&n);
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				scanf(" %1d",&map[i][j]);
				cost[i][j] = 0x7fffffff;
			}
		}
		queue<pair<int,int> > que;
		que.push({0,0});
		cost[0][0]=0;
		
		while(!que.empty()){
			int cy=que.front().first;
			int cx=que.front().second;
			que.pop();
			for(int d=0;d<4;++d){
				int nx=dx[d]+cx;
				int ny=dy[d]+cy;
				if(!isOnMap(ny,nx)) {
					continue;
				}
				if(cost[cy][cx] + map[ny][nx] < cost[ny][nx]){
					que.push({ny,nx});
					cost[ny][nx] = cost[cy][cx] + map[ny][nx];
				}
			}
			
		}
		ans = cost[n-1][n-1];
		printf("#%d %d\n",t,ans);
	}
	
	return 0;
}
