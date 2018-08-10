#include <iostream>
#include <string>

using namespace std;

int kx,ky,sx,sy;
int dx[8]={1,-1,0,0,1,-1,1,-1};
int dy[8]={0,0,1,-1,-1,-1,1,1};

int isOnMap(int y,int x){
	return y>0 && y<=8 && x>0 && x<=8;
}

void move(int d){
	int knx=dx[d]+kx;
	int kny=dy[d]+ky;
	int snx=dx[d]+sx;
	int sny=dy[d]+sy;
	
	if(!isOnMap(kny,knx)) return;
	if(knx==sx && kny==sy){
		if(!isOnMap(sny,snx)) return;
		sx=snx;
		sy=sny;
	}
	kx=knx;
	ky=kny;
}

int main(void){
	char a;
	int b,n;
	string k,s,str;
	cin>>k>>s>>n;
	kx=k.at(0)-64;
	ky=9-int(k.at(1)-'0');
	sx=s.at(0)-64;
	sy=9-int(s.at(1)-'0');
	for(int i=1;i<=n;++i){
		cin>>str;
		if(!str.compare("R")) move(0);
		else if(!str.compare("L")) move(1);
		else if(!str.compare("B")) move(2);
		else if(!str.compare("T")) move(3);
		else if(!str.compare("RT")) move(4);
		else if(!str.compare("LT")) move(5);
		else if(!str.compare("RB")) move(6);
		else if(!str.compare("LB")) move(7);
	}
	
	cout<<char(kx+64)<<9-ky<<endl;
	cout<<char(sx+64)<<9-sy<<endl;
	
	return 0;
}
