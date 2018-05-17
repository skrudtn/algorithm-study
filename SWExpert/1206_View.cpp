#include <iostream>
//#include <fstream>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

#define h 255

int solution(int *map, int w);
int isOnMap(int x);

int main(int argc, char** argv) {
	int test_case;
	test_case=10;
	
	for(int t=0; t<test_case; t++){
		int w=0;
		int *map;
		cin >> w;
		map = new int[w];
				
		for(int i=0; i<w; i++){
			cin >> map[i];
		}
		
		cout <<"#"<<t+1<<" "<< solution(map, w)<<endl;
	}
	
	return 0;
}

bool isOnMap(int x, int w){
	return x>=0 && x<w;
}


int solution(int *map, int w){
	int result = 0;
	
	for(int i=0; i<w; i++){
		for(int j=map[i]; j>=0; j--){
			if(isOnMap(i-1, w) && map[i-1]<j && isOnMap(i-2, w) && map[i-2]<j && 
				isOnMap(i+1, w) && map[i+1]<j && isOnMap(i+2, w) && map[i+2]<j )
				result++;
			else
				break;
		}
	}
	
	return result;
}
