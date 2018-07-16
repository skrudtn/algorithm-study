#include <iostream>
#include <string>

using namespace std;

int main(void){
	int tc,cnt;
	string str, word;
	for(int t=1; t<=10; ++t){
		cnt=0;
		cin>>tc>>word>>str;
		while(str.find(word) != string::npos){
			str = str.substr(str.find(word)+word.length());
			cnt++;
		}
		cout<<"#"<<tc<<" "<<cnt<<endl;
	}

	return 0;
}
