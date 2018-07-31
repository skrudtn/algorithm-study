#include <stdio.h>
#include <vector>

using namespace std; 

int arr[101],chk[101];

int main(void){
	int n,k,cnt,ans;
	vector<int> v;
	cnt=ans=0;
	scanf("%d %d",&n,&k);
	for(int i=1; i<=k; ++i){
		scanf("%d",&arr[i]);
	}
	for(int i=1;i<=k;++i){
		if(!chk[arr[i]]){
			if(v.size()<n) {// 그냥 꽂기.
				chk[arr[i]]=1;
				v.push_back(arr[i]);
			} else {
				int target,idx=0;
				for(int j=0; j<v.size();++j){
					int flg=0;
					for(int l=i;l<=k;++l){
						if(v[j]==arr[l]){
							flg=1;
							if(idx<l){ 
								idx=l;
								target=arr[l];
							}
							break;
						}
					}
					if(!flg){// 안 나오면  
						target=v[j];
						break;
					}
				}
				
				chk[arr[i]]=1;
				chk[target]=0;
				for(int j=0; j<v.size();++j){
					if(v[j]==target) v.erase(v.begin()+j);
				}
				v.push_back(arr[i]);
				ans++;
			}
		}
	}
	
	printf("%d",ans);
	return 0;
}
