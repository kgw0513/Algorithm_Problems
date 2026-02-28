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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin>>t;
    while(t--){
    	//{값,위치}
    	priority_queue<ll_ll>arr;
    	ll n;
    	cin>>n;
    	vector<ll_ll>ans;
    	ll a=0,b=0;
    	for(int i=0;i<n;i++){
    		ll w;
    		cin>>w;
    		ll h=(w-1)/2;
    		a+=h;
    		b+=(w-h);
    		arr.push({w-h,i});
    		ans.push_back({h,(w-h)});
    	}
    	ll loop=(n-1)/2;
    	while(loop>0){
    		loop--;
    		a+=arr.top().fi;
    		b-=arr.top().fi;
    		ans[arr.top().se].fi+=arr.top().fi;
    		ans[arr.top().se].se-=arr.top().fi;
    		arr.pop();
    	}
    	//cout<<a<<"vs"<<b<<"\n";
    	//cout<<arr.size()<<"?\n";
    	bool is_even=(n%2==0);
    	while(is_even && !arr.empty()){
    		//cout<<"들.\n";
    		if((ans[arr.top().se].fi+ans[arr.top().se].se)%2==0){
    			ll h=(ans[arr.top().se].fi+ans[arr.top().se].se)/2;
    			//cout<<arr.top().se<<"들.\n";
    			is_even=false;
    			a-=ans[arr.top().se].fi;
    			b-=ans[arr.top().se].se;
    			ans[arr.top().se].fi=h;
    			ans[arr.top().se].se=h;
    		}
    		arr.pop();
    	}
    	
    	if(a>b){
    		cout<<"YES\n";
    		for(int i=0;i<n;i++){
    			cout<<ans[i].fi;
    			if(i+1!=n)cout<<" ";
    		}
    		cout<<"\n";
    		for(int i=0;i<n;i++){
    			cout<<ans[i].se;
    			if(i+1!=n)cout<<" ";
    		}
    		cout<<"\n";
    	}
    	else{
    		cout<<"NO\n";
    	}
    }
}