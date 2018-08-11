#include <iostream>
#include <queue>

#define WATER 2
#define SRC 1
#define DST 3

using namespace std;

int n,m,srcX,srcY,map[51][51],visit[51][51];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct node{
	int y,x,time,type;
}typedef Node;

int isOnMap(int y,int x){
	return x>0 && x<=m && y>0 && y<=n;
}

int main(void){
	queue<Node> que;
	int ans=-1;
	char tmp;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf(" %1c",&tmp);
			if(tmp=='S') {srcX=j,srcY=i;}
			else if(tmp=='D') map[i][j]=DST;
			else if(tmp=='.') map[i][j]=0;
			else if(tmp=='X') map[i][j]=9;
			else if(tmp=='*') {
				map[i][j]=WATER;
				que.push(Node{i,j,0,WATER});
			}
		}
	}
	visit[srcY][srcX]=1;
	que.push(Node{srcY,srcX,0,SRC});

	while(!que.empty()){
		Node cur=que.front();
		que.pop();
		int cx,cy;
		cx=cur.x;
		cy=cur.y;
		
		if(cur.type==WATER){
			for(int d=0;d<4;++d){
				int nx=dx[d]+cx;
				int ny=dy[d]+cy;
				if(!isOnMap(ny,nx)) continue;
				if(map[ny][nx]==0){
					map[ny][nx]=WATER;
					que.push(Node{ny,nx,cur.time+1,WATER});
				}
			}
		} else{
			if(map[cy][cx]==DST){
				ans=cur.time;
				break;
			}
			for(int d=0;d<4;++d){
				int nx=dx[d]+cx;
				int ny=dy[d]+cy;
				if(!isOnMap(ny,nx)) continue;
				if(visit[ny][nx]) continue;
				if(map[ny][nx]==0||map[ny][nx]==DST){
					visit[ny][nx]=1;
					que.push(Node{ny,nx,cur.time+1,SRC});
				}
			}
		}
	}
	if(ans==-1){
		printf("KAKTUS");
	} else {
		printf("%d",ans);
	}
	return 0;
}
