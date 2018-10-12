#include <iostream>
#include <vector>
#include <queue>

using namespace std;

#define EMPTY 0
#define DEAD 1
#define ACTIVE 2
#define INACTIVE 3 

int n,m,k;
struct Cell{
	int y,x;
	int state;
	int val;
}typedef Cell;

Cell map[300+50+300][300+50+300];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int get_ans(){
	int ret=0;
	for(int i=300-k;i<300+n+k;++i){
		for(int j=300-k;j<300+m+k;++j){
			if(map[i][j].state == INACTIVE || map[i][j].state == ACTIVE){
				ret++;
			}
		}
	}
	
	return ret;
}

void init(){
	for(int i=300-k;i<300+n+k;++i){
		for(int j=300-k;j<300+m+k;++j){
			map[i][j].val = 0;
			map[i][j].state = EMPTY;
		}
	}
}

queue<Cell> fill(queue<Cell> &actives){
	queue<Cell> new_cells;
	int size = actives.size();
	for(int i=0;i<size;++i){
		Cell cur = actives.front();
		actives.pop();
		int x=cur.x;
		int y=cur.y;
		
		for(int d=0;d<4;++d){
			int ny=dy[d]+y;
			int nx=dx[d]+x;
			
			if(map[ny][nx].state == EMPTY){
				if(map[ny][nx].val < map[y][x].val){
					map[ny][nx].val = map[y][x].val;
				}
			}
		}
		cur.val--;
		if(cur.val == 0){
			map[y][x].state = DEAD;
		} else {
			actives.push(Cell{y,x,ACTIVE,cur.val});
		}
				
	}
	
	for(int i=300-k;i<300+n+k;++i){
		for(int j=300-k;j<300+m+k;++j){
			if(map[i][j].state == EMPTY && map[i][j].val != 0){
				new_cells.push(Cell{i,j,INACTIVE,map[i][j].val});
				map[i][j].state = INACTIVE;
			}
		}
	}
	
	
	return new_cells;
}

void solution(queue<Cell> &actives, queue<Cell> &inactives, int cnt){
	if(cnt == k){
		return; 
	}
	
	queue<Cell> new_cells = fill(actives);
	
	int size = inactives.size();
	for(int i=0;i<size;++i){
		Cell cur = inactives.front();
		inactives.pop();
		int y=cur.y;
		int x=cur.x;
		cur.val--;
		
		if(cur.val == 0){
			map[y][x].state = ACTIVE;
			actives.push(Cell{y,x,ACTIVE,map[y][x].val});
		} else{
			map[y][x].state = INACTIVE;
			inactives.push(Cell{y,x,INACTIVE,cur.val});
		}
	}
	
	while(!new_cells.empty()){
		Cell tmp = new_cells.front();
		new_cells.pop();
		int y=tmp.y;
		int x=tmp.x;
		map[y][x].state = INACTIVE;
		inactives.push(tmp);
	}
	
	solution(actives,inactives,cnt+1);
	
}

int main(void){
	int tc,tmp,ans;
	scanf("%d",&tc);
	for(int t=1;t<=tc;++t){
		scanf("%d %d %d",&n,&m,&k);
		init();
		ans=0;
		queue<Cell> actives;
		queue<Cell> inactives;
	
		for(int i=300;i<300+n;++i){
			for(int j=300;j<300+m;++j){
				scanf("%d",&tmp);
				map[i][j].y = i; map[i][j].x = j;
				map[i][j].val = tmp;
				if(tmp != 0){
					map[i][j].state = INACTIVE;
					inactives.push(Cell{i,j,INACTIVE,tmp});
				} else{
					map[i][j].val = 0;
					map[i][j].state = EMPTY;
				}
			}
		}
		
		solution(actives, inactives, 0);
		ans = get_ans();
		printf("#%d %d\n",t,ans);
	}
	return 0;
}
