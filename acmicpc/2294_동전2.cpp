#include <stdio.h>
#include <algorithm>

int n,k,arr[101],dp[10001];

int _min(int a, int b){return a<b?a:b;}

int main(void){
	scanf("%d %d",&n,&k);
	dp[0]=0;
	for(int i=1; i<=k; ++i){
		dp[i]=10001;
	}
	for(int i=1; i<=n; ++i){
		scanf("%d",&arr[i]);
	}
	std::sort(arr+1,arr+1+n);
	for(int i=1; i<=n; ++i){
		for(int j=arr[i];j<=k;++j){
			dp[j]=_min(dp[j-arr[i]]+1,dp[j]);
		}
	}

	if(dp[k]==10001) printf("-1");
	else printf("%d",dp[k]);	
	return 0;
}
