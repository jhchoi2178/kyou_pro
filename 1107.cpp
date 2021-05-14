#include <stdio.h>
int n;
int a[11];
int b[1000010];
int ans = 987654321;
int f(int x){
	if(x==0) return 1;
	return f(x/10)*(a[x%10]);
}
int digit(int x){
	if(x==0) return 0;
	return digit(x/10)+1;
}
int min(int a,int b){
	return a<b?a:b;
}
int abs(int x){
	return x>0?x:-x;
}
int main(){
	scanf("%d",&n);
	int m;
	scanf("%d",&m);
	for(int i=0;i<10;i++){
		a[i] = 1;
	}
	for(int i=0;i<m;i++){
		int t;
		scanf("%d",&t);
		a[t] = 0;
	}
	b[0] = a[0];
	for(int i=1;i<=999999;i++){
		b[i] = f(i);
	}
	ans = abs(n-100);
	if(b[0]) ans = min(ans,n+1);
	for(int i=1;i<=999999;i++){
		if(b[i]) ans = min(ans,abs(i-n)+digit(i));
	}
	printf("%d\n",ans);
}