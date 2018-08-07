#include <iostream>

using namespace std;

int n,b,c,room[1000001];

long long solve(){
	long long cnt=0;
	// n=1000000, room[i]=1000000, b=c=1 일때 cnt가 int 범위 벗어남. 
	for(int i=1;i<=n;++i){
		room[i]-=b;
		cnt++;
		if(room[i]>0){
			cnt+=room[i]/c;
			if(room[i]%c) cnt++;
		}
	}
	return cnt;
}

int main(void){
	cin>>n;
	for(int i=1;i<=n;++i){
		cin>>room[i];
	}
	cin>>b>>c;
	cout<<solve();
	return 0;
}
