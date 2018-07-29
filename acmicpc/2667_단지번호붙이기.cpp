#include <stdio.h>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n,result[26*26/2],map[26][26],visit[26][26];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int isOnMap(int y,int x){
	return x>=0 && x<n && y>=0 && y<n;
}

int bfs(int y, int x,int cnt){
	int ret=1;
	queue<pair<int,int> > que;
	que.push({y,x});
	while(!que.empty()){
		int y=que.front().first;
		int x=que.front().second;
		que.pop();
		for(int d=0; d<4; ++d){
			int nx=x+dx[d];
			int ny=y+dy[d];
			if(isOnMap(ny,nx) && !visit[ny][nx] && map[ny][nx]){
				visit[ny][nx]=cnt;
				que.push({ny,nx});
				ret++;
			}
		}
	}
	return ret;
}

int main(void){
	int cnt=1;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			scanf("%1d",&map[i][j]);
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(map[i][j] && !visit[i][j]){
				visit[i][j]=cnt;
				result[cnt]=bfs(i,j,cnt);
				cnt++;
			}
		}
	}
	printf("%d\n",cnt-1);
	sort(result+1,result+cnt);
	for(int i=1;i<cnt;++i){
		printf("%d\n",result[i]);
	}
	return 0;
}
