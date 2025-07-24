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

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		for(int j=0;j<n;j++){
			int a=j-i+1;
			if(a<0)a+=n;
			cout<<n*a+i;
			if(j!=n-1)cout<<" ";
		}
		if(i!=n)cout<<"\n";
	}
}