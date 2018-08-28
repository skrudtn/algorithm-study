#include <iostream>

using namespace std;

int n,m,ans,b[1001],visit[1001],adj[1001][1001];

int dfs(int a){
	if(visit[a]) return 0;
	visit[a]=1;

	for(int i=1;i<=m;++i){
		if(adj[a][i]){
			if(b[i]==0 || dfs(b[i])){
				b[i]=a;
				return 1;
			}
		}
	}
	return 0;
}

int main(void){
	int tmp,h;
	ans=0;
	freopen("input.txt","r",stdin);
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; ++i){
		scanf("%d",&h);
		for(int j=0; j<h;++j){
			scanf("%d",&tmp);
			adj[i][tmp]=1;
		}
	}

	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			visit[j]=0;
		}
		if(dfs(i)) ans++;
	}

	printf("%d",ans);
	return 0;
}
