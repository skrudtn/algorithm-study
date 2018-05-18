#include <iostream>
#include <math.h>

using namespace std;

int n,m;
int result;
int dx[] = {0, 0, 2, -2};
int dy[] = {2, -2, 0, 0};

bool isOnMap(int y, int x){
	return x>=0 && x<n && y>=0 && y<m;
}

int getBeanNum(int **map){
	int ret = 0;
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			if(map[i][j]==1){
				ret++;
			}
		}
	}
	return ret;
}

void solution(int **map, int x, int y){
	bool flag = false;
	
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			for(int d=0; d<4; d++){
				if(isOnMap(i+dy[d], j+dx[d]) && map[i+dy[d]][j+dx[d]] == 1)
					flag = true;
			}
			if(!flag){
				map[i][j] = 1;
			}
			flag = false;
		}
	}
	
}

void initMap(int **map){
	for(int i=0; i<m; i++){
		for(int j=0; j<n; j++){
			map[i][j] = 0;
		}
	}
}

int main(int argc, char** argv) {
	int test_case = 0;
	int **map;
	
	cin >> test_case;
	
	for(int t = 1; t<=test_case; ++t){
		
		result = 0;	
		cin>>n;
		cin>>m; 
		
		map = new int*[m];
		for(int i=0; i<m; i++){
			map[i] = new int[n];
		}
		
		
		initMap(map);
		solution(map,0,0);
		
	
		result = max(result, getBeanNum(map));	
		cout<<"#"<<t<<" "<<result<<endl;
		
		for(int i=0; i<m; i++){
			delete[] map[i];
		}
		delete[] map;
	}
	
	return 0;
}
