#include <iostream>
#include <string>

using namespace std;

int arr[1001][1001];

int main(void){
	string str1,str2,lcs;
	int l1,l2;
	cin>>str1>>str2;
	l1=str1.length();
	l2=str2.length();
	
	for(int i=0; i<l1; ++i){
		for(int j=0; j<l2; ++j){
			if(str1.at(i)==str2.at(j)){
				arr[i+1][j+1]=arr[i][j]+1;
			} else{
				arr[i+1][j+1]=arr[i][j+1]>=arr[i+1][j]?arr[i][j+1]:arr[i+1][j];
			}
		}
	}

	cout<<arr[l1][l2]<<endl;
	while(arr[l1][l2]){
		if(arr[l1-1][l2]==arr[l1][l2]) --l1;
		else if(arr[l1][l2-1]==arr[l1][l2]) --l2;
		else {
			lcs+=str1.at(l1-1);
			--l1;
			--l2;
		}
	}
	for(int i=lcs.size()-1; i>=0; --i){
		cout<<lcs.at(i);
	}

	return 0;
}
