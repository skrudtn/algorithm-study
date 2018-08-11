#include <iostream>

using namespace std;


int main(void){
	int N,m,M,T,R,cur,cnt,ans;
	cin>>N>>m>>M>>T>>R;
	cur=m;
	cnt=0;
	ans=1;
	
	if(M-m<T){
		ans=0;
	}
	
	while(N>0 && ans){
		if(cur+T<=M){
			cur+=T;
			N--;	
		} else{
			cur-=R;
			if(cur<m) cur=m;
		}
		cnt++;
	}
	
	if(ans){
		cout<<cnt;
	} else{
		cout<<-1;
	}
	return 0;
}
