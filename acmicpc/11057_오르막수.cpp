#include <stdio.h>

int arr[10][1001];

int main(void){
	int n;
	int ans=0;
	scanf("%d",&n);
	
	for(int i=0; i<10; ++i){
		arr[i][1]=1;
	}
	
	/* (i,j) j��° �ڸ��� ���ڰ� i�� DP */
	 
	for(int i=0; i<10; ++i){
		for(int j=2; j<=n; ++j){
			for(int k=0; k<=i; ++k){
				arr[i][j] += arr[k][j-1];
				arr[i][j] %= 10007;
			}
		}
	}

	for(int i=0; i<10; ++i){
		ans+=arr[i][n];
	}
	
	printf("%d\n",ans%10007);
	return 0;
}
