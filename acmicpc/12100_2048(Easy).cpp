#include <iostream>
#include <vector>

using namespace std;

int ans,n;

int _max(int a,int b){return a>b?a:b;}

int getMaxVal(vector<vector<int> > map){
	int ret=0;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ret=_max(ret,map[i][j]);
		}
	}
	return ret;
}

vector<vector<int> > push(int d,vector<vector<int> > map){
	vector<int> v;
	switch(d){
		case 0:
			for(int i=1;i<=n; ++i){
				v.clear();
				for(int j=n;j>=1;--j){
					if(map[i][j]){
						v.push_back(map[i][j]);
						map[i][j]=0;
					}
				}
				int cur=n;
				int size=v.size();
				while(size>1){
					if(v[0] == v[1]){
						map[i][cur]=v[0]*2;
						v.erase(v.begin());
						v.erase(v.begin());
						size-=2;
					} else {
						map[i][cur]=v[0];
						v.erase(v.begin());
						size-=1;
					}
					cur--;
				}
				if(!v.empty()){
					map[i][cur]=v[0];
					v.erase(v.begin());
				}
			}

			break;
		case 1:
			for(int j=1;j<=n; ++j){
				v.clear();
				for(int i=n;i>=1;--i){
					if(map[i][j]){
						v.push_back(map[i][j]);
						map[i][j]=0;
					}
				}
				int cur=n;
				int size=v.size();
				while(size>1){
					if(v[0] == v[1]){
						map[cur][j]=v[0]*2;
						v.erase(v.begin());
						v.erase(v.begin());
						size-=2;
					} else {
						map[cur][j]=v[0];
						v.erase(v.begin());
						size-=1;
					}
					cur--;
				}
				if(!v.empty()){
					map[cur][j]=v[0];
					v.erase(v.begin());
				}
			}
			break;
		case 2:
			for(int i=1;i<=n; ++i){
				v.clear();
				for(int j=1;j<=n;++j){
					if(map[i][j]){
						v.push_back(map[i][j]);
						map[i][j]=0;
					}
				}
				int cur=1;
				int size=v.size();
				while(size>1){
					if(v[0] == v[1]){
						map[i][cur]=v[0]*2;
						v.erase(v.begin());
						v.erase(v.begin());
						size-=2;
					} else {
						map[i][cur]=v[0];
						v.erase(v.begin());
						size-=1;
					}
					cur++;
				}
				if(!v.empty()){
					map[i][cur]=v[0];
					v.erase(v.begin());
				}
			}
			break;
		case 3:
			for(int j=1;j<=n; ++j){
				v.clear();
				for(int i=1;i<=n;++i){
					if(map[i][j]){
						v.push_back(map[i][j]);
						map[i][j]=0;
					}
				}
				int cur=1;
				int size=v.size();
				while(size>1){
					if(v[0] == v[1]){
						map[cur][j]=v[0]*2;
						v.erase(v.begin());
						v.erase(v.begin());
						size-=2;
					} else {
						map[cur][j]=v[0];
						v.erase(v.begin());
						size-=1;
					}
					cur++;
				}
				if(!v.empty()){
					map[cur][j]=v[0];
					v.erase(v.begin());
				}
			}
			break;
	}
	return map;
}

void dfs(int cnt,vector<vector<int> > map){
	if(cnt==5){
		ans=_max(ans,getMaxVal(map));
		return;
	}
	for(int d=0;d<4;++d){
		vector<vector<int> > copyMap(21,vector<int>(21,0));
		for(int i=1;i<=n;++i){
			for(int j=1;j<=n;++j){
				copyMap[i][j]=map[i][j];
			}
		}		
		copyMap = push(d,copyMap);
		dfs(cnt+1,copyMap);
	}
}

int main(void){
	vector<vector<int> > map(21, vector<int>(21,0));
	ans=0;
	cin >> n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>map[i][j];
		}
	}
	
	dfs(0,map);
	cout<<ans;
	return 0;
}
