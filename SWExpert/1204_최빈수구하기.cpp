#include <stdio.h>

int arr[101] = {0,};
�� 
int main(void){
	int T,t_c,tmp,ans,freq;
	scanf("%d",&T);
	for(int t=1; t<=T; ++t){
		scanf("%d",&t_c);
		for(int i=0; i<101; ++i){
			arr[i]=0;
		}
		ans=0;
		freq=0;
		
		for(int i=0; i<1000; ++i){
			scanf("%d",&tmp);
			arr[tmp] += 1;
		}

		for(int i=0; i<101; ++i){
			if(freq<=arr[i]){ /* ���� ���϶� �������� ã������ '<' */
				freq=arr[i];
				ans = i;
			}
		}
		printf("#%d %d\n",t_c,ans);
	}	
	return 0;
}
