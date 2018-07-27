#include <iostream>
#include <string>
#include <sstream>

using namespace std;

string int2str(int i){
	stringstream sst;
	sst<<i;
	return sst.str();
}

int isHansu(int i){
	if(i<100) return 1;
	
	int diff,flg=0;
	string str=int2str(i);
	
	diff=str.at(1)-str.at(0);
//	printf("%d diff %d\n",i,diff);
	for(int i=1;i<str.length();++i){
//			cout<<str.at(i)<<"-"<<str.at(i-1)<<endl;
		if(str.at(i)-str.at(i-1)!=diff){
			return 0;
		}
	}
	return 1;
}

int main(void){
	int n,ans=0;
	cin>>n;
	for(int i=1; i<=n; ++i){
		if(isHansu(i)) ans++;
	}
	cout<<ans;
	return 0;
}
