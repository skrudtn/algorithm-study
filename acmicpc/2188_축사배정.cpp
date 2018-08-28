#include <iostream>

using namespace std;

int n,m,b[201],visit[201],adj[201][201];

int dfs(int v){
	if(visit[v])
		return 0;
	
	visit[v]=1;
	
	for(int i=1;i<=m;++i){
		if(adj[v][i]){
			if(b[i]==0 || dfs(b[i])){
				b[i]=v;
				return 1;
			}
		}
	}
	
	return 0;
}

int main(void){
	int tmp,k,ans;
	cin>>n>>m;
	ans=0;
	for(int i=1;i<=n;++i){
		cin>>tmp;
		for(int j=1;j<=tmp;++j){
			cin>>k;
			adj[i][k]=1;
		}
	}
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			visit[j]=0;
		}
		if(dfs(i)) ans++;
	}
	cout<<ans;
	
	return 0;
}
