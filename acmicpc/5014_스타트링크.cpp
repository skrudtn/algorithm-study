#include <iostream>
#include <queue>

using namespace std;

int f,s,g,u,d,dir[2],visit[1000001];

int main(void){
	freopen("input.txt","r",stdin);
	cin>>f>>s>>g>>u>>d;
	dir[0]=u;
	dir[1]=-d;
	
	queue<int> que;
	que.push(s);
	visit[s]=1;
	
	while(!que.empty()){
		int cur=que.front();
		que.pop();
		
		if(cur==g) break;
		
		for(int d=0;d<2;++d){
			int next=dir[d]+cur;
			if(next<1 || next>f) continue;
			if(visit[next]) continue;
			visit[next]=visit[cur]+1;
			que.push(next);
		}
		
	}
	if(!visit[g]) cout<<"use the stairs";
	else cout<<visit[g]-1;
	return 0;
}
