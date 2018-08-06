#include <iostream>

using namespace std;

int ans,n,m,map[501][501],visit[501][501];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int _max(int a,int b){return a>b?a:b;}
int _min(int a,int b){return a<b?a:b;}

int isOnMap(int y,int x){
	return x>=0 && x<m && y>=0 &&y<n;
}

void dfs(int y, int x,int cnt,int val){
	if(cnt==4){
		ans=_max(ans,val);
		return;
	}
	
	for(int d=0;d<4;++d){
		int nx=dx[d]+x;
		int ny=dy[d]+y;
		if(!isOnMap(ny,nx)) continue;
		if(visit[ny][nx]) continue;
		visit[ny][nx]=1;
		dfs(ny,nx,cnt+1,val+map[ny][nx]);
		visit[ny][nx]=0;
	}
}

void solve(int y, int x){
	for(int d=0;d<4;++d){
		int possi=1;
		int cnt=map[y][x];
		for(int d2=0;d2<4;++d2){
			if(d==d2) continue;
			int nx=dx[d2]+x;
			int ny=dy[d2]+y;
			if(!isOnMap(ny,nx)) possi=0;
		}
		if(possi){
			for(int d2=0;d2<4;++d2){
				if(d==d2) continue;
				int nx=dx[d2]+x;
				int ny=dy[d2]+y;
				cnt+=map[ny][nx];
			}
			ans=_max(ans,cnt);
		}
	}
}

int main(void){
	cin>>n>>m;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			cin>>map[i][j];
		}
	}
	
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			visit[i][j]=1;
			dfs(i,j,1,map[i][j]);
			visit[i][j]=0;
			solve(i,j);
		}
	}

	cout<<ans;
	return 0;
}
