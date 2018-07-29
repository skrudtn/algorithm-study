#include <iostream>
#include <cmath>

using namespace std;

int arr[11];

void swap(int a, int b){
	int tmp=arr[a];
	arr[a]=arr[b];
	arr[b]=tmp;
}

void qsort(int s, int e){
	if(s<e){
		int pivot=s;
		for(int i=s; i<=e; ++i){
			if(arr[i]>arr[e]){
				swap(i,pivot);
				pivot++;
			}
		}
		swap(pivot,e);
		qsort(s,pivot-1);
		qsort(pivot+1,e);
	}
}

int main(void){
	int p,num;
	p=0;
	cin>>num;
	while(int(num/pow(10,p))){
		p++;
	}
	for(int i=p-1;i>=0;--i){
		arr[p-i-1]=int(num/pow(10,i))-int(num/(pow(10,i)*10))*10;
	}
	qsort(0,p-1);
	for(int i=0; i<p; ++i){
		cout<<arr[i];
	}
	return 0;
}
