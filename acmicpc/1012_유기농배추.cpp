#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n,m,k,map[51][51],visit[51][51];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int isOnMap(int y,int x){
	return x>=0 && x<m && y>=0 && y<n;
}

void bfs(int i,int j){
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
			if(map[ny][nx]){
				que.push({ny,nx});
				visit[ny][nx]=1;
			}
		}
	}
}

int main(void){
	int tc,ans;
	freopen("input.txt","r",stdin);
	cin>>tc;
	for(int t=1;t<=tc;++t){
		cin>>m>>n>>k;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				map[i][j]=0;
				visit[i][j]=0;
			}
		}
		ans=0;
		
		for(int i=0;i<k;++i){
			int a,b;
			cin>>a>>b;
			map[b][a]=1;
		}

		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				if(visit[i][j]) continue;
				if(map[i][j]) {
					bfs(i,j);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}

	return 0;
}
