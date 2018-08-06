#include <iostream>

using namespace std;

int minVal,maxVal,n,k,arr[12],operation[12],value[12],op[4],opTmp[4];

int _max(int a,int b){return a>b?a:b;}
int _min(int a,int b){return a<b?a:b;}

int getValue(){
	int idx=1;
	int ret=value[1];
	for(int j=0;j<4;++j){
		opTmp[j]=op[j];
	}
	for(int j=0;j<4;++j){
		while(opTmp[j]){
			operation[arr[idx]]=j;
			idx++;
			opTmp[j]-=1;
		}
	}
	idx=1;
	for(int j=1;j<=k;++j){
		switch(operation[j]){
			case 0:
				ret+=value[idx+1];
				break;
			case 1:
				ret-=value[idx+1];
				break;
			case 2:
				ret*=value[idx+1];
				break;
			case 3:
				if(ret>=0){
					ret/=value[idx+1];
				} else{
					ret= ~ret+1;
					ret/=value[idx+1];
					ret=~ret+1;
				}
			default:
				break;
		}
		idx++;
	}
	return ret;
}

void swap(int a,int b){
	int tmp=arr[a];
	arr[a]=arr[b];
	arr[b]=tmp;
}

void solve(int depth){
	if(depth==k){
		int v=getValue();
		maxVal=_max(maxVal,v);
		minVal=_min(minVal,v);
		return;
	} 
	for(int i=depth; i<=k;++i){
		swap(i,depth);
		solve(1+depth);
		swap(i,depth);
	}
}

int main(void){
	cin>>n;
	k=n-1;
	maxVal=-1000000000;
	minVal=1000000000;
	for(int i=1;i<=n;++i){
		cin>>value[i];
	}
	for(int i=1;i<=n;++i){
		arr[i]=i;
	}
	for(int i=0;i<4;++i){
		cin>>op[i];
	}
	
	solve(1);
	cout<<maxVal<<endl<<minVal<<endl;
	return 0;
}
