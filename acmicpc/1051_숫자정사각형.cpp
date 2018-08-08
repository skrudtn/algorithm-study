#include <iostream>
#include <queue>

using namespace std;

int n,m,map[51][51];

int chk(int y,int x, int len){
	return map[y][x]==map[y+len][x+len] && 
		map[y][x]==map[y][x+len] && 
		map[y][x]==map[y+len][x];
}

int main(void){
	int a,b,ans=1;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf("%1d",&map[i][j]);
		}
	}
	if(n<m){
		a=m;
		b=n-1;
	} else{
		a=n;
		b=m-1;
	}

	for(int len=b;len>0;--len){
		for(int i=1;i<=n-len;++i){
			for(int j=1;j<=m-len;++j){
				if(chk(i,j,len)){
					cout<<(len+1)*(len+1);
					return 0;
				}
			}
		}	
	}
	printf("%d\n",ans);
	return 0;
}
