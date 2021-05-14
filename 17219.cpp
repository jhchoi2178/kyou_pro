#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;
int n,m;
string a,b;
unordered_map<string,string> M;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a>>b;
		M[a] = b;
	}
	for(int i=0;i<m;i++){
		cin>>a;
		cout<<M[a]<<'\n';
	}
}