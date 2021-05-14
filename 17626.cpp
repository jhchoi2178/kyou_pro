#include <stdio.h>
int n;
int DT[50010];
int min(int a,int b){
	return a<b?a:b;
}
int main(){
	for(int i=1;i<50001;i++){
		DT[i] = 987654321;
	}
	DT[0] = 0;
	for(int i=0;i<4;i++){
		for(int j=0;j<50001;j++){
			for(int k=1;j+k*k<50001;k++){
				DT[j+k*k] = min(DT[j+k*k],DT[j]+1);
			}
		}
	}
	scanf("%d",&n);
	printf("%d\n",DT[n]);
}