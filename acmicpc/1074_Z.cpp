#include <cstdio>
#include <cmath>

int n,r,c,ans;

void solve(int s,int y,int x,int cnt){
	if(s==1){
		ans=cnt+y*2+x*1;
		return;
	}
	int w=int(pow(2,s));
	int w2=int(pow(2,s-1));
	int vol=int(pow(w2,2));
	if(w2>y){ // 북 
		if(w2>x){ // 서 
			solve(s-1,y,x,cnt); 
		} else {//동
			solve(s-1,y,x-w/2,cnt+vol); 
		}	
	} else { //남 
		if(w2>x){ // 서
			solve(s-1,y-w/2,x,cnt+vol*2); 
		} else {//동
			solve(s-1,y-w/2,x-w/2,cnt+vol*3);
		}
	}
}
int main(void){
	scanf("%d %d %d",&n,&r,&c);	
	solve(n,r,c,0);
	printf("%d",ans);
	return 0;
}
