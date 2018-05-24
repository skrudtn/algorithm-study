#include<iostream>
#include<algorithm>

#include <cstdio>

using namespace std;


int arr[9];

void print(int data[7]){
	for(int i=0; i<7; i++){
		cout<<data[i]<<endl;
	}
}

void search(int idx, int target,int choice, int data[7]){
	if(choice==0){	
		int ret=0;
		for(int i=0; i<7; i++){
			ret += data[i];
		}
		if(ret ==100){
			print(data);
		}
	} else if(target==9){
		return;	
	} else{
		data[idx] = arr[target];
		search(idx+1, target+1, choice-1,data);
		search(idx, target+1,choice, data);
	}
	
}

int main(){
	
	//freopen("input.txt", "r", stdin);
	for(int i=0; i<9; i++){
		cin>>arr[i];
	}
	
	sort(arr, arr+9);
	int data[7]={0,};
	
	search(0,0,7,data);
}
