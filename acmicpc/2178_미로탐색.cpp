#include <cstdio>
#include <queue>
#include <utility>

using namespace std;

int n,m,map[101][101],isVisit[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int isOnMap(int y,int x){
	return x>=0 && x<m && y>=0 && y<n;
}

int main(void){
	scanf("%d%d",&n,&m);
	for(int i=0; i<n;++i){
		for(int j=0; j<m; ++j){
			scanf("%1d",&map[i][j]);
		}
	}
	queue<pair<int,int> > que;
	que.push({0,0});
	isVisit[0][0]=1;
	
	while(!que.empty()){
		int y=que.front().first;
		int x=que.front().second;
		que.pop();
		if(x==m && y==n) break;
		for(int d=0; d<4; ++d){
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(isOnMap(ny,nx) && !isVisit[ny][nx] && map[ny][nx]){
				isVisit[ny][nx]=isVisit[y][x]+1;
				que.push({ny,nx});
			}
		}
	}
	printf("%d",isVisit[n-1][m-1]);
}
