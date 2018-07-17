#include <stdio.h>

int arr[2][100];
int ans;

void solve(int s){
	if(arr[0][s]==99 || arr[1][s]==99){
		ans=1;
	}
	
	if(arr[0][s]!=-1){
		solve(arr[0][s]);
	}
	if(arr[1][s]!=-1){
		solve(arr[1][s]);
	}
}

int main(void){
	int tc,n,a,b;
	for(int t=1; t<=10; ++t){
		scanf("%d %d",&tc,&n);
		ans=0;
		for(int i=0; i<100; ++i){
			arr[0][i]=arr[1][i]=-1;
		}
		
		for(int i=0; i<n; ++i){
			scanf("%d %d",&a,&b);
			if(arr[0][a] == -1) arr[0][a]=b;
			else arr[1][a]=b;
		}
		solve(0);
		printf("#%d %d\n",tc,ans);
	}
	
	return 0;
}
