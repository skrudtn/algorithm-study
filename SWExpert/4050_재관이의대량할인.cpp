#include <stdio.h>
#include <algorithm>

int arr[100002];
int N,ans;

void solution(){
	int quotient = N/3;
	for(int i=1; i<=quotient; ++i){
		ans-=arr[3*i-1];
	}
}

bool comp(int a, int b){
	return a>b;
}

int main(void){
	int tc,T;
	
	scanf("%d",&T);
	for(tc=1; tc<=T; ++tc){
		ans=0;
		scanf("%d", &N);
	
		for(int n=0;n<N;++n){
			scanf("%d",&arr[n]);
			ans+=arr[n];
		}
		std::sort(arr,arr+N,comp);
		
		solution();
		
		printf("#%d %d\n", tc, ans);
	}
	return 0;
}
