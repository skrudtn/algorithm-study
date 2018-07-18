#include <iostream>
#include <sstream>
#include <string>

#define SIZE 16

using namespace std;

struct pos{
	int x;
	int y;
}typedef Pos;

Pos sPos;
Pos dPos;
int ans;
int map[SIZE][SIZE];
int isVisit[SIZE][SIZE];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int str2int(string str){
	int ret;
	stringstream ss(str);
	ss>>ret;
	return ret;
}

void init(void){
	for(int i=0; i<SIZE; ++i){
		for(int j=0; j<SIZE; ++j){
			map[i][j]=0;
			isVisit[i][j]=0;
		}
	}
}

void dfs(int y, int x){
	if(y==dPos.y && x==dPos.x){
		ans=1;
		return;
	}
	int nx,ny;	
	
	for(int d=0; d<4; ++d){
		nx=dx[d]+x;
		ny=dy[d]+y;
		if(map[ny][nx]!=1 && !isVisit[ny][nx]){
			isVisit[ny][nx]=1;
			dfs(ny,nx);
			isVisit[ny][nx]=0;
		}
	}
	
}

int main(void){
	int tc;
	string l,tmp;
	freopen("input.txt","r",stdin);
	for(int t=1;t<=10; ++t){
		cin>>tc;
		ans=0;
		init();
		for(int i=0; i<SIZE; ++i){
			cin>>l;
			for(int j=0;j<SIZE;++j){
				tmp="";
				tmp+=l.at(j);
				map[i][j]=str2int(tmp);
				if(map[i][j]==2){
					sPos.x=j;
					sPos.y=i;
				} else if(map[i][j]==3){
					dPos.x=j;
					dPos.y=i;
				}
			}
		}
		isVisit[sPos.y][sPos.x]=1;
		dfs(sPos.y,sPos.x);
		
		cout<<"#"<<t<<" "<<ans<<endl;
	}
	return 0;
}
