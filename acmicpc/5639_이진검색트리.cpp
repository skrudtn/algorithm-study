#include <stdio.h>

int arr[10001];
int cnt;

void solve(int l, int r){
	if(l>r) return;
	int root=l;
	int s=l;
	int d=r;
	while(arr[s] >= arr[root]) s++;
	while(arr[d] > arr[root]) d--;
	solve(s,d);
	solve(d+1,r);
	printf("%d\n",arr[root]);
}

int main(void){
	int root;
	int val;
	
	while(scanf("%d",&val) != -1){
		arr[cnt++]=val;
	}
	solve(0,cnt-1);
	return 0;
}
