#include <stdio.h>
#include <vector>
int map[17][17];

using namespace std;

int N;
double result;

double max(double a, double b){
	return a>b?a:b;
}

void solve(int y,int x, double value, vector<int> v){
	// 끝까지 가면 리턴 
	if(y==N){
		result=max(result,value);
		return;
	}
	v[x]=1;
		
	for(int vx=1; vx<=N; ++vx){
		if(v[vx]==0&&value*map[y+1][vx]*0.01>result && value*map[y+1][vx]*0.01>0.0000005){
			
			solve(y+1, vx,value*map[y+1][vx]*0.01, v);
		}
	}
}

int main(void){
	int tc,T;
	
	scanf("%d",&T);
	
	for(tc=1; tc<=T; ++tc){
		result=0.0;
		scanf("%d",&N);
		for(int i=1;i<=N;++i){
			for(int j=1;j<=N;++j){
				scanf("%d",&map[i][j]);
			}
		}
		
		for(int x=1; x<=N; ++x){
			vector<int> v(17);
			if(map[1][x]!=0){
				solve(1,x,map[1][x]*(0.01),v);
			}
		}
		
		printf("#%d %.6lf\n", tc, result*(100.0));
	}
	
	return 0;	
}
