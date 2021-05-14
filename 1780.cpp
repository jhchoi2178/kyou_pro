#include <stdio.h>
int cnt[3];
int n;
int a[2200][2200];
void f(int x,int y,int w){
	if(w==1){
		cnt[a[x][y]+1]++;
		return;
	}
	int t  = a[x][y];
	for(int i=0;i<w;i++){
		for(int j=0;j<w;j++){
			if(a[x][y]!=a[x+i][y+j]){
				for(int k=0;k<3;k++){
					for(int l=0;l<3;l++){
						f(x+k*w/3,y+l*w/3,w/3);
					}
				}
				return;
			}
		}
	}
	cnt[a[x][y]+1]++;
	return;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
		}
	}
	f(0,0,n);
	for(int i=0;i<3;i++){
		printf("%d\n",cnt[i]);
	}
}