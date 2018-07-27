#include <iostream>
#include <string>

using namespace std;

int arr[10];

int _max(int a,int b){return a>b?a:b;}
int char2int(char c){
	int i=c-'0';
	return i;
}

int main(void){
	int n,ans=0;
	string str;
	cin>>str;
	for(int i=0; i<str.length();++i){
		n=char2int(str.at(i));
		if(n==9){
			arr[6]++;
		} else {
			arr[n]++;
		}
	}
	arr[6] = (arr[6]+1)/2;
	for(int i=0; i<9; ++i){
		ans=max(ans,arr[i]);
	}
	cout<<ans;
	return 0;
}
