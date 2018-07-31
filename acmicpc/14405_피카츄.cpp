#include <iostream>
#include <string>

using namespace std;

string chk[3]={"pi","ka","chu"};

int main(void){
	int s,len;
	string str;
	cin>>str;
	len=str.length();
	while(len){
		for(int j=0;j<3;j++){
			s=str.find(chk[j]);
			if(!s){
				str=str.substr(chk[j].length(),str.length());
				len-=chk[j].length();
				break;
			}
			if(j==2){
				cout<<"NO";
				return 0;
			}
		}
	}
	
	cout<<"YES";
}
