#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int m,a,a_hist[101], b_hist[101],map[10][10];
int dx[5] = {0,0,1,0,-1};
int dy[5] = {0,-1,0,1,0};

struct Node{
	int y,x,range,power;
}typedef Node;

struct User{
	int y,x;
}typedef User;

vector<Node> nodes(8);
User users[2];

int isOnMap(int y,int x){
	return x>=0 && x<10 && y>=0 && y<10;
}

bool cmp(Node n1, Node n2){
	return n1.power > n2.power ? 1: 0;
}

int abs(int i){return i>=0?i:-i;}
int max(int a,int b){return a>b?a:b;}

int get_dist(int y1,int x1,int y2,int x2){
	return abs(y1-y2) + abs(x1-x2);
}

int solution(){
	int ret=0;
	vector<int> a_list;
	vector<int> b_list;
	for(int time = 0; time<=m; ++time){
		int val=0;
		int d=a_hist[time];
		int x=users[0].x;
		int y=users[0].y;
		int nx=dx[d]+x;
		int ny=dy[d]+y;
		users[0].x=nx;
		users[0].y=ny;
		
		d=b_hist[time];
		x=users[1].x;
		y=users[1].y;
		nx=dx[d]+x;
		ny=dy[d]+y;
		users[1].x=nx;
		users[1].y=ny;
		
		for(int i=0;i<a;++i){
			int ac_x=nodes[i].x;
			int ac_y=nodes[i].y;
		
			if(get_dist(ac_y,ac_x,users[0].y,users[0].x) <= nodes[i].range){
				a_list.push_back(i);
			}
		}
		for(int i=0;i<a;++i){
			int ac_x=nodes[i].x;
			int ac_y=nodes[i].y;
		
			if(get_dist(ac_y,ac_x,users[1].y,users[1].x) <= nodes[i].range){
				b_list.push_back(i);
			}
		}
		
		if(a_list.size() && !b_list.size()){
			val = nodes[a_list[0]].power;
		} else if(!a_list.size() && b_list.size()){
			val = nodes[b_list[0]].power;
		} else if(a_list.size() && b_list.size()){
			int tmp=0;
			for(int i=0;i<a_list.size();++i){
				for(int j=0;j<b_list.size();++j){
					tmp = 0;
					if(a_list[i]==b_list[j]){
						tmp = nodes[a_list[i]].power;
					} else {
						tmp +=nodes[a_list[i]].power;
						tmp +=nodes[b_list[j]].power;
					}
					val = max(val,tmp);
				}
			}
		}
		
		a_list.clear();
		b_list.clear();
//		printf("time %d, %dÈ¹µæ\n",time,val); 
		ret += val;
	}
	
	return ret;
}

int main(void){
	int tc,ans;
	scanf("%d",&tc);
	for(int t=1;t<=tc;++t){
		ans=0;
		users[0].x=0;
		users[0].y=0;
		users[1].x=9;
		users[1].y=9;
		a_hist[0] = 0;
		b_hist[0] = 0;
		scanf("%d %d",&m,&a);
		for(int i=1;i<=m;++i){
			scanf("%d",&a_hist[i]);
		}
		for(int i=1;i<=m;++i){
			scanf("%d",&b_hist[i]);
		}
		for(int i=0;i<a;++i){
			int y,x,c,p;
			scanf("%d %d %d %d",&x,&y,&c,&p);
			nodes[i].y=y-1;
			nodes[i].x=x-1;
			nodes[i].range=c;
			nodes[i].power=p;
		}
		sort(nodes.begin(),nodes.begin()+a,cmp);

		ans = solution();
		printf("#%d %d\n",t,ans);
	}
	
	return 0;
}
