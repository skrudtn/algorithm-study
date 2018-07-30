#include <stdio.h>

int n,m,ans,hCnt,cCnt,chk[14],map[51][51];

struct house{
	int x;
	int y;
};

struct chicken{
	int x;
	int y;
};

struct house houses[101];
struct chicken chickens[14];

int _abs(int a){return a<0?-a:a;}
int _min(int a, int b){return a<b?a:b;}

int get_dist(int y1,int x1,int y2,int x2){
	return _abs(x1-x2)+_abs(y1-y2);
}

int get_chicken_dist(int hy, int hx){
	int dist=100;
	
	for(int i=1;i<=m;++i){
		int cy=chickens[chk[i]].y;
		int cx=chickens[chk[i]].x;
		dist=_min(dist,get_dist(hy,hx,cy,cx));
	}
	
	return dist;
}

int get_city_chicken_dist(){
	int ret=0;
	for(int i=1;i<=hCnt;++i){
		int hy=houses[i].y;
		int hx=houses[i].x;
		ret+=get_chicken_dist(hy,hx);
	}
		
	return ret;
}

void solve(int idx, int cnt){
	if(cnt==m+1){
		ans=_min(ans,get_city_chicken_dist());
		return;
	} else if(idx==cCnt+1){
		return;
	}
	chk[cnt]=idx;
	solve(idx+1,cnt+1);
	chk[cnt]=0;
	solve(idx+1,cnt);
}

int main(void){
	scanf("%d %d",&n,&m);
	cCnt=hCnt=0;
	ans=0x7fffffff;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf("%d",&map[i][j]);
			if(map[i][j]==1){
				hCnt+=1;
				houses[hCnt].x=j;
				houses[hCnt].y=i;
			} else if(map[i][j]==2){
				cCnt+=1;
				chickens[cCnt].x=j;
				chickens[cCnt].y=i;
			}
		}
	}
	solve(1,1);
	printf("%d\n",ans);
	return 0;
}
