#include <iostream>
#include <string>

using namespace std;
int arr[4] = {0,};

int solve(string str,int n){
	for(int i=0; i<n; ++i){
		if(str.at(i)=='{') arr[0]++;
		else if(str.at(i)=='[') arr[1]++;
		else if(str.at(i)=='(') arr[2]++;
		else if(str.at(i)=='<') arr[3]++;
		else if(str.at(i)=='}') arr[0]--;
		else if(str.at(i)==']') arr[1]--;
		else if(str.at(i)==')') arr[2]--;
		else if(str.at(i)=='>') arr[3]--;
	}
	
	for(int i=0; i<4; ++i){
		if(arr[i]!=0) return 0;
	}
	
	return 1;
}

int main(void){
	int n,ans;
	string str;
	
	freopen("input.txt","r",stdin);
	for(int t=1; t<=10; ++t){
		cin>>n;
		cin>>str;	
		for(int i=0; i<4; ++i)
			arr[i]=0;
		ans=solve(str,n);
		cout<<"#"<<t<<" "<<ans<<endl;
	}

	return 0;
}
