#include <stdio.h>

int n,m,t,ans;
int map[9][9] = {0,};
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
struct cctv{
	int x;
	int y;
	int type;
};

struct cctv cctvs[9] = {0,};

int _min(int a,int b){return a>b?b:a;}

int isOnMap(int y, int x){
	return x>0 && x<=m && y>0 && y<=n;
}

int get_cnt(){
	int ret=0;
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			if(!map[i][j]) ret++;
		}
	}
	return ret;
}

void go(int idx, int d, int val){
	int x=cctvs[idx].x;
	int y=cctvs[idx].y;
	x+=dx[d];
	y+=dy[d];
	while(isOnMap(y,x) && map[y][x] != -1){
		map[y][x]+=val;
		x+=dx[d];
		y+=dy[d];
	}
}



void dfs(int idx){
	if(idx==t) {
		ans=_min(ans,get_cnt()); 
		return;
	}
	int type=cctvs[idx].type;

	switch(type){
		case 1:
			for(int d=0; d<4; ++d){
				go(idx,d,type);
				dfs(idx+1);
				go(idx,d,-type);
			}
			break;
		case 2:
			for(int d=0; d<2; ++d){
				go(idx,d,type);
				go(idx,d+2,type);
				dfs(idx+1);
				go(idx,d,-type);
				go(idx,d+2,-type);
			}
			break;
		case 3:
			for(int d=0; d<4; ++d){
				go(idx,d,type);
				go(idx,(d+1)%4,type);
				dfs(idx+1);
				go(idx,d,-type);
				go(idx,(d+1)%4,-type);
			}
			break;
		case 4:
			for(int d=0; d<4; ++d){
				go(idx,d,type);
				go(idx,(d+1)%4,type);
				go(idx,(d+2)%4,type);
				dfs(idx+1);
				go(idx,d,-type);
				go(idx,(d+1)%4,-type);
				go(idx,(d+2)%4,-type);
			}
			break;
		case 5:
			go(idx,0,type);
			go(idx,1,type);
			go(idx,2,type);
			go(idx,3,type);
			dfs(idx+1);
			go(idx,0,-type);
			go(idx,1,-type);
			go(idx,2,-type);
			go(idx,3,-type);
			break;
		default:
			break;
	}
}

int main(void){
	int tmp;
	scanf("%d %d", &n, &m);
	ans=n*m;
	
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf("%d",&tmp);
			if(tmp != 0 && tmp != 6){
				cctvs[t].x = j;
				cctvs[t].y = i;
				cctvs[t].type = tmp;
				++t;
			} else if(tmp ==6){
				tmp=-1;
			}
			map[i][j]=tmp;
		}
	}
	
	dfs(0);
	printf("%d",ans);
	return 0;
}
