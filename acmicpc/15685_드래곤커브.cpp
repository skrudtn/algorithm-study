#include <iostream>
#include <vector>

using namespace std;

int n,map[102][102];

int dx[4]={1,0,-1,0};
int dy[4]={0,-1,0,1};
void dfs(int ey,int ex,int d, int g,int limit,vector<pair<int,int> > v){
	if(g==limit){
		return;
	}
	int x2,y2,ex2,ey2,size;
	size=v.size();
	for(int i=0;i<size;++i){
		y2=v[i].first;
		x2=v[i].second;
		if(y2==ey && x2==ex) continue;
		x2-=ex;
		y2-=ey;
		int tmp=x2;
		x2=-y2;
		y2=tmp;
		x2+=ex;
		y2+=ey;
		if(i==0) {
			ex2=x2;
			ey2=y2;
		}
		if(y2<0 || y2>100 || x2<0 || x2>100) continue;
		v.push_back({y2,x2});
		map[y2][x2]=1;
	}
	
	dfs(ey2,ex2,d,g+1,limit,v);
}

int solve(){
	int ret;
	for(int i=0;i<100;++i){
		for(int j=0;j<100;++j){
			if(map[i][j]==1 && map[i+1][j]==1 &&map[i][j+1]==1 && map[i+1][j+1]==1){
				ret+=1;
			}
		}
	}
	return ret;
}

int main(void){
	cin>>n;
	for(int i=1;i<=n;++i){
		int x,y,d,g;
		vector<pair<int,int> > v;

		cin>>x>>y>>d>>g;

		int ex=x+dx[d];
		int ey=y+dy[d];
		map[y][x]=1;
		map[ey][ex]=1;
		v.push_back({y,x});
		v.push_back({ey,ex});
		dfs(ey,ex,d,0,g,v);
	}
	cout<<solve();
}
