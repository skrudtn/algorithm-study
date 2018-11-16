#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n,m,r,c,l,ans,map[50][50],visit[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

queue<pair<int,int> > que;

int get_ans(){
	int ret=0;
	for(int i=0;i<n;++i){
		for(int j=0;j<m;++j){
			if(visit[i][j] == 1) ret++;
		}
	}
	return ret;
}

int is_on_map(int y,int x){
	return x>=0 && x<m && y>=0 && y<n;
}

void move(int y,int x){
	switch(map[y][x]){
		case 1:
			for(int d=0;d<4;++d){
				int ny = dy[d] + y;
				int nx = dx[d] + x;
				if(!is_on_map(ny,nx)) continue;
				if(visit[ny][nx] == 1) continue;
				if(map[ny][nx] == 0) continue;
				if(d==0){
					if(map[ny][nx] == 2 ||map[ny][nx] == 4 || map[ny][nx] == 5) continue;
				} else if(d==1){
					if(map[ny][nx] == 3 ||map[ny][nx] == 5 || map[ny][nx] == 6) continue;
				} else if(d==2){
					if(map[ny][nx] == 2 ||map[ny][nx] == 6 || map[ny][nx] == 7) continue;
				} else if(d==3){
					if(map[ny][nx] == 3 ||map[ny][nx] == 4 || map[ny][nx] == 7) continue;
				}
				visit[ny][nx] = 1;
				que.push({ny,nx});
			}
			break;
		case 2:
			for(int d=0;d<4;++d){
				if(d==0 || d==2) continue;
				int ny = dy[d] + y;
				int nx = dx[d] + x;
				if(!is_on_map(ny,nx)) continue;
				if(visit[ny][nx] == 1) continue;
				if(map[ny][nx] == 0) continue;
				if(d==0){
					if(map[ny][nx] == 2 ||map[ny][nx] == 4 || map[ny][nx] == 5) continue;
				} else if(d==1){
					if(map[ny][nx] == 3 ||map[ny][nx] == 5 || map[ny][nx] == 6) continue;
				} else if(d==2){
					if(map[ny][nx] == 2 ||map[ny][nx] == 6 || map[ny][nx] == 7) continue;
				} else if(d==3){
					if(map[ny][nx] == 3 ||map[ny][nx] == 4 || map[ny][nx] == 7) continue;
				}
				visit[ny][nx] = 1;
				que.push({ny,nx});
			}
			break;
		case 3:
			for(int d=0;d<4;++d){
				if(d==1 || d==3) continue;
				int ny = dy[d] + y;
				int nx = dx[d] + x;
				if(!is_on_map(ny,nx)) continue;
				if(visit[ny][nx] == 1) continue;
				if(map[ny][nx] == 0) continue;
				if(d==0){
					if(map[ny][nx] == 2 ||map[ny][nx] == 4 || map[ny][nx] == 5) continue;
				} else if(d==1){
					if(map[ny][nx] == 3 ||map[ny][nx] == 5 || map[ny][nx] == 6) continue;
				} else if(d==2){
					if(map[ny][nx] == 2 ||map[ny][nx] == 6 || map[ny][nx] == 7) continue;
				} else if(d==3){
					if(map[ny][nx] == 3 ||map[ny][nx] == 4 || map[ny][nx] == 7) continue;
				}
				visit[ny][nx] = 1;
				que.push({ny,nx});
			}
			break;
		case 4:
			for(int d=0;d<4;++d){
				if(d==1 || d==2) continue;
				int ny = dy[d] + y;
				int nx = dx[d] + x;
				if(!is_on_map(ny,nx)) continue;
				if(visit[ny][nx] == 1) continue;
				if(map[ny][nx] == 0) continue;
				if(d==0){
					if(map[ny][nx] == 2 ||map[ny][nx] == 4 || map[ny][nx] == 5) continue;
				} else if(d==1){
					if(map[ny][nx] == 3 ||map[ny][nx] == 5 || map[ny][nx] == 6) continue;
				} else if(d==2){
					if(map[ny][nx] == 2 ||map[ny][nx] == 6 || map[ny][nx] == 7) continue;
				} else if(d==3){
					if(map[ny][nx] == 3 ||map[ny][nx] == 4 || map[ny][nx] == 7) continue;
				}
				visit[ny][nx] = 1;
				que.push({ny,nx});
			}
			break;
		case 5:
			for(int d=0;d<4;++d){
				if(d==2 || d==3) continue;
				int ny = dy[d] + y;
				int nx = dx[d] + x;
				if(!is_on_map(ny,nx)) continue;
				if(visit[ny][nx] == 1) continue;
				if(map[ny][nx] == 0) continue;
				if(d==0){
					if(map[ny][nx] == 2 ||map[ny][nx] == 4 || map[ny][nx] == 5) continue;
				} else if(d==1){
					if(map[ny][nx] == 3 ||map[ny][nx] == 5 || map[ny][nx] == 6) continue;
				} else if(d==2){
					if(map[ny][nx] == 2 ||map[ny][nx] == 6 || map[ny][nx] == 7) continue;
				} else if(d==3){
					if(map[ny][nx] == 3 ||map[ny][nx] == 4 || map[ny][nx] == 7) continue;
				}
				visit[ny][nx] = 1;
				que.push({ny,nx});
			}
			break;
		case 6:
			for(int d=0;d<4;++d){
				if(d==0 || d==3) continue;
				int ny = dy[d] + y;
				int nx = dx[d] + x;
				if(!is_on_map(ny,nx)) continue;
				if(visit[ny][nx] == 1) continue;
				if(map[ny][nx] == 0) continue;
				if(d==0){
					if(map[ny][nx] == 2 ||map[ny][nx] == 4 || map[ny][nx] == 5) continue;
				} else if(d==1){
					if(map[ny][nx] == 3 ||map[ny][nx] == 5 || map[ny][nx] == 6) continue;
				} else if(d==2){
					if(map[ny][nx] == 2 ||map[ny][nx] == 6 || map[ny][nx] == 7) continue;
				} else if(d==3){
					if(map[ny][nx] == 3 ||map[ny][nx] == 4 || map[ny][nx] == 7) continue;
				}
				visit[ny][nx] = 1;
				que.push({ny,nx});
			}
			break;
		case 7:
			for(int d=0;d<4;++d){
				if(d==0 || d==1) continue;
				int ny = dy[d] + y;
				int nx = dx[d] + x;
				if(!is_on_map(ny,nx)) continue;
				if(visit[ny][nx] == 1) continue;
				if(map[ny][nx] == 0) continue;
				if(d==0){
					if(map[ny][nx] == 2 ||map[ny][nx] == 4 || map[ny][nx] == 5) continue;
				} else if(d==1){
					if(map[ny][nx] == 3 ||map[ny][nx] == 5 || map[ny][nx] == 6) continue;
				} else if(d==2){
					if(map[ny][nx] == 2 ||map[ny][nx] == 6 || map[ny][nx] == 7) continue;
				} else if(d==3){
					if(map[ny][nx] == 3 ||map[ny][nx] == 4 || map[ny][nx] == 7) continue;
				}
				visit[ny][nx] = 1;
				que.push({ny,nx});
			}
			break;
	}
}

void solution(){
	for(int time = 1; time<l;++time){
		int size=que.size();
		for(int s=0;s<size;++s){
			int y = que.front().first;
			int x = que.front().second;
			que.pop();
			move(y,x);
		}
	}
}

int main(void){
	int tc;
	
	cin >> tc;
	
	for(int t=1;t<=tc;++t){
		
		cin>>n>>m>>r>>c>>l;
		while(!que.empty()) que.pop();
		que.push({r,c});
		
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				visit[i][j] = 0;
			}
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				cin>>map[i][j];
			}
		}
		visit[r][c] = 1;
		solution();
		cout<<"#"<<t<<" "<<get_ans()<<endl;
	}
	
	return 0;
}
