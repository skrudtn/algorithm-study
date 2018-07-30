#include <iostream>
#include <algorithm>
using namespace std;

int l,c,result[16],arr[16];
char vowels[5] = {'a','e','i','o','u'};

int isVowel(int i){
	char ch=char(i+97);
	for(int i=0;i<5;++i){
		if(ch==vowels[i]) return 1;
	}
	return 0;
}
	
void print(){
	int vCnt, cCnt;
	vCnt=cCnt=0;
	for(int i=1;i<=l;++i){
		if(isVowel(arr[result[i]])) vCnt++;
		else cCnt++;
	}
	if(vCnt>=1 && cCnt>=2){	
		for(int i=1;i<=l;++i){
			cout<<char(arr[result[i]]+97);
		}
		cout<<endl;
	}
}

void solve(int idx, int cnt){
	if(cnt==l+1){
		print();
		return;
	} else if(idx==c+1){
		return;
	}
	
	result[cnt]=idx;
	solve(idx+1,cnt+1);
	result[cnt]=0;
	solve(idx+1,cnt);
	
}

int main(void){
	char tmp;
	cin>>l>>c;
	for(int i=1; i<=c; ++i){
		cin>>tmp;
		arr[i]=tmp-97;
	}
	sort(arr+1,arr+1+c);
	solve(1,1);
	return 0;
}
