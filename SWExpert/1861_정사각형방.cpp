#include <stdio.h>

int map[1001][1001];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

int N;
int resultIdx;
int resultValue;

bool isOnMap(int y, int x){
	return x>=0 && x<N && y>=0 && y<N;
}

int min(int a, int b){
	return a<b?a:b;
}

void solution(int y, int x, int idx, int cnt){
	for(int d=0;d<4;d++){
		if(isOnMap(y+dy[d], x+dx[d]) && map[y][x]+1 == map[y+dy[d]][x+dx[d]]){
			solution(y+dy[d],x+dx[d],idx,++cnt);
		}
	}
	if(resultValue<=cnt){
		if(resultValue==cnt){
			resultIdx = min(resultIdx,idx);
		} else{
			resultIdx = idx;
		}
		resultValue = cnt;
	}
}

int main(void){
	int tc;
	int T;
	
	scanf("%d",&T);
	for(tc=1; tc<=T; ++tc){
		resultValue=0;
		resultIdx=987654321;
		scanf("%d",&N);
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				scanf("%d", &map[i][j]);
			}
		}
		for(int i=0; i<N; ++i){
			for(int j=0; j<N; ++j){
				solution(i,j,map[i][j],1);
			}
		}
		
		printf("#%d %d %d\n",tc,resultIdx,resultValue);
	}
	
	return 0;
}
