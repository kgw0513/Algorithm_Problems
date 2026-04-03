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

class Seg {
    struct Node {
        Node() = default;

        int counting = 0;
        Node* left_Node = nullptr;
        Node* right_Node = nullptr;
    };

    Node* root_Node = nullptr;

    int start_s, start_e;
public:
    Seg() {
        root_Node = new Node();
        start_s = 0;
        start_e = 1000000;
    }

    ~Seg() = default;

    void insert(int p) {
        int s = start_s, e = start_e;
        //cout << s << "<=" << p << "<=" << e << "?\n";
        assert(s <= p && p <= e);
        Node* now_Node = root_Node;
        now_Node->counting++;
        while (!(s == p && p == e)) {
            int mid = (s + e) / 2;
            if (s <= p && p <= mid) {
                e = mid;
                if (now_Node->left_Node == nullptr) {
                    now_Node->left_Node = new Node();
                }
                now_Node = now_Node->left_Node;
            }
            else {
                s = mid + 1;
                if (now_Node->right_Node == nullptr) {
                    now_Node->right_Node = new Node();
                }
                now_Node = now_Node->right_Node;
            }
            now_Node->counting++;
        }
    }

    void erase(int p) {
        int s = start_s, e = start_e;
        assert(s <= p && p <= e);
        Node* now_Node = root_Node;
        now_Node->counting--;
        assert(now_Node->counting >= 0);
        
        while (!(s == p && p == e)) {
            int mid = (s + e) / 2;
            if (s <= p && p <= mid) {
                e = mid;
                if (now_Node->left_Node == nullptr) {
                    now_Node->left_Node = new Node();
                }
                now_Node = now_Node->left_Node;
            }
            else {
                s = mid + 1;
                if (now_Node->right_Node == nullptr) {
                    now_Node->right_Node = new Node();
                }
                now_Node = now_Node->right_Node;
            }
            now_Node->counting--;
            assert(now_Node->counting >= 0);
        }
    }

    int find_by_order(int c) {
        int s = start_s, e = start_e;
        Node* now_Node = root_Node;
        assert(c <= now_Node->counting);

        while (s < e) {
            /*cout << s << "~" << e << "에서 " <<
                (now_Node->left_Node!=nullptr?now_Node->left_Node->counting:-100) << "vs" <<
                (now_Node->right_Node != nullptr ? now_Node->right_Node->counting : -100) << "?\n";*/
            int mid = (s + e) / 2;
            if (now_Node->left_Node != nullptr && c <= now_Node->left_Node->counting) {
                now_Node = now_Node->left_Node;
                e = mid;
            }
            else {
                c -= (now_Node->left_Node != nullptr ? now_Node->left_Node->counting : 0);
                assert(now_Node->right_Node != nullptr);
                now_Node = now_Node->right_Node;
                s = mid + 1;
            }
        }

        assert(s == e);
        assert(c == 1);
        return s;
    }
};

Seg score_rank;
int score_to_player[1000002];
int player_to_score[1000002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int q;
    cin >> q;
    vector<pair<char, intint>>inputs(q, { 'x',{-1,-1} });
    for (int i = 0; i < q; i++) {
        cin >> inputs[i].fi >> inputs[i].se.fi;
        if (inputs[i].fi == 'N' || inputs[i].fi == 'M')cin >> inputs[i].se.se;
    }

    {
        set<int>rank_insert_num;
        unordered_map<int, int> rank_transform;

        for (int i = 0; i < q; i++) {
            rank_insert_num.insert(inputs[i].se.se);
        }

        for (auto h : rank_insert_num) {
            static int give_num = 0;
            give_num++;
            rank_transform[h] = give_num;
        }

        for (int i = 0; i < q; i++) {
            inputs[i].se.se = rank_transform[inputs[i].se.se];
        }
    }

    for (int i = 0; i < q; i++) {
        char a;
        int x, r;
        a = inputs[i].fi;
        x = inputs[i].se.fi;
        r = inputs[i].se.se;
        if (a == 'N') {
            r = 1000000 - r;
            score_rank.insert(r);
            score_to_player[r] = x;
            player_to_score[x] = r;
            continue;
        }
        else if (a == 'M') {
            r = 1000000 - r;
            score_rank.erase(player_to_score[x]);
            score_rank.insert(r);
            score_to_player[r] = x;
            player_to_score[x] = r;
            continue;
        }
        cout << score_to_player[(score_rank.find_by_order(x))] << "\n";
    }
}