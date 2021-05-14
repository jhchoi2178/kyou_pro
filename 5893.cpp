#include <stdio.h>
#include <string.h>
char a[1010];
char b[1010];
int c[1010];
int carry;
int main(){
	scanf("%s",a);
	int len = strlen(a);
	for(int i=0;i<len;i++){
		b[i+4] = a[i];
	}
	for(int i=0;i<4;i++){
		b[i] = '0';
		a[i+len] = '0';
	}
	for(int i=len+3;i>=0;i--){
		c[i] = (int)(a[i]-'0') + (int)(b[i]-'0') + carry;
		carry = c[i]/2;
		c[i] = c[i] - carry*2;
	}
	if(carry) printf("%d",carry);
	for(int i=0;i<len+4;i++){
		printf("%d",c[i]);
	}
	puts("");
}