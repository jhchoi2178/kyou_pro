#include <stdio.h>
int ret;
int n,m;
int a[110];
int main(){
	scanf("%d %d",&n,&m);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(a[i]+a[j]+a[k]>ret && a[i]+a[j]+a[k]<=m) ret = a[i]+a[j]+a[k];
			}
		}
	}
	printf("%d\n",ret);
}