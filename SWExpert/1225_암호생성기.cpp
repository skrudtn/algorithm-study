#include <stdio.h>

#define NUM 8

int arr[NUM];
int h;

void getResult(void){
	for(int i=h; i<h+NUM; ++i){
		printf("%d ",arr[i%NUM]);
	}
	printf("\n");
}

void solve(void){
	int c=1;
	while(1){
		arr[h] -= c++;
		if(arr[h]<=0){
			arr[h]=0;
			h++;
			break;
		}
		h++;
		h=h%8;
		if(c%5==0) c=5;
		else c=c%5;
		
	}
}

int main(void){
	int tc;
	for(int t=1; t<=10; ++t){
		h=0;
		scanf("%d",&tc);	
		for(int i=0; i<NUM; ++i){
			scanf("%d",&arr[i]);
		}
		solve();
		printf("#%d ",tc);
		getResult();
	}
	
	return 0;
}
