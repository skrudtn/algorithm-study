#include <iostream>

using namespace std;

int ans,tc,n,b,sum,arr[21];

int _min(int a,int b){return a<b?a:b;}
void solve(int idx, int cnt,int val){
	if(sum-val<b){
		return;
	}
	
	if(idx>n+1) return;
	if(cnt>n+1) return;
	if(sum-(val+b)>=0){
		ans=_min(ans,sum-(val+b));
	}
	solve(idx+1,cnt+1,val+arr[idx]);
	solve(idx+1,cnt,val);
}

int main(void){
	cin>>tc;
	
	for(int t=1;t<=tc;++t){
		cin>>n>>b;
		sum=0;
		ans=0x1c1c1c1c;
		for(int i=1;i<=n;++i){
			cin>>arr[i];
			sum+=arr[i];
		}
		solve(1,1,0);
		cout<<"#"<<t<<" "<<ans<<endl;
	}
	
	return 0;
}
