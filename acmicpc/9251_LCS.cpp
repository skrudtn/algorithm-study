#include <iostream>
#include <string>

using namespace std;

int arr[1001][1001];

int main(void){
	string str1,str2;
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
	printf("%d",arr[l1][l2]);
	return 0;
}
