#include <stdio.h>
int a,b,c;
int main(){
	scanf("%d %d %d",&a,&b,&c);
	if(b>=c) printf("-1\n");
	else printf("%d\n",a/(c-b)+1);
}