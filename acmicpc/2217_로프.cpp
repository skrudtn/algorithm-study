#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[100001];

int desc(int a, int b){return a>b;}

int main(void){
	int n,ans;
	ans=0;
	scanf("%d",&n);
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	sort(arr,arr+n,desc);
	for(int i=0; i<n; ++i){
		if(ans<arr[i]*(i+1)) ans=arr[i]*(i+1);
	}
	
	printf("%d",ans);
	return 0;
}
