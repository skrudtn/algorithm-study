#include <iostream>
#include <string>

using namespace std;

int arr[21];

int solve(string str){
	for(int i=0; i<str.size(); ++i){
		for(int j=0; j<arr[i]; ++j){
			cout<<'-';
		}
		cout<<str.at(i);
	}
	for(int j=0; j<arr[str.size()]; ++j){
		cout<<'-';
	}
	cout<<endl;
	return 0;
}

int main(void){
	int tc,h,tmp;
	string str;
	cin>>tc;
	for(int t=1; t<=tc; ++t){
		cin>>str>>h;
		for(int i=0; i<21; ++i){
			arr[i]=0;
		}
		
		for(int i=0; i<h; ++i){
			cin>>tmp;
			arr[tmp]+=1;
		}
		cout<<"#"<<t<<" ";
		solve(str);
	}
	return 0;
}
