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
#define nINF -1000000000
#define INF 1000000000

using namespace std;

vector<int>arr;
vector<bool>brr;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n,m,k,w;
	cin>>n>>m>>k;
	for(int i=0;i<m;i++){
		cin>>w;
		arr.push_back(w);
		brr.push_back(false);
	}
	sort(arr.begin(),arr.end());
	while(k--){
		cin>>w;
		int up=upper_bound(arr.begin(),arr.end(),w)-arr.begin();
		while(brr[up]){
			up++;
		}
		cout<<arr[up]<<"\n";
		brr[up]=true;
	}
}