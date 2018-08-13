#include <iostream>

using namespace std;

int n,m,visit[1001],adj[1001][1001];

void dfs(int s){
	for(int i=1;i<=n;++i){
		if(visit[i]) continue;
		if(adj[s][i]){
			visit[i]=1;
			dfs(i);
		}
	}
}

int main(void){
	int ans=0;
	cin>>n>>m;
	
	for(int i=0;i<m;++i){
		int a,b;
		cin>>a>>b;
		adj[a][b]=1;
		adj[b][a]=1;
	}
	for(int i=1;i<=n;++i){
		if(visit[i]) continue;
		visit[i]=1;
		dfs(i);
		ans++;
	}
	cout<<ans;
	return 0;
}
