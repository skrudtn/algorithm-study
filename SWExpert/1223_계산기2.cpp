#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <deque>

using namespace std;

int isOperator(string tmp){
	return !tmp.compare("+") || !tmp.compare("-") || !tmp.compare("*") || !tmp.compare("/");
}

int str2int(string str){
	int ret;
	stringstream ss(str);
	ss>>ret;
	return ret;
}
string int2str(int i){
	stringstream ss;
	ss<<i;
	return ss.str();
}

int postfix2int(deque <string>dq, int n){
	int ret,tmp,i;
	string s;
	deque<string> tmpDeque;
	
	while(dq.size()!=1){
		for(int i=0; i<dq.size();++i){
			if(isOperator(dq.at(i))){
				if(!dq.at(i).compare("+")){
					tmp=str2int(dq.at(i-2))+str2int(dq.at(i-1));
				} else if(!dq.at(2).compare("-")){
					tmp=str2int(dq.at(i-2))-str2int(dq.at(i-1));
				} else if(!dq.at(i).compare("*")){
					tmp=str2int(dq.at(i-2))*str2int(dq.at(i-1));
				} else if(!dq.at(2).compare("/")){
					tmp=str2int(dq.at(i-2))/str2int(dq.at(i-1));
				}
				for(int j=0;j<=i;++j){
					tmpDeque.push_back(dq.front());
					dq.pop_front();
				}
				s=int2str(tmp);
				dq.push_front(s);
				for(int j=0;j<3;++j){
					tmpDeque.pop_back();
				}
				int size=tmpDeque.size();
				for(int j=0;j<size;++j){
					dq.push_front(tmpDeque.back());
					tmpDeque.pop_back();
				}
				i=0;
			}
		}
	}
	ret = str2int(dq.at(0));
	dq.pop_back();
	return ret;
}

deque<string> getPostifx(string str,int n){
	deque <string>dq;
	stack <string>s;
	string tmp;
	for(int i=0; i<n; ++i){
		tmp="";
		tmp+=str.at(i); 
		if(isOperator(tmp)){
			if(s.empty()){
				s.push(tmp);
			} else{
				if(!tmp.compare("*")||!tmp.compare("/")){
					if(!s.top().compare("+") || !s.top().compare("-")){
						s.push(tmp);
					} else if(!s.top().compare("*") || !s.top().compare("/")){
						dq.push_back(s.top());
						s.pop();
						s.push(tmp);
					}
				} else{	
					while(!s.empty()){
						dq.push_back(s.top());
						s.pop();
					}
					s.push(tmp);
				}
			}
		} else {
			dq.push_back(tmp);
		}
	}
	while(!s.empty()){
		dq.push_back(s.top());
		s.pop();
	}
	return dq;
}

int main(void){
	int n,ans;
	string str,postfix;
	for(int t=1; t<=10; ++t){
		cin>>n;
		cin>>str;
		ans = postfix2int(getPostifx(str,n),n);
		cout<<"#"<<t<<" "<<ans<<endl;	
	}
	return 0;
}
