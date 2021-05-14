#include <stdio.h>
#include <algorithm>
int a[3];
int main(){
	while(1){
		scanf("%d %d %d",&a[0],&a[1],&a[2]);
		std::sort(a,a+3);
		if(a[0]==0&&a[1]==0&&a[2]==0) return 0;
		printf("%s\n",(a[0]*a[0]+a[1]*a[1])==a[2]*a[2]?"right":"wrong");
	}
}