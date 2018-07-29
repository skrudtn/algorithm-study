#include <stdio.h>
#include <algorithm>

int arr[51];

int main(void){
	int n,ans;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	
	std::sort(arr+1,arr+n+1);
	printf("%d",arr[1]*arr[n]);
	return 0;
}
