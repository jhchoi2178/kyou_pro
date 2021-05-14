#include <string>
#include <iostream>
#include <stack>

using namespace std;
string a;
stack<char> Q;
int main(){
	while(1){
		while(!Q.empty()){
			Q.pop();
		}
		bool isOkay = true;
		getline(cin,a);
		if(a.length()==1&&a[0]=='.') return 0;
		for(int i=0;i<a.length();i++){
			if(a[i]=='('||a[i]=='['){
				Q.push(a[i]);
			} else if(a[i]==')'||a[i]==']'){
				if(Q.empty()||Q.top()!=(a[i]==')'?'(':'[')){
					isOkay = false;
				} else {
					Q.pop();
				}
			}
		}
		if(Q.empty()&&isOkay) cout<<"yes"<<endl;
		else cout<<"no"<<endl;
	}
}