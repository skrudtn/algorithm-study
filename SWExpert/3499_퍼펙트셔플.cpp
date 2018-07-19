#include <iostream>
using namespace std;

string a[501];
string b[501];

void getResult(int n){
	int ai,bi;
	ai=bi=0;
	for(int i=1; i<=n; ++i){
		if(i%2) cout<<a[ai++]<<" ";
		else cout<<b[bi++]<<" ";
	}
	cout<<endl; 
}

int main(void){
	int tc,n;
	freopen("sample_input.txt", "r", stdin);
	cin>>tc;
	for(int t=1;t<=tc; ++t){
		cin>>n;
		for(int i=0; i<(n+1)/2; ++i){
			cin>>a[i];
		}
		for(int i=0; i<n/2; ++i){
			cin>>b[i];
		}
		cout<<"#"<<t<<" ";
		getResult(n);
	}
	return 0;
}
