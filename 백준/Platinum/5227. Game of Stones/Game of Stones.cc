#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <cmath>
#include <set>
#include <map>
#pragma warning(disable:4996)
#define INF 1000000000

using namespace std;

typedef pair<int,int> intint;

int n,m;
short Node[1000]={};
bool vn[1000]={};

int dfs(int p,vector<short>arr[1000]){
	if(vn[p])return Node[p];
	else{
		bool check[1001]={};
		for(int i=0;i<arr[p].size();i++){
			check[dfs(arr[p][i],arr)]=1;
		}
		Node[p]=-1;
		for(int i=0;i<=n;i++){
			if(!check[i]){
				Node[p]=i;
				break;
			}
		}
		vn[p]=1;
		if(Node[p]==-1)exit(-1);
		return Node[p];
	}
}
void setting(){
	vector<short>arr[1000];
	int ans=0;
	for(int i=0;i<n;i++){
		vn[i]=false;
	}
	int a,b,w;
	while(m--){
		cin>>a>>b;
		arr[a].push_back(b);
	}
	for(int i=0;i<n;i++){
		cin>>w;
		while(w){
			ans^=dfs(i,arr);
			w--;
		}
	}
	if(ans==0)cout<<"Second\n";
	else cout<<"First\n";
}
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	while(1){
		cin>>n>>m;
		if(n==0&&m==0)break;
		else setting();
	}
}