#include <iostream>
#include <queue>

using namespace std;

int n,visit[51],map[51][51];

int _max(int a,int b){return a>b?a:b;}

void init(){
	for(int j=1;j<=n;++j){
		visit[j]=0;
	}
}

int solve(int v){
	queue<pair<int,int> > que;
	que.push({v,0});
	
	while(!que.empty()){
		int cur=que.front().first;
		int dep=que.front().second;
		que.pop();
		if(dep==2) break;
		
		for(int i=1;i<=n;++i){
			if(visit[i]) continue;
			if(map[cur][i]){
				visit[i]=1;
				que.push({i,dep+1});
			}
		}
	}
	int ret=0;
	for(int j=1;j<=n;++j){
		if(visit[j]){
			ret++;
		}
	}
	return ret-1;
}

int main(void){
	int ans=0;
	char c;
	scanf("%d",&n);
	
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			scanf(" %1c",&c);
			if(c=='Y'){
				map[i][j]=1;
			} else{
				map[i][j]=0;
			}
		}
	}
	for(int i=1;i<=n;++i){
		init();
		visit[i]=1;
		ans=_max(ans,solve(i));
	}
	cout<<ans<<endl;
	return 0;
}
