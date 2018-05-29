#include<stdio.h>

#include <algorithm>

using namespace std;

int arr[100001];
int max(int a,int b){
	return a>b?a:b;
}
int main(void){
	int tc,T,N;
	
	freopen("sample_input.txt","r",stdin);

	scanf("%d",&T);

	for(tc=1; tc<=T; ++tc){
		scanf("%d",&N);
		for(int i=0;i<N;++i){
			scanf("%d",&arr[i]);
		}
		sort(arr,arr+N);
		int ans=0;
		ans=max(ans,arr[1]-arr[0]);
		ans=max(ans,arr[N-1]-arr[N-2]);
		for(int i=2;i<N;++i){
			ans=max(ans,arr[i]-arr[i-2]);
		}
		printf("#%d %d\n",tc,ans);
	}
	return 0;
}
