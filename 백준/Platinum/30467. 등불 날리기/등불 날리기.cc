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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#define ordered_set tree<int, null_type, less_equal<int>, rb_tree_tag,tree_order_statistics_node_update>

#pragma warning(disable:4996)
#define fi first
#define se second
using namespace std;

//rope c++
//#include <ext/rope>
//using namespace __gnu_cxx;

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

사용법 :
(Set 이름).order_of_key(NUM) : ordered_set 에서 NUM 보다 작은(미만의) 원소의 개수를 반환한다. 
(Set 이름).find_by_order(K) : ordered_set 에서 (K+1)번째 원소가 있는 iterator 을 반환한다. (K가 0이면 1번째)
*/

//unordered_set, unordered_map 전용 (구조체로 쓸 경우 == operator도 필요)
//사용 예시 : unordered_set<intint,pair_hash> arr;
namespace std {
    struct default_hash {
        template <class T1>
        size_t operator()(const T1 n) const {
            hash<T1> a{}; size_t sa = a(n);
            return sa;
        }
    };
    struct pair_hash {
        template <class T1, class T2>
        size_t operator()(const pair<T1, T2> n) const {
            hash<T1> a{}; size_t sa = a(n.fi);
            hash<T2> b{}; size_t sb = b(n.se);
            return sa ^ sb;
        }
    };
}

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

void OS_erase(ordered_set &OS,int n){
    auto h = OS.find_by_order(OS.order_of_key(n));
    OS.erase(h);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, s, a;
    cin >> n >> s;

    queue<int>arr;
    ordered_set brr;
    ll ans = 0, sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        // cout<<a<<"들.\n";
        sum+=brr.order_of_key(a);
        // cout<<sum<<"상태.\n";
        brr.insert(a);
        arr.push(a);
        while(arr.size()>s){
            a=arr.front();
            // cout<<a<<" 나감.\n";
            arr.pop();
            OS_erase(brr,a);
            // cout<<sum<<"=>";
            // cout<<int(brr.size())<<"-"<<brr.order_of_key(a+1)<<"로 ";
            sum-=int(brr.size())-brr.order_of_key(a+1);
            // cout<<sum<<"\n";
        }
        ans=max(ans,sum);
    }
    cout<<ans;
}