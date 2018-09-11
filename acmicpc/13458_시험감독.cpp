#include <stdio.h>

int n,b,c,arr[1000001];

int main(void){
	long long ans;
	scanf("%d",&n);
	for(int i=1;i<=n;++i){
		scanf("%d",&arr[i]);
	}
	scanf("%d %d",&b,&c);
	ans=n;
	for(int i=1;i<=n;++i){
		arr[i]-=b;
		if(arr[i]<0) arr[i]=0;
		if(arr[i] % c == 0) {
			ans+= arr[i]/c;
		}
		else {
			ans+=arr[i]/c+1;
		}
	}
	
	printf("%lld",ans);
	return 0;
}
