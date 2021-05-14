#include <stdio.h>

char a[1000010];

int main(){
	scanf("%s",a);
	int t = 0;
	for(int i=0;a[i]!=0;i++){
		t = t*10+(a[i]-'0');
		t%=20000303;
	}
	printf("%d\n",t);
}