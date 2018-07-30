#include <stdio.h>

int arr[3][100001],dp[3][100001];;

int _max(int a,int b){return a>b?a:b;}
int main(void){
	int tc,n,ans;
	scanf("%d",&tc);
	for(int t=1; t<=tc; ++t){
		ans=0;
		scanf("%d",&n);
		for(int i=1; i<=2; ++i){
			for(int j=1; j<=n; ++j){
				scanf("%d",&arr[i][j]);
			}
		}
		dp[1][1]=arr[1][1];
		dp[2][1]=arr[2][1];
		dp[1][2]=arr[2][1]+arr[1][2];
		dp[2][2]=arr[1][1]+arr[2][2];
		
		for(int i=3; i<=n; ++i){
			dp[1][i]=arr[1][i]+_max(dp[2][i-1],dp[2][i-2]);
			dp[2][i]=arr[2][i]+_max(dp[1][i-1],dp[1][i-2]);
		}
		
		for(int i=1; i<=2; ++i){
			for(int j=n-1; j<=n; ++j){
				ans=_max(ans,dp[i][j]);
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
