#include <stdio.h>

/*
	1차원 DP로 메모리 8배 감소가능... 
*/

int n,m,dp[1001];

int _max(int a, int b){return a>b?a:b;}

int main(void){
	int tmp;
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; ++i){
		for(int j=1; j<=m; ++j){
			scanf("%d",&tmp); 
			dp[j]=_max(dp[j-1],dp[j])+tmp;
		}
	}
			
	printf("%d",dp[m]);
	return 0;
}
