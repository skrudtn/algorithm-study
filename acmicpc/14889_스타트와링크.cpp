#include <iostream>

using namespace std;

int ans,aValue,bValue,n,value[3],index[21],map[21][21];

int _min(int a,int b){return a<b?a:b;}
int _abs(int a){return a>0?a:-a;}

void getValue(int idx,int cnt,int a,int team[11]){
	if(cnt==3){
			if(a){
				aValue+=map[team[value[1]]][team[value[2]]];
				aValue+=map[team[value[2]]][team[value[1]]];
			}else {
				bValue+=map[team[value[1]]][team[value[2]]];
				bValue+=map[team[value[2]]][team[value[1]]];
			}
		return;
	} else if(idx==1+n/2){
		return;
	}
	value[cnt]=idx;
	getValue(idx+1,cnt+1,a,team);
	value[cnt]=0;
	getValue(idx+1,cnt,a,team);
}

void solve(int idx, int cnt){
	if(cnt==1+n/2){
		int aCnt,bCnt;
		int aTeam[11],bTeam[11];
		aCnt=bCnt=1;
		for(int i=1;i<=n;++i){
			if(index[i]){
				aTeam[aCnt]=i;
				aCnt+=1;
			} else {
				bTeam[bCnt]=i;
				bCnt+=1;
			}
		}
		aValue=bValue=0;
		
		getValue(1,1,1,aTeam);
		getValue(1,1,0,bTeam);
		ans=_min(ans,_abs(aValue-bValue));
		return;
	} else if(idx==1+n){
		return;
	}
	
	index[idx]=1;
	solve(idx+1,cnt+1);
	index[idx]=0;
	solve(idx+1,cnt);
}

int main(void){
	cin>>n;
	ans=0x1c1c1c1c;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>map[i][j];
		}
	}
	solve(1,1);
	cout<<ans;
	return 0;
}
