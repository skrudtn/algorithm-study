#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int n,l,r,map[50][50],visit[50][50];
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

int abs(int a){return a>=0?a:-a;}

int is_on_map(int y,int x){
	return x>=0 && x<n && y>=0 &&y<n;
}

int bfs(int y,int x, int area){
	int val=map[y][x];
	int cnt=1;
	vector<pair<int,int> > v;
	queue<pair<int,int> > que;
	que.push({y,x});
	v.push_back({y,x});
	visit[y][x] = area;
	
	while(!que.empty()){
		int cy = que.front().first;
		int cx = que.front().second;
		que.pop();
		
		for(int d=0;d<4;++d){
			int nx=dx[d]+cx;
			int ny=dy[d]+cy;
			if(!is_on_map(ny,nx)) continue;
			if(visit[ny][nx]) continue;
			if(abs(map[cy][cx] - map[ny][nx]) >= l 
				&& abs(map[cy][cx] - map[ny][nx]) <= r){
				visit[ny][nx] = area;
				v.push_back({ny,nx});
				que.push({ny,nx});
				val+= map[ny][nx];
				cnt++;
			}
			
		}
	}
	int avg = val/cnt;
	for(int i=0;i<v.size();++i){
		int cy = v[i].first;
		int cx = v[i].second;
		map[cy][cx] = avg;
	}
	
}

void init_visit(){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			visit[i][j]=0;
		}
	}
}

int can_go(){
	return visit[n-1][n-1] != n*n;
}

int main(void){
	int ans;
	cin>>n>>l>>r;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>map[i][j];
		}
	}
	
	int time = 0;
	int area=0;
	while(1){
		area = 0;
		init_visit();
		
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){			
				if(visit[i][j] == 0){
					area++;
					bfs(i,j,area);
				}
			}
		}
		
		if(!can_go()) break;
		time++;
		
	}
	cout<<time<<endl;
	return 0;
}
