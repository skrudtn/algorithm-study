#include <iostream>
#include <queue>

using namespace std;

int n,dstX,dstY,map[301][301],visit[301][301];
int dx[8]={2,1,-2,-1,-1,-2,1,2};
int dy[8]={1,2,1,2,-2,-1,-2,-1};

struct _node{
	int y,x,cnt;
}typedef Node;

int isOnMap(int y,int x){
	return x>=0 && x<n && y>=0 && y<n;
}

int bfs(int sx, int sy){
	queue<Node> que;
	que.push(Node{sy,sx,0});
	visit[sy][sx]=1;
	
	while(!que.empty()){
		int cy=que.front().y;
		int cx=que.front().x;
		int cnt=que.front().cnt;
		que.pop();
		if(cx==dstX && cy==dstY) return cnt;
		
		for(int d=0;d<8;++d){
			int nx=cx+dx[d];
			int ny=cy+dy[d];
			if(!isOnMap(ny,nx)) continue;
			if(visit[ny][nx]) continue;
			visit[ny][nx]=1;
			que.push(Node{ny,nx,cnt+1});
		}
	}
	
	return -1;
}

int main(void){
	int tc,sx,sy;
	cin>>tc;
	for(int t=1;t<=tc;++t){
		cin>>n;
		cin>>sx>>sy;
		cin>>dstX>>dstY;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				visit[i][j]=0;
			}
		}
		cout<<bfs(sx,sy)<<endl;
	}
	
	return 0;
}
