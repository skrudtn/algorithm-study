#include <iostream>
#include <cmath>

using namespace std;

int n;

int isPnum(int num){
	if(num<2) return 0;
	for(int i=2;i<=sqrt(double(num));++i){
		if(num%i == 0) return 0;
	}
	return 1;
}


void solve(int idx, int val){
	if(idx==n){
		cout<<val<<endl;
		return;
	}
	
	for(int i=1;i<10;++i){
		if(isPnum(val*10+i)) solve(idx+1,val*10+i);
	}
}

int main(void){
	cin>>n;
	for(int i=1;i<10;++i){
		if(isPnum(i)) solve(1,i);
	}
	
	return 0;
}
