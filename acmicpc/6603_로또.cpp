#include <stdio.h>

#define CNT 6

int n,result[7],arr[13];

void print(){
	for(int i=1;i<=CNT;++i){
		printf("%d ",arr[result[i]]);
	}
	printf("\n");
}

void solve(int idx, int cnt){
	if(cnt==CNT+1){
		print();
		return;
	} else if(idx==n+1){
		return;
	}
	
	result[cnt]=idx;
	solve(idx+1,cnt+1);
	result[cnt]=0;
	solve(idx+1,cnt);
	
}

int main(void){
	n=1;
	while(n){
		scanf("%d",&n);
		for(int i=1; i<=n; ++i){
			scanf("%d",&arr[i]);
		}
		solve(1,1);
		printf("\n");
	}
	return 0;
}
