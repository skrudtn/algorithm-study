#include <iostream>

using namespace std;

int n,l,map[101][101],ladder[101][101];

int isOnMap(int y, int x){
	return x>=1 && x<=n && y>=1 && y<=n;
}
void initLadder(void){
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			ladder[i][j]=0;
		}
	}
}

int putLadder(int y, int x, int d){
	//해당 좌표에서 해당 방향으로 사다리를 둘때
	//1. 사다리 크기만큼 공간이 있고
	//2. 사다리를 두지 않았고
	//3. 사다리를 두는 공간의 높이가 모두 같아야함. 
	int h;
	h=map[y][x];
	switch(d){
		case 1: // 동
			for(int nx=x;nx<x+l;++nx){
				if(!isOnMap(y,nx)) return 0;
				if(ladder[y][nx]) return 0;
				if(h!=map[y][nx]) return 0;
			}
			for(int nx=x;nx<x+l;++nx){
				ladder[y][nx]=1;
			}
			return 1; 
			break;
		case 2: // 남
			for(int ny=y;ny<y+l;++ny){
				if(!isOnMap(ny,x)) return 0;
				if(ladder[ny][x]) return 0;
				if(h!=map[ny][x]) return 0;
			}
			for(int ny=y;ny<y+l;++ny){
				ladder[ny][x]=1;
			}
			return 1;
			break;
		case 3: // 서
			for(int nx=x;nx>x-l;--nx){
				if(!isOnMap(y,nx)) return 0;
				if(ladder[y][nx]) return 0;
				if(h!=map[y][nx]) return 0;
			}
			for(int nx=x;nx>x-l;--nx){
				ladder[y][nx]=1;
			}
			return 1;
			break;
		case 4: // 북
			for(int ny=y;ny>y-l;--ny){
				if(!isOnMap(ny,x)) return 0;
				if(ladder[ny][x]) return 0;
				if(h!=map[ny][x]) return 0;
			}
			for(int ny=y;ny>y-l;--ny){
				ladder[ny][x]=1;
			}
			return 1;
			break;
		default:
			break;
	}
	return 0;
}

int rowChk(int r){
	int ret=1;
	for(int c=1;c<n;++c){
		if(map[r][c] == map[r][c+1]){
			continue;
		} else if(map[r][c]+1 == map[r][c+1]){
			if(putLadder(r,c,3)){
				//
			} else {
				ret=0;
				break;
			}
		} else if(map[r][c]-1 == map[r][c+1]){
			if(putLadder(r,c+1,1)){
				//
				c+=l-1;
			} else {
				ret=0;
				break;
			}
		} else{
			ret=0;
			break;
		}
	}
	return ret;
}

int colChk(int c){
	int ret=1;
	for(int r=1;r<n;++r){
		if(map[r][c]==map[r+1][c]){
			continue;
		} else if(map[r][c]+1 == map[r+1][c]){
			if(putLadder(r,c,4)){
				// 다음칸 검사 
			} else {
				ret=0;
				break;
			}
		} else if(map[r][c]-1 == map[r+1][c]){
			if(putLadder(r+1,c,2)){
				r+=l-1;
			} else {
				ret=0;
				break;
			}
		} else{
			ret=0;
			break;
		}
	}
	return ret;
}

int main(void){
	int ans=0;
	cin>>n>>l;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>map[i][j];
		}
	}
	for(int i=1;i<=n;++i){
		ans+=rowChk(i);
		initLadder(); 
		ans+=colChk(i);
		initLadder(); 
	}
	
	cout<<ans;
	return 0;
}
