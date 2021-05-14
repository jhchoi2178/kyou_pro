#include <string>
#include <iostream>

using namespace std;

string a;
bool have_minus = false;
int ret;
int main(){
	cin>>a;
	int t = 0;
	for(int i=0;i<a.length();i++){
		if(a[i]>='0'&&a[i]<='9'){
			t = a[i]-'0';
			while(a[i+1]>='0'&&a[i+1]<='9'){
				i++;
				t = t*10+a[i]-'0';
			}
		} else if(a[i]=='+'){
			if(have_minus){
				ret -= t;
				t = 0;
			} else{
				ret += t;
				t = 0;
			}
		} else if(a[i]=='-'){
			if(have_minus){
				ret -= t;
				t = 0;
			} else{
				ret += t;
				t = 0;
			}
			have_minus = true;
		}
	}
	if(have_minus){
				ret -= t;
				t = 0;
			} else{
				ret += t;
				t = 0;
			}
	printf("%d\n",ret);
}