#include <iostream>
#include <utility>
#include <queue>
#include <algorithm>

using namespace std;

int m,n,k,size[101],map[101][101],visit[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int isOnMap(int y,int x){
	return x>=0 && x<m && y>=0 && y<n;
}

int bfs(int i,int j){
	int cnt=1;
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
			if(map[ny][nx]==0){
				que.push({ny,nx});
				cnt++;
				visit[ny][nx]=1;
			}
		}

	}
	return cnt;
}

int main(void){
	int ans=0;
	cin>>n>>m>>k;
	for(int t=0;t<k;++t){
		int a,b,c,d;
		cin>>a>>b>>c>>d;
		for(int i=b;i<d;++i){
			for(int j=a;j<c;++j){
				map[i][j]=1;
			}
		}
	}
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(visit[i][j]) continue;
			if(map[i][j]==0){
				size[ans]=bfs(i,j);
				ans++;
			}
		}
	}
	sort(size,size+ans);
	cout<<ans<<endl;
	for(int i=0;i<ans;++i){
		cout<<size[i]<<" ";
	}
	return 0;
}
