#include <stdio.h>
int n,m;
int a[100010];
int DT[100010];

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		DT[i] = DT[i-1]+a[i];
	}
	for(int i=0;i<m;i++){
		int x,y;
		scanf("%d %d",&x,&y);
		printf("%d\n",DT[y]-DT[x-1]);
	}
}