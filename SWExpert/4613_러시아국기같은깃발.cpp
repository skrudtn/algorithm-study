#include <iostream>

#define W 1
#define B 2
#define R 3

using namespace std;

int n,m,map[51][51];

int _min(int a,int b){return a<b?a:b;}

int getCnt(int w,int r,int b){
	int ret=0;
	for(int i=1;i<=w;++i){
		for(int j=1;j<=m;++j){
			if(map[i][j] != W){
				ret++;
			}
		}
	}
	for(int i=w+1;i<=w+b;++i){
		for(int j=1;j<=m;++j){
			if(map[i][j] != B){
				ret++;
			}
		}
	}

    for(int i=w+b+1;i<=w+r+b;++i){
		for(int j=1;j<=m;++j){
			if(map[i][j] != R){
				ret++;
			}
		}
	}
	return ret;
}

int solve(void){
	int r,ret;
	ret=n*m;
	for(int w=1;w<=n-2;++w){
		for(int b=1;b<=n-(w+1);++b){
			r=n-(w+b);
			ret=_min(ret,getCnt(w,r,b));
		}
	}
	
	
	
	return ret;
}

int main(void){
	int tc;
	char c;
	scanf("%d",&tc);
	for(int t=1;t<=tc;++t){
		scanf("%d %d",&n,&m);
		for(int i=1;i<=n;++i){
			for(int j=1;j<=m;++j){
				scanf(" %1c",&c);
				if(c=='W'){
					map[i][j]=W;
				} else if(c=='R'){
					map[i][j]=R;
				} else {
					map[i][j]=B;
				}
			}
		}
		cout<<"#"<<t<<" "<<solve()<<endl;
	
	}
	return 0;
}
