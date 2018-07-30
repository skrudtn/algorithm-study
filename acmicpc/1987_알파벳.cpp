#include <stdio.h>

int ans,r,c,map[21][21],visit[26];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int _max(int a,int b){return a>b?a:b;}

int isOnMap(int y,int x){
	return x>=0 && x<c && y>=0 && y<r;
}

void solve(int y,int x, int cnt){
	ans=_max(ans,cnt);
	for(int d=0; d<4; ++d){
		int nx=x+dx[d];
		int ny=y+dy[d];
		if(isOnMap(ny,nx) && !visit[map[ny][nx]]){
			visit[map[ny][nx]]=1;
			solve(ny,nx,cnt+1);
			visit[map[ny][nx]]=0;
		}
	}
}

int main(void){
	ans=0;
	scanf("%d %d",&r,&c);
	getchar();
	for(int i=0;i<r;++i){
		for(int j=0;j<c;++j){
			char c;
			scanf("%1c",&c);
			map[i][j]=c-65;
		}
		getchar();
	}
	visit[map[0][0]]=1;
	solve(0,0,1);
	printf("%d",ans);
	return 0;
}
