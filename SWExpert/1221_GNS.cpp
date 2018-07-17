#include <iostream>
#include <string>

using namespace std;

int arr[10];
string words[10] = {"ZRO","ONE","TWO","THR","FOR","FIV","SIX","SVN","EGT","NIN"};

int str2num(string str){
	int ret=0;
	for(int i=0; i<10; ++i){
		if(!str.compare(words[i])){
			
			ret=i;
			break;
		}
	}
	return ret;
}
void printResult(){
	for(int i=0; i<10; ++i){
		for(int j=0; j<arr[i]; ++j){
			cout<<words[i]<<" ";
		}
	}
	cout<<endl;
}

int main(void){
	int tc,n,num;
	string str,tmp;
	cin>>tc;
	for(int t=1; t<=tc; ++t){
		cin>>tmp>>n;
		for(int i=0; i<10; ++i){
			arr[i]=0;
		}
		for(int i=0; i<n; ++i){
			cin>>str;
			
			arr[str2num(str)]++;
		}
		
		cout<<tmp<<" ";
		printResult();
		
	}
	return 0;
}
