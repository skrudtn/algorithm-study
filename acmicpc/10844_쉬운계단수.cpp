#include <stdio.h>

#define MOD 1000000000

typedef long long unsigned llu;

llu arr[10][101];

int main(void){
	int n;
	llu ans;
	ans=0;
	scanf("%d",&n);
	arr[0][1]=0;
	for(int i=1; i<10; ++i){
		arr[i][1]=1;
	}
	
	for(int i=2;i<=n;++i){
		arr[0][i]=arr[1][i-1];
		arr[9][i]=arr[8][i-1];
		for(int j=1;j<9;++j){
			arr[j][i]=(arr[j-1][i-1]+arr[j+1][i-1]) % MOD;
		}
	}
	for(int i=0; i<10; ++i){
		ans+=arr[i][n];
	}
	printf("%llu",ans%MOD);
	return 0;
}
