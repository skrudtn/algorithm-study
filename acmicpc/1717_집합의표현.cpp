#include <stdio.h>

int parent[1000001];

int find(int u){
	if(u==parent[u]){
		return u;
	}
	parent[u]=find(parent[u]);
	return parent[u];
}

void merge(int u, int v){
	u = find(u);
	v = find(v);
	
	if(u==v)
		return;
	
	parent[u] = v;
}

int main(void){
	int n,m,a,b,op;
	freopen("input.txt", "r", stdin);
	scanf("%d %d", &n,&m);
	for(int i=1; i<=n; ++i){
		parent[i]=i;
	}
	
	for(int i=0; i<m; ++i){
		scanf("%d %d %d", &op,&a,&b);
		
		if(op){
			if(find(a)==find(b)) printf("YES\n");
			else printf("NO\n");
		} else{
			merge(a,b);
		}
	}
	return 0;
}

