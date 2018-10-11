#include <stdio.h>

using namespace std;

int ans,n,m,map[501][501],visit[501];

void dfs(int s, int cnt){
	if(cnt==2){
		return;
	}
	
	for(int i=1;i<=n;++i){
		if(map[s][i]){
			visit[i]=1;
			dfs(i,cnt+1);
		}
	}
}

int main(void){
	int tc;
	scanf("%d",&tc);
	for(int t=1;t<=tc;++t){
		ans=0;
		for(int i=1;i<=n;++i){
			visit[i]=0;
			for(int j=1;j<=n;++j){
				map[i][j]=0;
			}
		}
		scanf("%d %d",&n,&m);
		for(int i=0;i<m;++i){
			int a,b;
			scanf("%d %d",&a,&b);
			map[a][b]=1;
			map[b][a]=1;
		}
		visit[1]=1;
		dfs(1,0);
		for(int i=2;i<=n;++i){
			if(visit[i]) ans++;
		}
		printf("#%d %d\n",t,ans);
	}
	
	return 0;
}
