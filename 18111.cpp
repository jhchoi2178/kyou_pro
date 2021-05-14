#include <stdio.h>
int n,m,b;
int a[510][510];
int ans=987654321;
int ansz = -1;
int main(){
	scanf("%d %d %d",&n,&m,&b);
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			scanf("%d",&a[i][j]);
		}
	}
	for(int z=0;z<=256;z++){
		int time = 0;
		int cur_b = b;
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j]>=z){
					time += (a[i][j]-z)*2;
					cur_b += a[i][j]-z;
				} else {
					time += z-a[i][j];
					cur_b += a[i][j]-z;
				}
			}
		}
		if(cur_b >= 0 && time <= ans ){
			ans = time;
			ansz = z;
		}
	}
	printf("%d %d\n",ans,ansz);
}