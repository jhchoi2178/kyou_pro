#include <stdio.h>
int n,m;
char a[1000010];
int cnt,ans;
int main(){
	scanf("%d %d",&n,&m);
	scanf("%s",a);
	for(int i=0;i<m;i++){
		if(a[i]=='I'&&a[i+1]=='O'){
			cnt++;
			i++;
		} else {
			cnt = 0;
		}
		if(cnt>=n&&a[i+1]=='I'){
			ans++;
		}
	}
	printf("%d\n",ans);
}