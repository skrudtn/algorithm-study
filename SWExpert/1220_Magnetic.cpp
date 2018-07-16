#include <stdio.h>

#define SIZE 100

struct node{
	int x;
	int y;
}typedef Node;

Node red[SIZE*SIZE];
Node blue[SIZE*SIZE];
int r,b;

int map[SIZE][SIZE];
//
//void display(void){
//	for(int i=0; i<SIZE; ++i){
//		for(int j=0; j<SIZE; ++j){
//			printf("%d",map[i][j]);
//		}
//		printf("\n");
//	}
//	printf("\n");
//}

int isOnMap(int y, int x){
	return x>=0 && x<SIZE && y>=0 &&y<SIZE;
}

int get_deadlock(){
	int nx,ny,ret=0;
	for(int i=0; i<r; ++i){
		nx=red[i].x;
		ny=red[i].y;
		if(isOnMap(ny+1,nx) && map[ny+1][nx] == 2)
			ret++;
	
	}
	return ret;
}


void solve(){
	int nx,ny;
	for(int cycle=0; cycle<SIZE; ++cycle){
		for(int i=0; i<r; ++i){
			nx=red[i].x;
			ny=red[i].y;
			if(isOnMap(ny+1,nx) && map[ny+1][nx] == 0){
				red[i].y+=1;
				map[ny][nx]=0;
				map[ny+1][nx]=1;
			} else if(ny == SIZE){
				map[ny][nx]=0;
			}
		}
		
		for(int i=0; i<b; ++i){
			nx=blue[i].x;
			ny=blue[i].y;
			if(isOnMap(ny-1,nx) && map[ny-1][nx] == 0){
				blue[i].y-=1;
				map[ny][nx]=0;
				map[ny-1][nx]=2;
			} else if(ny == 0){
				map[ny][nx]=0;
			}
			
		}
	}
}		

int main(void){
	int ans,n;
	freopen("input.txt","r",stdin);
//	freopen("sample_input.txt","r",stdin);

	for(int t=1; t<=10; ++t){
		ans=r=b=0;
		scanf("%d",&n);
		for(int i=0; i<SIZE; ++i){
			for(int j=0; j<SIZE; ++j){
				scanf("%d",&map[i][j]);
				if(map[i][j] == 1){
					red[r].x=j;
					red[r].y=i;
					r++;
				} else if(map[i][j]==2){
					blue[b].x=j;
					blue[b].y=i;
					b++;
				}
			}
		}
//		display();
		solve();
//		display();
		ans = get_deadlock();
		printf("#%d %d\n",t,ans);	
	}

	return 0;
}
