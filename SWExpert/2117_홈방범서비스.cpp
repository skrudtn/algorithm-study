#include <iostream>
#include <vector>

using namespace std;

int n,m,ans,map[20][20];

struct Node{
	int y,x;
}typedef Node;
vector<Node> v;

int max(int a,int b){return a>b?a:b;}
int min(int a,int b){return a<b?a:b;}
int abs(int a){return a>=0?a:-a;}

int is_on_map(int y,int x){
	return x>=0 && x<n && y>=0 && y<n;
}

int get_distance(int y1,int x1, int y2, int x2){
	return abs(y1-y2) + abs(x1-x2);
}

int get_cost(int k){
	return k*k+(k-1)*(k-1);
}

void get_profit(int y, int x, int k){
	int cnt=0;
	for(int i=0;i<v.size();++i){
		int y2 = v[i].y;
		int x2 = v[i].x;
		
		if(get_distance(y,x,y2,x2) <= k-1) {
			cnt++;
		}
	}
	
	if(cnt*m-get_cost(k) >=0){
		ans = max(ans,cnt);
	}
}

void solution(){
	for(int k=1;k<=n+1;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				get_profit(i,j,k);
			}
		}
	}
}

int main(void){
	int tc;
	
	cin>>tc;
	

	for(int t=1;t<=tc;++t){
		ans=0;
		v.clear();
		cin>>n>>m;
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				cin>>map[i][j];
				if(map[i][j] == 1){
					v.push_back(Node{i,j});
				}
			}
		}
		solution();
		
		cout<<"#"<<t<<" "<<ans<<endl;
	}
	return 0;
}
