#include <iostream>
#include <string>
#include <stack>
#include <sstream>

using namespace std;

int isPair(string pre, string cur){
	return (cur==")" && pre == "(") || (cur=="]" && pre =="[");
}

int isOpener(string str){
	return str=="(" || str=="[";
}

int isCloser(string str){
	return str==")" || str=="]";
}

int str2int(string str){
	int i;
	stringstream sst;
	sst.str(str);
	sst>>i;
	return i;
}

string int2str(int i){
	stringstream sst;
	sst<<i;
	return sst.str();
}

int isNumber(string str){
	return str !="[" && str !="]" && str !="(" && str !=")";
}

int isPossible(string str){
	stack<string> stk;
	string cur,pre;
	for(int i=0; i<str.length();++i){
		cur="";
		cur+=str.at(i);
		
		if(isCloser(cur)){
			if(stk.empty()) return 0;
			pre=stk.top();
			if(isPair(pre,cur)) stk.pop();
			else return 0;
		} else {
			stk.push(cur);		
		}

	}
	
	return stk.empty();
}

int solve(string str){
	string cur,pre;
	stack<string> stk;
	for(int i=0; i<str.length();++i){
		cur="";
		cur+=str.at(i);
		if(isOpener(cur)){
			stk.push(cur);
		} else { 
			pre=stk.top();
			stk.pop();
			if(isPair(pre,cur)){
				if(cur==")") stk.push("2");
				else stk.push("3");
			} else if(isNumber(pre)){
				int tmp=str2int(pre);
				while(isNumber(stk.top())){
					tmp+=str2int(stk.top());
					stk.pop();
				}
				if(isPair(stk.top(),cur)){
					stk.pop();
					if(cur==")") {
						stk.push(int2str(2*tmp)); 
					} else {
						stk.push(int2str(3*tmp));
					}
				}
			} 		
		}
	}
	int ans=0;
	while(!stk.empty()){
		ans+=str2int(stk.top());
		stk.pop();
	}
	return ans;
}

int main(void){
	string str;
	cin>>str;
	
	if(isPossible(str)){
		cout<<solve(str);
	} else {
		cout<<0;
	}
	return 0;
}
