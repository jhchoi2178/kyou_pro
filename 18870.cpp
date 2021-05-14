#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int n;
int a[1000010];
vector<int> V;
int get_idx(int x){
	return lower_bound(V.begin(),V.end(),x) - V.begin();
}
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%d",&a[i]);
		V.push_back(a[i]);
	}
	sort(V.begin(),V.end());
	V.erase(unique(V.begin(),V.end()),V.end());
	for(int i=0;i<n;i++){
		printf("%d ",get_idx(a[i]));
	}
}