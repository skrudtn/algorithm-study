#include <stdio.h>


int solve(int n, int m, int cnt){
	if(cnt==m)
		return n;
	
	return n*solve(n,m,cnt+1);
}

int main(void){
	int tc,n,m,ans;
	freopen("input.txt","r",stdin);
	for(int t=1; t<=10; ++t){
		scanf("%d",&tc);
		scanf("%d%d",&n,&m);
		ans = solve(n,m,1);
		
		printf("#%d %d\n",t,ans);
	}
	
	return 0;
}
