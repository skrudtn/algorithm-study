#include <iostream>

using namespace std;

int solve(int i){
	int sum=i;
	int tmp=i;
	while(tmp){
		sum+=tmp%10;
		tmp/=10;
	}
		
	return sum;
}

int main(void){
	int n;
	cin>>n;
	for(int i=n/10;i<=n;++i){
		if(solve(i)==n) {
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<0;
	return 0;
}
