#include <stdio.h>
#include <deque>

#define MAX_VAL 1000000000

using namespace std;
typedef long long lld;

lld arr[5000001];
int n,l;

int main(void){
	deque<int> deq;

	scanf("%d %d",&n,&l);
	for(int i=0;i<n;++i){
		scanf("%lld",&arr[i]);
		while(!deq.empty() && deq.front() < i-l+1) deq.pop_front();
		while(!deq.empty() && arr[deq.back()] >= arr[i]) deq.pop_back();
		deq.push_back(i);
		printf("%lld ",arr[deq.front()]); 
	}
	return 0;
}
