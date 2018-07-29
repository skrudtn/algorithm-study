#include <iostream>

using namespace std;

int n,arr[101];
long long dp[101][21];

void solve(void){
	dp[1][arr[1]]=1;
	for(int i=1; i<=n-1; ++i){
		for(int j=0; j<21; ++j){
			if(dp[i][j]){
				int a=j+arr[i+1];
				int b=j-arr[i+1];
				if(a<=20){
					dp[i+1][a] += dp[i][j];
				}
				if(b>=0){
					dp[i+1][b] += dp[i][j];
				}
			}
		}
	}
}

int main(void){
	cin>>n;
	for(int i=1; i<=n;++i){
		cin>>arr[i];
	}
	solve();
	cout<<dp[n-1][arr[n]];
	return 0;
}
