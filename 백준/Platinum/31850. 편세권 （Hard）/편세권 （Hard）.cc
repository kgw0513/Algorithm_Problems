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

struct Node {
    ll x = -1;
    ll y = -1;
    ll Cost = -1;
};

bool cmp(Node& a, Node& b) {
    if(a.y!=b.y)return a.y < b.y;
    return a.x < b.x;
}

class Seg {
private:
    ll Val = 0;
    Seg* LeftSeg = nullptr;
    Seg* RightSeg = nullptr;

public:
    void Init(const int s,const int e) {
        if (s == e) {
            Val = 0;
            return;
        }
        LeftSeg = new Seg();
        RightSeg = new Seg();
        LeftSeg->Init(s, (s + e) / 2);
        RightSeg->Init((s + e) / 2 + 1, e);
    }

    void Insert(const int p,const ll val, const int s, const int e) {
        if (p < s || e < p)return;
        if (s == e) {
            Val = max(Val, p + val);
            return;
        }
        LeftSeg->Insert(p, val, s, (s + e) / 2);
        RightSeg->Insert(p, val, (s + e) / 2 + 1, e);
        Val = max(LeftSeg->Val, RightSeg->Val);
    }

    ll FindVal(const int f_s, const int f_e, const int s, const int e) {
        if (e < f_s || f_e < s)return 0;
        if (f_s <= s && e <= f_e) {
            return Val;
        }
        return max(LeftSeg->FindVal(f_s, f_e, s, (s + e) / 2), RightSeg->FindVal(f_s, f_e, (s + e) / 2 + 1, e));
    }

    ~Seg() {
        if (LeftSeg != nullptr) {
            delete(LeftSeg);
        }
        if (RightSeg != nullptr) {
            delete(RightSeg);
        }
    }
};

ll Cal(vector<Node>arr,const int n,const int m) {
    Seg* rootSeg = new Seg();
    rootSeg->Init(1, n);
    ll ans = lINF;

    sort(arr.begin(), arr.end(), cmp);

    for (Node& h : arr) {
        if (h.Cost == -1) { //편의점
            rootSeg->Insert(h.x, h.y, 1, n);
        }
        else {
            ll h2 = rootSeg->FindVal(1, h.x, 1, n);
            if (h2 == 0)continue;
            //cout << h.Cost << "*" << h.x << "+" << h.y << "-" << h2 << "?\n";
            ans = min(ans, h.Cost * (h.x+h.y-h2));
        }
    }

    return ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, r, c;
    cin >> n >> m >> r >> c;
    vector<Node>arr;
    for (int i = 0; i < r; i++) {
        Node h;
        cin >> h.x >> h.y >> h.Cost;
        arr.push_back(h);
    }
    for (int i = 0; i < c; i++) {
        Node h;
        cin >> h.x >> h.y;
        arr.push_back(h);
    }

    ll ans = Cal(arr, n, m);
    //cout << ans << "나옴.1\n";
    {
        vector<Node>brr;
        for (Node h : arr) {
            h.x = n - h.x+1;
            brr.push_back(h);
        }
        ll h2 = Cal(brr, n, m);
        //cout << h2 << "나옴.2\n";
        ans = min(ans, h2);
    }
    {
        vector<Node>brr;
        for (Node h : arr) {
            h.y = m - h.y+1;
            brr.push_back(h);
        }
        ll h2 = Cal(brr, n, m);
        //cout << h2 << "나옴.3\n";
        ans = min(ans, h2);
    }
    {
        vector<Node>brr;
        for (Node h : arr) {
            h.x = n - h.x+1;
            h.y = m - h.y+1;
            brr.push_back(h);
        }
        ll h2 = Cal(brr, n, m);
        //cout << h2 << "나옴.4\n";
        ans = min(ans, h2);
    }
    cout << ans;
}