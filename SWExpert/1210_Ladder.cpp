#include <stdio.h>

int data[101][101];
int is_visit[101][101];

void init_visit(void){
	for(int i=1; i<101; ++i){
		for(int j=1; j<101; ++j){
			is_visit[i][j] = 0;
		}
	}
}

int isOnMap(int y, int x){
	return x>0 && x<101 && y>0 && y<101;
}

int solve(int y,int x){
	if(data[y][x] == 2){
		return 1;
	}

	if(isOnMap(y,x-1) && data[y][x-1] && !is_visit[y][x-1]){
		is_visit[y][x-1]=1;
		return solve(y,x-1);
	} else if(isOnMap(y,x+1) && data[y][x+1] && !is_visit[y][x+1]){
		is_visit[y][x+1]=1;
		return solve(y,x+1);
	} else if(isOnMap(y+1,x)){
		is_visit[y+1][x]=1;
		return solve(y+1,x);
	}

	return 0;
}

int main(void){
	int t_c,ans;
	for(int t=1; t<=10; ++t){
		ans=0;
		scanf("%d",&t_c);
		init_visit();
		for(int i=1; i<101; ++i){
			for(int j=1; j<101; ++j){
				scanf("%d",&data[i][j]);
			}
		}
		for(int i=1; i<101; ++i){
			init_visit();
			if(data[1][i]){
				is_visit[1][i]=1;
				if(solve(1,i)) {
					ans=i-1;
					break;
				}
			}
		}
		
		printf("#%d %d\n",t_c, ans);
	}
	return 0;
}
