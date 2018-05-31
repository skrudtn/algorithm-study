#include <stdio.h>

int _abs(int a){
	return a>0?a:-a;
}

int main(void){
	int T,tc,ans=0;
//	freopen("sample_input.txt","r", stdin);
	scanf("%d",&T);
	for(tc=1; tc<=T; ++tc){
		int a,b,t1,t2,a_row,a_col,b_row,b_col,i,tmp=0;
		
		scanf("%d %d",&t1,&t2); 
		if(t1>t2){
			a=t1;
			b=t2;
		} else {
			a=t2;
			b=t1;
		}
		
		for(i=1; i<=10000; ++i){
			tmp+=i;
			if(tmp>=a){
				a_row=i;
				a_col=a-(tmp-i);
				break;
			}
		}
		tmp=0;
		for(i=1; i<=10000; ++i){
			tmp+=i;
			if(tmp>=b){
				b_row=i;
				b_col=b-(tmp-i);
				break;
			}
		}

		if(b_col+(a_row-b_row)<a_col){ // 커버 안되면 
			ans = a_col-b_col;
		} else if(b_col>a_col){
			ans = b_col-a_col+a_row-b_row;
		} else{
			ans = a_row-b_row;
		}
		printf("#%d %d\n",tc,ans);
	}
	return 0;
}
