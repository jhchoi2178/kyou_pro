#include <stdio.h>
#include <algorithm>
int n,m,x;
int a[500010];
int upper_bound(int x){
	int st = 0,ed = n;
	while(ed>st){
		int mid = (st+ed)/2;
		if(a[mid]>x){
			ed = mid;
		} else {
			st = mid+1;
		}
	}
	return st;
}
int lower_bound(int x){
	int st = 0,ed = n;
	while(ed>st){
		int mid = (st+ed)/2;
		if(a[mid]>=x){
			ed = mid;
		} else {
			st = mid+1;
		}
	}
	return st;
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	std::sort(a,a+n);
	scanf("%d",&m);
	for(int i=0;i<m;i++){
		scanf("%d",&x);
		printf("%d ",upper_bound(x)-lower_bound(x));
	}
}