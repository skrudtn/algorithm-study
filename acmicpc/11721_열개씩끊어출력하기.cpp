#include <iostream>
#include <string>
using namespace std;

int main(void){
	int len;
	string str;
	cin>>str;
	len=str.length();
	cout<<str.at(0);
	for(int i=1; i<len;++i){
		if(!(i%10)) cout<<endl; /* !i%10과 !(i%10)은 다르다 */
		cout<<str.at(i);
	}

	return 0;
}
