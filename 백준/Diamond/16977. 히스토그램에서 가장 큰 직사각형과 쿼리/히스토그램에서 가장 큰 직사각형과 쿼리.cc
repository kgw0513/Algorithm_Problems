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

struct Node {
    intint lr = { 0,0 };
    int max_len = 0;

    Node* left_Node = nullptr;
    Node* right_Node = nullptr;

    Node() = delete;

    Node(int s, int e) {
        assert(s <= e);
        if (s == e)return;
        left_Node = new Node(s, (s + e) / 2);
        right_Node = new Node((s + e) / 2 + 1, e);
        lr = { 0,0 };
        max_len = 0;
    }

    void Clear() {
        if (left_Node != nullptr)left_Node->Clear();
        if (right_Node != nullptr)right_Node->Clear();
        lr = { 0,0 };
        max_len = 0;
    }


    int2_int insert_num(int s,int e,const int p) {
        assert(s <= e);

        if (p < s || e < p) return { lr,max_len };

        if (s == e) {
            max_len = 1;
            lr = { 1,1 };
            return { lr,max_len };
        }

        int l_len = (s + e) / 2 - s + 1;
        int r_len = e - ((s + e) / 2 + 1) + 1;
        int2_int lv = left_Node->insert_num(s, (s + e) / 2, p);
        int2_int rv = right_Node->insert_num((s + e) / 2 + 1, e, p);

        //cout << s << "~" << e << "에서.\n";
        //cout << l_len << "과 " << r_len << "!\n";
        //cout << l_len << "==" << lv.se << "?\n";
        if (l_len == lv.se) {
            lr.fi = lv.se + rv.fi.fi;
        }
        else {
            lr.fi = lv.fi.fi;
        }

        if (r_len == rv.se) {
            lr.se = rv.se + lv.fi.se;
        }
        else {
            lr.se = rv.fi.se;
        }

        max_len = max({ max_len,lr.fi,lr.se });
        max_len = max({ max_len,lv.se,rv.se ,lv.fi.se + rv.fi.fi });

        return { lr,max_len };
    }

    int2_int find_num(int s, int e, const int fs, const int fe) {
        assert(s <= e);

        if (fe < s || e < fs)return { {0,0} ,0 };

        if (fs <= s && e <= fe) return { lr,max_len };

        int l_len = (s + e) / 2 - s + 1;
        int r_len = e - ((s + e) / 2 + 1) + 1;
        int2_int lv = left_Node->find_num(s, (s + e) / 2, fs, fe);
        int2_int rv = right_Node->find_num((s + e) / 2 + 1, e, fs, fe);

        //cout << s << "~" << e << "에서.\n";
        //cout << l_len << "과 " << r_len << "!\n";
        //cout << lv.fi.fi << "," << lv.fi.se << "|" << lv.se << " / " << rv.fi.fi << "," << rv.fi.se << "|" << rv.se << "\n";
        intint h = {};
        int h_max = 0;

        if (l_len == lv.se) {
            h.fi = lv.se + rv.fi.fi;
        }
        else {
            h.fi = lv.fi.fi;
        }

        if (r_len == rv.se) {
            h.se = rv.se + lv.fi.se;
        }
        else {
            h.se = rv.fi.se;
        }

        h_max = max({ h_max,h.fi,h.se });
        h_max = max({ h_max,lv.se,rv.se ,lv.fi.se + rv.fi.fi });

        return { h,h_max };
    }
};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, q;
    cin >> n;
    vector<ll_ll>inputs(n);
    for (int i = 1; i <= n; i++) {
        cin >> inputs[i - 1].fi;
        inputs[i - 1].se = i;
    }
    sort(inputs.begin(), inputs.end(), greater<ll_ll>());

    cin >> q;
    vector<ll2_ll>quest(q);
    vector<ll_ll>q_range(q);
    vector<ll>ans(q,-1);
    for (int i = 0; i < q; i++) {
        cin >> quest[i].fi.fi >> quest[i].fi.se >> quest[i].se;
        q_range[i] = { 0,n - 1 };
    }

    Node* Seg = new Node(1, n);

    while (true) {
        map<ll, vector<ll>>arr;
        for (int i = 0; i < q; i++) {
            if (!(q_range[i].fi <= q_range[i].se))continue;
            ll mid = (q_range[i].fi + q_range[i].se) / 2;
            mid = inputs[mid].fi;
            arr[-mid].push_back(i);
        }

        if (arr.empty())break;

        for (ll_ll& inp : inputs) {
            //cout << inp.fi << "들.\n";
            while (!arr.empty() && (-arr.begin()->fi) > inp.fi) {
                //cout << -arr.begin()->fi << " vs " << inp.fi << "에서 실행중.\n";
                for (ll p : arr.begin()->se) {
                    ll h = Seg->find_num(1, n, quest[p].fi.fi, quest[p].fi.se).se;
                    //cout << p << "의 " << h << "상태.\n";
                    ll mid = (q_range[p].fi + q_range[p].se) / 2;
                    if (h >= quest[p].se) {
                        ans[p] = -arr.begin()->fi;
                        q_range[p] = { q_range[p].fi,mid - 1 };
                    }
                    else {
                        q_range[p] = { mid + 1,q_range[p].se };
                    }
                }
                arr.erase(arr.begin());
            }
            Seg->insert_num(1, n, inp.se);
        }
        while (!arr.empty()) {
            for (ll p : arr.begin()->se) {
                ll h = Seg->find_num(1, n, quest[p].fi.fi, quest[p].fi.se).se;
                //cout << p << "의 " << h << "상태.\n";
                ll mid = (q_range[p].fi + q_range[p].se) / 2;
                if (h >= quest[p].se) {
                    ans[p] = -arr.begin()->fi;
                    q_range[p] = { q_range[p].fi,mid - 1 };
                }
                else {
                    q_range[p] = { mid + 1,q_range[p].se };
                }
            }
            arr.erase(arr.begin());
        }

        //cout << "현 결과 : \n";
        //for (int i = 0; i < q; i++) {
        //    cout << i << "의 범위 : " << q_range[i].fi << "~" << q_range[i].se << " | " << i << "의 현 답 : " <<  ans[i] << "\n";
        //}
        Seg->Clear();
    }

    for (int i = 0; i < q; i++) {
        assert(ans[i] != -1);
        cout << ans[i] << "\n";
    }
}