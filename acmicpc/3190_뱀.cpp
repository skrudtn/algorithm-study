#include <iostream>
#include <utility>
#include <list>
using namespace std;

int n,k,l,dir,map[101][101];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct pos{
	int x,y;
}typedef Pos;

struct s{
	int x;
	char c;
}typedef State;

Pos apple[101];
State state[101];

list <pair<int,int> > snake;

int isOnMap(int y, int x){return y>0 && y<=n && x>0 && x<=n;}
int isCrash(int y, int x){
	for(list<pair<int,int> >::iterator iter=snake.begin();iter!=snake.end();++iter){
		if((*iter).first==y && (*iter).second==x){
			return 1;
		}
	}
	return 0;
}

int eatApple(int y,int x){
	for(int i=1; i<=k; ++i){
		if(y==apple[i].y && x==apple[i].x){
			apple[i].y=-1;
			apple[i].x=-1;
			map[y][x]=0;
			return 1;
		}
	}
	return 0;
}

int solve(void){
	int ret=0;
	int s=1;
	int x=state[s].x;
	char c=state[s].c;
	while(1){
		ret+=1;
		int ny=(*snake.begin()).first+dy[dir];
		int nx=(*snake.begin()).second+dx[dir];
		
		if(!isOnMap(ny,nx)) break;
		if(isCrash(ny,nx)) break;
		
		snake.push_front({ny,nx});
		if(!eatApple(ny,nx)){
			snake.pop_back();
		}
		if(ret==x){
			if(s<=l){
				if(c=='D') dir=(dir+1)%4;
				else {
					if(dir==0) dir=3;
					else dir-=1;
				}
				s++;
				x=state[s].x;
				c=state[s].c;
			}
		}
	}
	
	return ret;
}

int main(void){
	int x;
	char c;

	snake.push_back({1,1});
	dir=0;
	cin>>n>>k;
	for(int i=1;i<=k;++i){
		int a,b;
		cin>>a>>b;
		apple[i].y=a;
		apple[i].x=b;
	}
	cin>>l;
	for(int i=1;i<=l;++i){
		cin>>state[i].x>>state[i].c;
	}
	cout<<solve();
	return 0;
}
