#include <stdio.h>

int n,plusMax,minusMax,multiMax,divideMax,mAns,MAns,arr[100];

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}

void dfs(int plus,int minus,int multi,int divide,int cnt, int val){
	if(cnt == n){
		mAns = min(mAns,val);
		MAns = max(MAns,val);
		return;
	}
	
	if(plus<plusMax){
		dfs(plus+1,minus,multi,divide,cnt+1,val+arr[cnt]);
	}

	if(minus<minusMax){
		dfs(plus,minus+1,multi,divide,cnt+1,val-arr[cnt]);
	}

	if(multi<multiMax){
		dfs(plus,minus,multi+1,divide,cnt+1,val*arr[cnt]);
	}

	if(divide<divideMax){
		dfs(plus,minus,multi,divide+1,cnt+1,val/arr[cnt]);
	}
	
}

int main(void){
	scanf("%d",&n);
	mAns = 0x7fffffff;
	MAns = 0x80000000;
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	scanf("%d %d %d %d",&plusMax,&minusMax,&multiMax,&divideMax);
	
	dfs(0,0,0,0,1,arr[0]);
	
	printf("%d\n%d\n",MAns,mAns);
	
	return 0;
}
