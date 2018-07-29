#include <stdio.h>
#include <algorithm>

using namespace std;

int arr[1001],l[1001];

int _max(int a, int b){return a>b?a:b;}

int main(void){
	int n,len;
	scanf("%d",&n);
	len=0;
	for(int i=0;i<n;++i){
		scanf("%d",&arr[i]);
	}
	
	for(int i=0;i<n;++i){
		if(!len || l[len-1] < arr[i]){
			l[len]=arr[i];
			len++;
		} else {
			int *pos=lower_bound(l,l+len,arr[i]);
			*pos=arr[i];
		}
	}
	
	printf("%d",len);
	return 0;
}
