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
#include <bitset>
#include <utility>
#include <assert.h>
#include <unordered_set>
#include <unordered_map>
#include <complex>
#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;
/*
rope c++
#include <ext/rope>
using namespace __gnu_cxx;
*/

/*
pbds c++ set전용
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update>

multiset을 쓰고 싶으면 위의 코드에서 마지막 줄만 아래 코드로 변경.(대신 erase가 정상작동 되지 않는다.)
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

이외에 범위를 늘리고 싶으면 타입변경하면 된다.
ex. int->ll, less_equal<ll>
*/

constexpr double PI = 3.1415926535;
constexpr long long INF = 2147483647;
constexpr long long lINF = 9000000000000000000;
constexpr long long nlINF = lINF / 10000;
constexpr int nINF = 1007483647;
constexpr long long MOD1 = 1000000007;
constexpr long long MOD2 = 1000000009;
constexpr long long MOD3 = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<short, short>sh_sh;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
typedef pair<double, double> dd;
typedef pair<intint, double> int2_d;
typedef pair<int, ll> intlong;
typedef pair<ll, ll> ll_ll;
typedef pair<intint, int> int2_int;
typedef pair<int, intint> int_int2;
typedef pair<ll, ll_ll> ll_ll2;
typedef pair<ll_ll, ll>ll2_ll;
typedef pair<intint, intint> int2_int2;
typedef pair<ll_ll, ll_ll> ll2_ll2;
typedef pair<char, int> char_int;
typedef pair<int, char> int_char;
typedef complex<double> cpx;

vector<int>lines[200001];
queue<int>bigger;
vector<int>erase_num;

int Union[200001];
bool visit[200001];

int bfs(int p,queue<int>&brr){
	if(visit[p])return -1;
	visit[p]=true;
	
	queue<int>arr;
	arr.push(p);
	
	int counting=0;
	
	while(arr.size()){
		p=arr.front();
		arr.pop();
		counting++;
		if(Union[p]==1)brr.push(p);
		for(int next_p:lines[p]){
			if(visit[next_p])continue;
			visit[next_p]=true;
			arr.push(next_p);
		}
	}
	
	return counting;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m,a,b;
    cin>>n>>m;
    for(int i=1;i<=n;i++){
    	cin>>a;
    	bigger.push(a);
    }
    while(m--){
    	cin>>a>>b;
    	lines[a].push_back(b);
    	lines[b].push_back(a);
    	Union[a]++;
    	Union[b]++;
    }
    
    for(int i=1;i<=n;i++){
    	queue<int>arr;
    	int bfs_sum=bfs(i,arr);
    	if(bfs_sum==-1)continue;
    	
    	if(bfs_sum==1){
    		erase_num.push_back(0);
    		continue;
    	}
    	
    	int counting=0;
    	while(arr.size()){
    		int p=arr.front();
    		arr.pop();
    		counting++;
    		for(int next_p:lines[p]){
    			Union[next_p]--;
    			if(Union[next_p]!=1)continue;
    			arr.push(next_p);
    		}
    	}
    	erase_num.push_back(counting-1);
    }
    
    sort(erase_num.begin(),erase_num.end());
    
    int save_count=0;
   
    for(int h:erase_num){
    	while(h>0 && bigger.size()){
    		h--;
    		int p=bigger.front();
    		bigger.pop();
    		if(p==1)continue;
    		if(save_count<=0){
    			cout<<"No";
    			return 0;
    		}
    		save_count--;
    		h++;
    	}
    	
    	if(h!=0){
    		cout<<"No";
    		return 0;
    	}
    	
    	save_count++;
    }
    
    while(save_count>0 && bigger.size() && bigger.front()==0){
    	bigger.pop();
    	save_count--;
    }
    
    if(save_count>0 || !bigger.empty()){
    	cout<<"No";
    	return 0;
    }
    
    cout<<"Yes";
}