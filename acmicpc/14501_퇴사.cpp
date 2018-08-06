#include <iostream>

using namespace std;

int ans,n,arr[16][3];

int _max(int a,int b){return a>b?a:b;}

void solve(int s,int val){
	if(s+arr[s][1]>n){
		if(s+arr[s][1]==n+1) val+=arr[s][2];
		ans=_max(ans,val);
		return;
	}
	val+=arr[s][2];
	for(int i=s+arr[s][1];i<=n;++i){
		solve(i,val);
	}
}

int main(void){
	int a,b;
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>a>>b;
		arr[i][1]=a;
		arr[i][2]=b;
	}
	for(int i=1;i<=n;++i){
		solve(i,0);	
	}
	cout<<ans;
	return 0;
}
