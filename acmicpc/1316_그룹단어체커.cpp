#include <iostream>
#include <string>

using namespace std;

int arr[26];

int isGroupWord(string str){
	int i;
	arr[str.at(0)-97]=1;
	for(int k=1;k<str.length();++k){
		i=str.at(k)-97;
		if(arr[i]==0) arr[i]++;
		else if(arr[i] && str.at(k-1)!=str.at(k)) return 0;
	}
	return 1;
}

int main(void){
	int n,ans=0;
	string str;
	cin>>n;
	for(int i=0; i<n; ++i){
		cin>>str;
		for(int j=0; j<26; ++j) arr[j]=0;
		if(isGroupWord(str)) ans++;
	}
	cout<<ans;
	return 0;
}
