#include <stdio.h>

int n,m,r,c,d,end,map[50][50],visit[50][50];
int dx[4] = {0,1,0,-1};
int dy[4] = {-1,0,1,0};

void solve1();
void solve2(int);

int isOnMap(int y,int x){
	return x>=0 && x<m && y>=0 && y<n;
}

int getAns(){
	int ret=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(visit[i][j]==1) ret++;
		}
	}
	return ret;
}

void solve1(){
	if(end == 1) return;
	visit[r][c]=1;
	solve2(0);
}

void solve2(int cnt){
	if(end == 1) return;
	if(cnt==4){
		int dir=(d+2)%4;
		int nx=dx[dir]+c;
		int ny=dy[dir]+r;
		if(map[ny][nx] == 0){
			c=nx, r=ny;
			solve2(0);
		} else {
			end=1;
			return;
		}
	}
	
	int dir=(d+3)%4;
	int nx=dx[dir]+c;
	int ny=dy[dir]+r;
	if(map[ny][nx]==0 && visit[ny][nx]==0){
		d = dir;
		c=nx, r=ny;
		solve1();
	} else if(visit[ny][nx]==1 || map[ny][nx]==1){
		d = dir;
		solve2(cnt+1);
	}
}

int main(void){
	scanf("%d %d",&n,&m);
	scanf("%d %d %d",&r,&c,&d);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&map[i][j]);
		}
	}
	solve1();
	printf("%d\n",getAns());
}
