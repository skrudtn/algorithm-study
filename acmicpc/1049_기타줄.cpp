#include <iostream>

using namespace std;

int n,m,arr[51][2];

//void disp(){
//	for(int i=0;i<m;++i){
//		cout<<arr[i][0]<<" "<<arr[i][1]<<endl;
//	}
//}

int _min(int a,int b){return a<b?a:b;}

int main(void){
	int min_pack,min_indiv,sum;
	min_pack=min_indiv=0x1c1c1c1c;
	sum=0;
	
	freopen("input.txt","r",stdin);
	cin>>n>>m;
	for(int i=0;i<m;++i){
		cin>>arr[i][0]>>arr[i][1];
		min_pack=_min(min_pack,arr[i][0]);
		min_indiv=_min(min_indiv,arr[i][1]);
	}
	
	if(min_pack<min_indiv*6){
		sum+=n/6*min_pack;

		if(n%6*min_indiv>=min_pack){
			sum+=min_pack;
		} else{
			sum+=n%6*min_indiv;
		}
	} else {
		sum+=n*min_indiv;
	}
	
	cout<<sum<<endl;
	return 0;
}
