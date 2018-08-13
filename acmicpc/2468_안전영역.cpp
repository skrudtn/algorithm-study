#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int n,map[101][101],visit[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int _max(int a,int b){return a>b?a:b;}
int _min(int a,int b){return a<b?a:b;}

int isOnMap(int y,int x){
	return x>0 && x<=n && y>0 && y<=n;
}

void bfs(int i,int j,int h){
	queue<pair<int,int> > que;
	que.push({i,j});
	visit[i][j]=1;
	
	while(!que.empty()){
		int y=que.front().first;
		int x=que.front().second;
		que.pop();
		for(int d=0;d<4;++d){
			int nx=dx[d]+x;
			int ny=dy[d]+y;
			if(!isOnMap(ny,nx)) continue;
			if(visit[ny][nx]) continue;
			if(map[ny][nx]>h){
				que.push({ny,nx});
				visit[ny][nx]=1;
			}
		}

	}
}

int main(void){
	int m,M,ans,cnt;
	M=cnt=0;
	ans=1;
	m=0x1c1c1c1c;
	cin>>n;
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>map[i][j];
			M=_max(M,map[i][j]);
			m=_min(m,map[i][j]);
		}
	}
	
	for(int h=m;h<M;++h){
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				visit[i][j]=0;
			}
		}
		cnt=0;

		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				if(visit[i][j]) continue;
				if(map[i][j]>h){
					bfs(i,j,h);
					cnt++;
				}
			}
		}
		ans=_max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
