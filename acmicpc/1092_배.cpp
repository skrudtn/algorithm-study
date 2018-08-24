#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int n,m,crane[51],box[10001];

bool cmp(int a,int b){return a>b?1:0;}

int main(void){
	cin>>n;
	vector<queue<int> > v(n);
	for(int i=0;i<n;++i){
		cin>>crane[i];
	}
	
	cin>>m;
	for(int i=0;i<m;++i){
		cin>>box[i];
	}
	
	sort(crane,crane+n,cmp);
	sort(box,box+m,cmp);

	if(crane[0]<box[0]){
		cout<<-1<<endl;
		return 0;
	}
	
	for(int i=0;i<m;++i){
		int flg=0;
		for(int j=0;j<n-1;++j){
			if(box[i]<=crane[j] && box[i]>crane[j+1]){
				v[j].push(box[i]);
				flg=1;
				break;
			}
		}
		if(!flg){
			v[n-1].push(box[i]);
		}
	}
	int size,ans;
	size=ans=0;
	while(1){
		if(size==m) break;
		ans++;
		for(int i=0;i<n;++i){
			if(v[i].empty()){
				for(int j=i+1;j<n;++j){
					if(!v[j].empty()){
						v[j].pop();
						size++;
						break;
					}
				}
			} else {
				v[i].pop();
				size++;
			}
		}
	}
	
	cout<<ans<<endl;
	return 0;
}
