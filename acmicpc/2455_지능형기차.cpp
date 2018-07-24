#include <stdio.h>

int main(void){
	int ans,a,man;
	ans=man=0;
	for(int i=0; i<3; ++i){
		scanf("%d",&a);
		man-=a;
		scanf("%d",&a);
		man+=a;
		ans=ans>man?ans:man;
	}
	printf("%d\n",ans);
		
	return 0;
}
