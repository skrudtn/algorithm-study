#include <iostream>

using namespace std;

int tc,n,m,a[1001],b[1001],val[1001];

int main(void){
	int ans;
	cin>>tc;
	
	for(int t=1;t<=tc;++t){
		cin>>n>>m;
		ans=0;
		for(int i=1;i<=n;++i){
			val[i]=0;
		}
		for(int i=1;i<=n;++i){
			cin>>a[i];
		}
		for(int i=1;i<=m;++i){
			cin>>b[i];
		}
		
		for(int i=1;i<=m;++i){
			for(int j=1;j<=n;++j){
				if(b[i]>=a[j]){
					val[j]++;
					break;
				}
			}
		}
		
		int max=0;
		for(int i=1;i<=n;++i){
			if(max<val[i]){
				ans=i;
				max=val[i];
			}
		}
		
		cout<<"#"<<t<<" "<<ans<<endl;
	}
	
	return 0;
}
