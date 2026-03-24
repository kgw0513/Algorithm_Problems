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

vector<int>arr;

class Node {
public:
    Node* Left_Node = nullptr;
    Node* Right_Node = nullptr;

    int Insert_Time = 0;

    explicit Node(Node* l = nullptr, Node* r = nullptr) :Left_Node(l), Right_Node(r) {
        static int Give_Time = 0;
        Insert_Time = ++Give_Time;
    }

    ~Node() {
        if (Left_Node != nullptr)delete(Left_Node);
        if (Right_Node != nullptr)delete(Right_Node);
    }

    void GetOut() {
        if (Left_Node != nullptr)Left_Node->GetOut();
        arr.push_back(Insert_Time);
        if (Right_Node != nullptr)Right_Node->GetOut();
    }
};

vector<Node*> DepthNode[300002];
int Ans[300002];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    Node* Root_Node = new Node();
    DepthNode[0].push_back(Root_Node);

    int n, w;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> w;
        if (DepthNode[w - 1].empty()) {
            cout << -1;
            delete(Root_Node);
            return 0;
        }

        Node* New_Node = new Node();
        if (DepthNode[w - 1].back()->Left_Node == nullptr) {
            DepthNode[w - 1].back()->Left_Node = New_Node;
        }
        else if (DepthNode[w - 1].back()->Right_Node == nullptr) {
            DepthNode[w - 1].back()->Right_Node = New_Node;
            DepthNode[w - 1].pop_back();
        }
        else return -1;

        DepthNode[w].push_back(New_Node);
    }

    Root_Node->GetOut();

    for (int i = 0; i < arr.size(); i++) {
        Ans[arr[i]] = i + 1;
    }

    for (int i = 1; i <= n; i++) {
        cout << Ans[i] << " ";
    }
    
    delete(Root_Node);
}