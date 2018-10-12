#include <iostream>
#include <string>
#include <map>
#include <cmath>

using namespace std;

int n,k;

int hex2dec(string str){
	int ret=0;
	for(int i=0;i<str.length();++i){
		int j;
		if(str.at(i) <= 59){
			j = str.at(i)-'1'+1;
		} else {
			j = str.at(i)-'A'+10;
		}
		ret += j*int(pow(16,str.length()-1-i));
	}
	return ret;
}

int solution(string str){
	int ret;
	int rotate_cnt = n/4;
	map<int,int,greater<int> > result;
	
	for(int i=0;i<rotate_cnt;++i){
		for(int j=0;j<4;++j){
			string tmp = "";
			for(int z=0;z<rotate_cnt;++z){
				tmp += str.at(z+j*rotate_cnt);
			}
			int dec = hex2dec(tmp);
			result[dec] = 1;
		}
		char c = str.at(str.length()-1);
		str = c+str;
		str.erase(str.end()-1);
	}
	
	int i=1;
	map<int,int>::iterator iter;
	for(iter = result.begin(); iter != result.end(); ++iter){
		if(i==k){
			ret = (*iter).first;
			break;
		}
		i++;
	}
	
	return ret;
}

int main(void){
	int tc;
	string str;
	cin>>tc;
	
	for(int t=1;t<=tc;++t){
		cin>>n>>k;
		cin>>str;
		cout<<"#"<<t<<" "<<solution(str)<<endl;
	}
	
	return 0;
}
