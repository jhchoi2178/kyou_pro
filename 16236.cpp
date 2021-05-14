#include <stdio.h>
#include <utility>
#include <vector>
#include <queue>
using namespace std;
int n;
int a[30][30];
int visit[30][30];
int dx[4] = {-1,0,1,0};
int dy[4] = {0,-1,0,1};
int cur_size = 2;
int cur_food;
int ans;
queue<pair<int,int> > Q;
int abs(int x){
	return x>0?x:-x;
}
int dis(int x,int y,int z,int w){
	return abs(x-z)+abs(y-w);
}
pair<int,int> st;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			scanf("%d",&a[i][j]);
			if(a[i][j] == 9){
				st.first = i;
				st.second = j;
				a[i][j] = 0;
			}
		}
	}
	bool isUpdated = true;
	while(isUpdated){
		isUpdated = false;
		int min_dis = 987654321;
		int min_x,min_y;
		for(int i=0;i<n;i++){
			for(int j=0;j<n;j++){
				visit[i][j] = -1;
			}
		}
		Q.push(st);
		visit[st.first][st.second] = 0;
		while(!Q.empty()){
			pair<int,int> cur = Q.front();
			Q.pop();
			if(visit[cur.first][cur.second] < min_dis && a[cur.first][cur.second] < cur_size && a[cur.first][cur.second]>0){
				min_dis = visit[cur.first][cur.second];
				min_x = cur.first;
				min_y = cur.second;
				isUpdated = true;
			} else if(visit[cur.first][cur.second] == min_dis && a[cur.first][cur.second] < cur_size && a[cur.first][cur.second]>0){
				if(cur.first < min_x || (cur.first==min_x && cur.second < min_y )){
					min_x = cur.first;
					min_y = cur.second;
					isUpdated = true;
				}
			}
			for(int i=0;i<4;i++){
				pair<int,int> nt(cur.first+dx[i],cur.second+dy[i]);
				if(nt.first>=0 && nt.first < n && nt.second >=0 && nt.second < n && visit[nt.first][nt.second]==-1 && a[nt.first][nt.second] <= cur_size){
					visit[nt.first][nt.second] = visit[cur.first][cur.second] + 1;
					Q.push(nt);
				}
			}
		}
		if(isUpdated){
			ans += visit[min_x][min_y];
			st.first = min_x;
			st.second = min_y;
			a[min_x][min_y] = 0;
			cur_food++;
		}
		if(cur_food >= cur_size){
			cur_food -= cur_size;
			cur_size++;
		}
	}
	printf("%d\n",ans);
}