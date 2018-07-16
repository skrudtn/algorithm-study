#include <stdio.h>

int data[101][101];
int is_visit[101][101];
int result,ans;

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

void solve(int s,int y,int x,int cnt){
	if(y==100){
		if(result>cnt) {
			result=cnt;
			ans=s;
		}
	}

	if(isOnMap(y,x-1) && data[y][x-1] && !is_visit[y][x-1]){
		is_visit[y][x-1]=1;
		solve(s,y,x-1,cnt+1);
	} else if(isOnMap(y,x+1) && data[y][x+1] && !is_visit[y][x+1]){
		is_visit[y][x+1]=1;
		solve(s,y,x+1,cnt+1);
	} else if(isOnMap(y+1,x)){
		is_visit[y+1][x]=1;
		solve(s,y+1,x,cnt+1);
	}

	return;
}

int main(void){
	int t_c;
	for(int t=1; t<=10; ++t){
		result=0;
		scanf("%d",&t_c);
		init_visit();
		result =100*100;
		for(int i=1; i<101; ++i){
			for(int j=1; j<101; ++j){
				scanf("%d",&data[i][j]);
			}
		}
		for(int i=1; i<101; ++i){
			init_visit();
			if(data[1][i]){
				is_visit[1][i]=1;
				solve(i,1,i,1);
			}
		}
		
		printf("#%d %d\n",t_c, ans-1);
	}
	return 0;
}
