#include <stdio.h>

#define BOT 6
#define TOP 1

int n,m,x,y,k;
int map[21][21];

int dx[5]={0,1,-1,0,0};
int dy[5]={0,0,0,-1,1};

int dice[7]={0,};

int isOnMap(int y, int x){
	return x>=0 && x<m && y>=0 && y<n;
}

void copy(){
	if(map[y][x]){
		dice[BOT]=map[y][x];
		map[y][x]=0;
	} else{
		map[y][x]=dice[BOT];
	}
}

void turn(int d){
	int tmp;
	switch(d){
		case 1:
			tmp=dice[3];
			dice[3]=dice[1];
			dice[1]=dice[4];
			dice[4]=dice[6];
			dice[6]=tmp;
			break;
		case 2:
			tmp=dice[1];
			dice[1]=dice[3];
			dice[3]=dice[6];
			dice[6]=dice[4];
			dice[4]=tmp;
			break;
		case 3:
			tmp=dice[2];
			dice[2]=dice[1];
			dice[1]=dice[5];
			dice[5]=dice[6];
			dice[6]=tmp;
			break;
		case 4:
			tmp=dice[6];
			dice[6]=dice[5];
			dice[5]=dice[1];
			dice[1]=dice[2];
			dice[2]=tmp;
			break;
		default:return;
	}
}

void go(int d){
	int nx=x+dx[d];
	int ny=y+dy[d];
	if(isOnMap(ny,nx)){
		turn(d);
		x=nx;
		y=ny;
		copy();
		printf("%d\n",dice[TOP]);
	}

}

int main(void){
	int dir;
	scanf("%d %d %d %d %d",&n,&m,&y,&x,&k); /* x,y ÁÂÇ¥°¡ ¹Ý´ë·Î ÀÔ·ÂµÇ¼­ ¹Ù²ãÁÜ */
	for(int i=0; i<n; ++i){
		for(int j=0; j<m; ++j){
			scanf("%d",&map[i][j]);
		}
	}
	for(int i=0;i<k;++i){
		scanf("%d",&dir);
		go(dir);
	}
	
	return 0;
}
