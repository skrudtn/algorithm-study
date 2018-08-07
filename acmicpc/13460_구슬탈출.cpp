#include <iostream>
#include <queue>

using namespace std;

int n,m,map[11][11]; 
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

struct p{
	int rx,ry,bx,by,cnt;
}typedef Pos;

int main(void){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	char tmp;
	int v;
	queue<Pos> que;
	Pos pos;
	pos.cnt=1;

	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m;++j){
			scanf(" %1c",&tmp);
			if(tmp=='#') v=9;
			else if(tmp=='.') v=0;
			else if(tmp=='R') {v=0;pos.rx=j;pos.ry=i;}
			else if(tmp=='B') {v=0;pos.bx=j;pos.by=i;}
			else if(tmp=='O') v=3;
			map[i][j]=v;
		}
	}
	que.push(pos);
	while(!que.empty()){
		Pos cur=que.front();
		que.pop();
		if(cur.cnt>10) break;
		// 동서남북 기울이기
		for(int d=0;d<4;++d){
			int rx=cur.rx;
			int ry=cur.ry;
			int bx=cur.bx;
			int by=cur.by;
			int cnt=cur.cnt;
			int bFlg,rFlg;

			bFlg=rFlg=0;
			while(1){
				int nx=bx+dx[d];
				int ny=by+dy[d];
				if(map[ny][nx]==9) break;
				if(map[ny][nx]==3) bFlg=1;
				bx=nx;by=ny;
			}
			if(bFlg) continue;
			while(1){
				int nx=rx+dx[d];
				int ny=ry+dy[d];
				if(map[ny][nx]==9) break;
				if(map[ny][nx]==3) rFlg=1;
				rx=nx;ry=ny;
			}
			if(rFlg){
				cout<<cur.cnt;
				return 0;
			}

			if(rx==bx && ry==by){
				if(dx[d]==1){ //동으로 움직인거면
					if(cur.rx>cur.bx){
						bx--;
					} else {
						rx--;
					}
				} else if(dx[d]==-1){ //서 
					if(cur.rx>cur.bx){
						rx++;
					} else {
						bx++;
					}
				} else if(dy[d]==1){ //남 
					if(cur.ry>cur.by){
						by--;
					} else {
						ry--;
					}
				} else if(dy[d]==-1){ //북 
					if(cur.ry>cur.by){
						ry++;
					} else {
						by++;
					}
				}
			}
			if(!(cur.rx==rx && cur.ry==ry && cur.bx==bx && cur.by==by)){ // 안움직였으면 안넣음 
	 			Pos next={rx,ry,bx,by,cnt+1};
				que.push(next);
			}
		}
	}
	cout<<-1;
	return 0;
}
