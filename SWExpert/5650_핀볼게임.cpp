#include <iostream>

using namespace std;

int n_cnt,n,map[100][100];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct Node{
	int w_cnt;
	int y1=-1,x1=-1,y2=-1,x2=-1;
}typedef Node;

Node nodes[5];

int isOnMap(int y,int x){
	return x>=0 && x<n && y>=0 && y<n;
}
int max(int a,int b){return a>b?a:b;}

int solution(int y,int x,int d){
	int score=0;
	int src_x = x;
	int src_y = y;
	int nx=dx[d]+x;
	int ny=dy[d]+y;

	while(1){
		nx=dx[d]+x;
		ny=dy[d]+y;
		if(!isOnMap(ny,nx)){
			d=(d+2)%4;
			score++;
			x=nx;
			y=ny;
		} else if(ny==src_y && nx==src_x){
			break;	
		} else if(map[ny][nx] == -1){
			break;
		} else if(map[ny][nx]==0){
			x=nx;
			y=ny;
		} else if(map[ny][nx]<=5){
			if(map[ny][nx]==1){
				if(d==0 || d==3){
					d = (d+2)%4;
				} else if(d==1){
					d=0;
				} else if(d==2){
					d=3;
				}
			} else if(map[ny][nx]==2){
				if(d==0 || d==1){
					d = (d+2)%4;
				} else if(d==2){
					d=1;
				} else if(d==3){
					d=0;
				}
			} else if(map[ny][nx]==3){
				if(d==1 || d==2){
					d = (d+2)%4;
				} else if(d==0){
					d=1;
				} else if(d==3){
					d=2;
				}
			} else if(map[ny][nx]==4){
				if(d==2 || d==3){
					d = (d+2)%4;
				} else if(d==0){
					d=3;
				} else if(d==1){
					d=2;
				}
			} else if(map[ny][nx]==5){
				d = (d+2)%4;
			}
			x=nx;
			y=ny;
			score++;
		} else if(map[ny][nx]<=10){
			if(nodes[map[ny][nx]-6].x1 == nx && nodes[map[ny][nx]-6].y1 == ny){
				x = nodes[map[ny][nx]-6].x2;
				y = nodes[map[ny][nx]-6].y2;
			} else {
				x = nodes[map[ny][nx]-6].x1;
				y = nodes[map[ny][nx]-6].y1;
			}
		}
	}
	
	return score; 
}

int main(void){
	int tc,ans;
	cin>>tc;
	for(int t=1;t<=tc;++t){
		ans=0;
		cin>>n;
		for(int i=0;i<5;++i){
			nodes[i].w_cnt=0;
		}
		
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>map[i][j];
				if(map[i][j]>=6){
					if(nodes[map[i][j]-6].w_cnt){
						nodes[map[i][j]-6].x2=j;
						nodes[map[i][j]-6].y2=i;
					} else {
						nodes[map[i][j]-6].x1=j;
						nodes[map[i][j]-6].y1=i;
						nodes[map[i][j]-6].w_cnt=1;
					}
				}
			}
		}

		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(map[i][j]==0){
					for(int d=0;d<4;++d){
						ans = max(ans,solution(i,j,d));
					}
				}
			}
		}
		
		cout<<"#"<<t<<" "<<ans<<endl;
	}
	
	
	return 0;	
}
