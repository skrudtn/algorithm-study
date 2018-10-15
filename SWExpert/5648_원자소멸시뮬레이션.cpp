// 2: 40
#include <iostream>
#include <vector>
#include <utility>
#define WIDTH 4002

using namespace std;

int n,map[WIDTH+1][WIDTH+1];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

struct Node{
	int x,y,d,k,live;
}typedef Node;

Node nodes[1000];

int isOnMap(int y,int x){
	return x>=0 && x<=WIDTH && y>=0 && y<=WIDTH;
}

int solution(){
	int ret=0;
	int live_nodes=0;
	vector<pair<int,int> > collides;
	for(int time = 0; time<=WIDTH;++time){ // 0.5초씩 4002번하면 끝
		// 원자의 0.5초 이동
		live_nodes=0;
		for(int i=0;i<n;++i){
			if(!nodes[i].live) continue;
			live_nodes++;
			int x=nodes[i].x;
			int y=nodes[i].y;
			int d=nodes[i].d;
			int nx=dx[d]+x;
			int ny=dy[d]+y;
			
			if(!isOnMap(ny,nx)){
				nodes[i].live = 0;
				continue;
			}
			map[ny][nx]+=1;
			if(map[ny][nx] == 2){//충돌 
				collides.push_back({nx,ny});
			}
			
			nodes[i].x = nx;
			nodes[i].y = ny; 
		}
		if(!live_nodes) break;
		
		for(int i=0;i<collides.size();++i){
			int cx=collides[i].first;
			int cy=collides[i].second;
		
			for(int i=0;i<n;++i){
				if(!nodes[i].live) continue;
				int x=nodes[i].x;
				int y=nodes[i].y;
				int d=nodes[i].d;
				int k=nodes[i].k;
				if(cx==x && cy==y){
					ret+=k;
					nodes[i].live=0;
				}
			}
		}
		
		collides.clear();
		for(int i=0;i<n;++i){
			int x=nodes[i].x;
			int y=nodes[i].y;
			map[y][x]=0;
		}
	}

	return ret;	
}

int main(void){
	int tc,ans;
	scanf("%d",&tc);
	for(int t=1;t<=tc;++t){
		scanf("%d",&n);
		ans=0;
		for(int i=0;i<n;++i){
			int x,y,d,k;
			scanf("%d %d %d %d",&x,&y,&d,&k);
			x+= 1000;
			y+= 1000;
			
			nodes[i].x=2*x;
			nodes[i].y=2*y;
			nodes[i].d=d;
			nodes[i].k=k;
			nodes[i].live =1;
		}
		ans = solution();
		printf("#%d %d\n",t,ans);
	}
	
	return 0;
}
