#include <iostream>
#include <string>

using namespace std;

char map[8][8];
//
//void display(void){
//	for(int i=0; i<8; ++i){
//		for(int j=0; j<8; ++j){
//			printf("%c",map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

int is_palindrome(string str,int n){
	int ret= 1;
	for(int i=0; i<n/2; ++i){
		if(str.at(i) != str.at(n-i-1)){
			ret=0;
		}
	}
	return ret;
}


int solve(int n){
	int ret=0;
	string tmp;
	for(int i=0; i<8; ++i){
		for(int j=0; j<=8-n; ++j){
			tmp="";
			for(int k=j; k<j+n; ++k){
				tmp += map[i][k];
			}
			if(is_palindrome(tmp,n)) ret++;
		}
	}
	
	
	for(int j=0; j<8; ++j){
		for(int i=0; i<=8-n; ++i){
			tmp="";
			for(int k=i; k<i+n; ++k){
				tmp += map[k][j];
			}
			if(is_palindrome(tmp,n)) ret++;
		}
	}
	
	
	return ret;
}


int main(void){
	int n,ans;
	freopen("input.txt","r",stdin);
	 
	for(int t=1; t<=10; ++t){
		ans=0;
		cin>>n;
		for(int i=0; i<8; ++i){
			for(int j=0; j<8; ++j){
				cin>>map[i][j];
			}
		}
		ans =solve(n);
		cout<<"#"<<t<<" "<<ans<<endl;
	}

	return 0;
}
