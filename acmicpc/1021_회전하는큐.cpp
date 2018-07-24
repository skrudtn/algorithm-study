#include <iostream>
#include <deque>

using namespace std;

int getIdx(deque<int> deq, int target){
	int ret=-1;
	for(deque<int>::size_type i=0; i<deq.size(); ++i){
		if(deq[i]==target){
			ret=i;
		}
	}
	return ret;
}

int main(void){
	int n,m,tmp,ans,idx;
	freopen("input.txt","r",stdin);
	cin>>n>>m;
	deque<int> deq(n);
	for(deque<int>::size_type i=0; i<n; ++i){
		deq[i]=i+1;
	}
	ans=0;
	for(int i=0; i<m; ++i){
		cin>>tmp;
		idx=getIdx(deq,tmp);
		if(!idx){
			deq.pop_front();
		}
		else if(idx<=deq.size()/2){
			for(int i=0; i<idx;i++){
				deq.push_back(deq.front());
				deq.pop_front();
				ans++;
			}
			deq.pop_front();
		}
		else if(idx>deq.size()/2){
			for(int i=0; i<deq.size()-idx; ++i){
				deq.push_front(deq.back());
				deq.pop_back();
				ans++;
			}
			deq.pop_front();
		}
	}
	
	cout<<ans<<endl;
	
	return 0;
}
