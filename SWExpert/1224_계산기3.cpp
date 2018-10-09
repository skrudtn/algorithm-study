#include<iostream>
#include<string>
#include<vector>
#include<stack>
#include <sstream>

using namespace std;

int isNumber(string str){
	return str.compare("+") != 0 &&
	str.compare("-") != 0 &&
	str.compare("*") != 0 &&
	str.compare("/") != 0 &&
	str.compare("(") != 0 &&
	str.compare(")") != 0 ;
}

int str2int (const string &str) {
  stringstream ss(str);
  int num;
  if((ss >> num).fail()){}
  return num;
}

int main(void) {
    int tc;
    string str;
	tc=10;
    for (int t = 1; t <= tc; ++t) {
    	int len;
        stack<string> s;
        stack<int> s2;
        vector<string> v;
        cin>>len>>str;
        vector<string> strs(len,"");    	
    	
        for (int i = 0; i < len; i++) {
			strs[i] += str.at(i);
		}
		
        for (int i = 0; i < strs.size(); i++) {
            string c = strs[i];
			if(c.compare("-")==0){
				c="+";
				strs[i+1] = "-"+strs[i+1];
			}
            if (isNumber(c)) {
                v.push_back(c);
            }
            else {
                if (c.compare("(") == 0) {
                    s.push(c);
                }
                else if (c.compare(")") == 0) {
					while (s.top().compare("(")!=0) {
                        v.push_back(s.top());
                        s.pop();
                    }
                    s.pop();
                    
                }
                else if (c.compare("+")==0) {
					if (!s.empty()) {
                        while (s.top().compare("*")==0 || s.top().compare("/")==0) {
							v.push_back(s.top());
                            s.pop();
                            if(s.size()==0) break;
                        }
                    }
					s.push(c);
                }
                else if (c.compare("/")==0 || c.compare("*")==0) {
					if (!s.empty()) {
						while (s.top().compare("/")==0 || s.top().compare("*")==0) {
							v.push_back(s.top());
	                        s.pop();
	                        if(s.size()==0) break;
	                    }
	                }
                    s.push(c);
                }
            }
	    }
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }

        for (int i=0;i<v.size();++i) {
        	string c = v[i];
        	if(c.compare("") == 0) continue;
            if (isNumber(c)) {
                s2.push(str2int(c));
            } else {
                if (c.compare("+")==0) {
                    int num1 = s2.top();
                    s2.pop();
                    int num2 = s2.top();
                    s2.pop();
                    s2.push(num1 + num2);
                }
                else if (c.compare("*")==0) {
                    int num1 = s2.top();
                    s2.pop();
                    int num2 = s2.top();
                    s2.pop();
					s2.push(num1 * num2);
                }
                else if (c.compare("/")==0) {
                    int num1 = s2.top();
                    s2.pop();
                    int num2 = s2.top();
                    s2.pop();
                    s2.push(num2 / num1);
                }
            }
    }

    cout<<"#"<<t<<" "<<s2.top() <<endl;
       
    }
}
