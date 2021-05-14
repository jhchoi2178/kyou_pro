#include <stdio.h>
int n;
int a[200][200];
int cnt[2];
void f(int x,int y,int w){
	if(w==1){
		cnt[a[x][y]]++;
		return;
	}
	for(int i=0;i<w;i++){
		for(int j=0;j<w;j++){
			if(a[x][y]!=a[x+i][y+j]){
				for(int k=0;k<2;k++){
					for(int l=0;l<2;l++){
						f(x+k*w/2,y+l*w/2,w/2);
					}
				}
				return;
			}
		}
	}
	cnt[a[x][y]]++;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	f(0,0,n);
	for(int i=0;i<2;i++){
		printf("%d\n",cnt[i]);
	}
}