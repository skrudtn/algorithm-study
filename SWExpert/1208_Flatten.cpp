#include <stdio.h>

int arr[101];

int* get_dump_val(void){
	int ret[2], min_val,min_idx,max_val,max_idx;
	min_val=101;
	max_val=0;
	for(int i=1; i<101; ++i){
		if(min_val>arr[i]) {
			min_val = arr[i];
			min_idx=i;
		}
		if(max_val<arr[i]){
			max_val = arr[i];
			max_idx=i;
		}
	}
	ret[0]=min_idx;
	ret[1]=max_idx;
	
	return ret;
}

int main(void){
	int dump,max_val,min_val,ans;
	int *dump_val;

	for(int t=1; t<=10; ++t){
		scanf("%d",&dump);
		ans=0;
		for(int i=1; i<=100; ++i){
			scanf("%d",&arr[i]);
		}
		min_val = 0; 
		max_val = 0;
		for(int i=0; i<dump; ++i){
			dump_val = get_dump_val();
			min_val = dump_val[0];
			max_val = dump_val[1];
			arr[min_val]++;
			arr[max_val]--;
		}
		dump_val = get_dump_val();
		ans = arr[dump_val[1]]-arr[dump_val[0]];
		printf("#%d %d\n",t,ans);
	}
	
	return 0;
}
