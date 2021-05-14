#include <string>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
int n,m;
set<string> M;
vector<string> ans;
string x;
int cnt;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>x;
		M.insert(x);
	}
	for(int i=0;i<m;i++){
		cin>>x;
		if(M.find(x)!=M.end()){
			cnt++;
			ans.push_back(x);
		}
	}
	cout<<cnt<<endl;
	sort(ans.begin(),ans.end());
	for(int i=0;i<ans.size();i++){
		cout<<ans[i]<<endl;
	}
}