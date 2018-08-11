#include <iostream>

using namespace std;

int n,m,a,b,robot1,robot2,map[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct _node{
	int x,y,d;
}typedef Node;

Node nodes[101];

int isOnMap(int y,int x){
	return x>0 && x<=m && y>0 && y<=n;
}

int move(int idx, char c, int dist){
	int ret=1;
	switch(c){
		case 'L':
			for(int i=0;i<dist%4;++i){
				if(nodes[idx].d==0) nodes[idx].d=3;
				else nodes[idx].d--;
			}
			break;
		case 'R':
				nodes[idx].d=(nodes[idx].d+dist)%4;
			break;
		case 'F':
			for(int i=0;i<dist;++i){
				int nx=nodes[idx].x+dx[nodes[idx].d];
				int ny=nodes[idx].y+dy[nodes[idx].d];
				if(!isOnMap(ny,nx)){
					ret=-1;
					robot1=idx;
					break;
				}
				if(map[ny][nx] != 0){
					ret=-2;
					robot1=idx;
					robot2=map[ny][nx];
					break;
				}
				map[nodes[idx].y][nodes[idx].x]=0;
				map[ny][nx]=idx;
				nodes[idx].x=nx;
				nodes[idx].y=ny;
			}
			break;
		default:
			break;
	}
	return ret;
}
		

int main(void){
	int ans=0;
	cin>>m>>n;
	cin>>a>>b;
	for(int i=1;i<=a;++i){
		int x,y,d;
		char c;
		cin>>x>>y>>c;
		y=n-y+1;
		nodes[i].x=x;
		nodes[i].y=y;
		map[y][x]=i;
		if(c=='E') d=0;
		else if(c=='S') d=1;
		else if(c=='W') d=2;
		else if(c=='N') d=3;
		
		nodes[i].d=d;
	}
	for(int i=1;i<=b;++i){
		int num,dist;
		char c;
		cin>>num>>c>>dist;
		ans=move(num,c,dist);
		if(ans<0) break;
	}
	if(ans>0){
		cout<<"OK";
	} else if(ans==-1) {
		cout<<"Robot "<<robot1<<" crashes into the wall";
	} else {
		cout<<"Robot "<<robot1<<" crashes into robot "<<robot2;
	}
	return 0;
}
