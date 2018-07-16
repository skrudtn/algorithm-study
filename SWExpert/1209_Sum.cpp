#include <stdio.h>

int map[101][101];

int _max(int a, int b){
	return a>b?a:b;
}
int solve(){
	int ret=0,sub_sum=0;
	
	for(int i=1; i<101; ++i){
		sub_sum=0;
		for(int j=1; j<101; ++j){
			sub_sum += map[i][j];
		}
		ret = _max(ret,sub_sum);
	}
	
	for(int i=1; i<101; ++i){
		sub_sum=0;
		for(int j=1; j<101; ++j){
			sub_sum += map[j][i];
		}
		ret = _max(ret,sub_sum);
	}
	
	sub_sum=0;
	for(int d=1; d<101; ++d){
		sub_sum+=map[d][d];
	}
	ret = _max(ret,sub_sum);
	
	
	sub_sum=0;
	for(int d=1; d<101; ++d){
		sub_sum+=map[101-d][d];
	}
	ret = _max(ret,sub_sum);
	
	return ret;
}

int main(void){
	int ans,t_c;
	freopen("input.txt","r",stdin);

	for(int t=1; t<=10; ++t){
		ans=0;
		scanf("%d",&t_c);
		for(int i=1; i<101; ++i){
			for(int j=1; j<101; ++j){
				scanf("%d",&map[i][j]);
			}
		}
		
		ans = solve();
		printf("#%d %d\n", t,ans);
	
	}

	return 0;
}
