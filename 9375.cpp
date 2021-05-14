#include <iostream>
#include <map>
using namespace std;
int t;
int n;
string a[30],b[30];
int main(){
	cin>>t;
	while(t--){
		map<string,int> M;
		cin>>n;
		for(int i=0;i<n;i++){
			cin>>a[i]>>b[i];
			if(M.find(b[i]) != M.end()){
				M[b[i]]++;
			} else {
				M[b[i]] = 1;
			}
		}
		int ans = 1;
		for(auto i : M){
			ans *= (i.second+1);
		}
		ans--;
		printf("%d\n",ans);
	}
}
