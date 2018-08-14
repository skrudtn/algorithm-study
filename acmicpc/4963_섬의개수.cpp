#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n,m,map[51][51],visit[51][51];
int dx[8]={1,1,0,-1,-1,-1,0,1};
int dy[8]={0,1,1,1,0,-1,-1,-1};

int isOnMap(int y,int x){
	return x>0 && x<=m && y>0 && y<=n;
}

void bfs(int y,int x){
	queue<pair<int,int> > que;
	que.push({y,x});
	visit[y][x]=1;
	while(!que.empty()){
		int cy=que.front().first;
		int cx=que.front().second;
		que.pop();
		
		for(int d=0;d<8;++d){
			int nx=dx[d]+cx;
			int ny=dy[d]+cy;
			if(!isOnMap(ny,nx)) continue;
			if(visit[ny][nx]) continue;
			if(map[ny][nx]){
				visit[ny][nx]=1;
				que.push({ny,nx});
			}
		}	
	}
	
}

void init(){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			visit[i][j]=0;
		}
	}
}

int solve(){
	int ret=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			if(visit[i][j]) continue;
			if(map[i][j]==1){
				bfs(i,j);
				ret++;
			}
		}
	}
	return ret;
}


int main(void){
	for(;;){
		cin>>m>>n;
		if(m==0 && n==0) break;
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				cin>>map[i][j];
			}
		}
		init();
		cout<<solve()<<endl;
	}
	
	return 0;
}
