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
#define print_end "\n"
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
    bool is_range=false;
    int vector_Node_p=-1;
    int num=-1;

    Node(bool a, int b, int c) {
        if (a == true) {
            is_range = a;
            vector_Node_p = b;
        }
        else {
            num = c;
        }
    }
};
vector<Node>lines[200002];
vector<int>inputs;

int s = 0;
static int lines_count = 0;
int cal(const int now_num) {
    int line_number = ++lines_count;
    for (; s < inputs.size(); s++) {
        if (inputs[s] != now_num) {
            if (inputs[s] < now_num)break;
            int h= cal(now_num + 2);
            lines[line_number].push_back(Node(true, h, -1));
        }
        else {
            lines[line_number].push_back(Node(false, -1, s + 1));
        }
    }
    lines[line_number].push_back(Node(false, -1, s + 1));

    return line_number;
}

void print_ans(int now_line,bool is_flip) {
    //cout << now_line << "중!\n";
    if (!is_flip) {
        for (int i = 0; i < lines[now_line].size(); i++) {
            //cout << now_line << "에서.\n";
            //cout << lines[now_line][i].is_range << "," << lines[now_line][i].num << "," << lines[now_line][i].vector_Node_p << "??\n";
            if (lines[now_line][i].is_range == false) {
                cout << lines[now_line][i].num << " ";
            }
            else {
                print_ans(lines[now_line][i].vector_Node_p, !is_flip);
            }
        }
    }
    else {
        for (int i = lines[now_line].size()-1; i>=0; i--) {
            if (lines[now_line][i].is_range == false) {
                cout << lines[now_line][i].num << " ";
            }
            else {
                print_ans(lines[now_line][i].vector_Node_p, !is_flip);
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, w;
    cin >> n;
    for (int i = 1; i < n; i++) {
        cin >> w;
        inputs.push_back(w);
    }

    print_ans(cal(1), false);
}