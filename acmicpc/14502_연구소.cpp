#include <stdio.h>
#include <vector>

using namespace std;

int n,m,vCnt,ans,arr[3];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int map[8][8];
typedef struct Pos{
	int x,y;
}Pos;

Pos virus[64];

int max(int a,int b){return a>b?a:b;}
int isOnMap(int y,int x){
	return x>=0 && x<m && y>=0 && y<n;
}

int getCnt(int map[8][8]){
	int ret=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(map[i][j]==0) ret++;
		}
	}
	return ret;
}

void fill(int map[8][8], int y, int x){
	for(int d=0;d<4;++d){
		int nx=dx[d]+x;
		int ny=dy[d]+y;
		if(!isOnMap(ny,nx)) continue;
		if(map[ny][nx] == 0){
			map[ny][nx]=2;
			fill(map,ny,nx);
		}
	}
}

void solve(int idx, int cnt, int N, int r){
	if(cnt==r){
		int dupeMap[8][8];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				dupeMap[i][j] = map[i][j];
			}
		}
		
		for(int i=0;i<3;++i){
			dupeMap[arr[i]/m][arr[i]%m]=1;
		}
		for(int v=0;v<vCnt;++v){
			fill(dupeMap,virus[v].y,virus[v].x);
		}
		ans=max(ans,getCnt(dupeMap));
		return;
	} else if(idx==N){
		return;
	} else{
		if(map[idx/m][idx%m]==0){
			arr[cnt] = idx;
			solve(idx+1,cnt+1,N,r);
			arr[cnt] = 0;
		}
		solve(idx+1,cnt,N,r);
	}
}

int main(void){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			scanf("%d",&map[i][j]);
			if(map[i][j]==2){
				virus[vCnt].x=j;
				virus[vCnt].y=i;
				vCnt++;
			}
		}
	}
	solve(0,0,n*m,3);
	printf("%d\n",ans);
}
