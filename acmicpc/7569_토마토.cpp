#include <iostream>
#include <queue>

using namespace std;

int m,n,h,map[101][101][101];
int dx[6]={1,0,-1,0,0,0};
int dy[6]={0,1,0,-1,0,0};
int dz[6]={0,0,0,0,1,-1};
struct _node{
	int z,y,x,cnt;
}typedef Node;

int isOnMap(int z,int y,int x){
	return x>0 && x<=m && y>0 && y<=n && z>0 && z<=h;
}

int bfs(queue<Node> que){
	int cnt=0;
	while(!que.empty()){
		int cx=que.front().x;
		int cy=que.front().y;
		int cz=que.front().z;
		cnt=que.front().cnt;
		que.pop();
		
		for(int d=0;d<6;++d){
			int nx=dx[d]+cx;
			int ny=dy[d]+cy;
			int nz=dz[d]+cz;
			if(!isOnMap(nz,ny,nx)) continue;
			if(map[nz][ny][nx]==0) {
				map[nz][ny][nx]=1;
				que.push(Node{nz,ny,nx,cnt+1});
			}
		}
	}
	
	for(int z=1;z<=h;++z){
		for(int y=1;y<=n;++y){
			for(int x=1;x<=m;++x){
				if(map[z][y][x]==0) return -1;
			}
		}
	}
	return cnt;
}

int main(void){
	queue<Node> que;
	freopen("input.txt","r",stdin);
	cin>>m>>n>>h;
	
	for(int z=1;z<=h;++z){
		for(int y=1;y<=n;++y){
			for(int x=1;x<=m;++x){
				cin>>map[z][y][x];
			}
		}
	}
	
	for(int z=1;z<=h;++z){
		for(int y=1;y<=n;++y){
			for(int x=1;x<=m;++x){
				if(map[z][y][x]==1) {
					que.push(Node{z,y,x,0});
				}
			}
		}
	}
	
	cout<<bfs(que)<<endl;
	
	return 0;
}
