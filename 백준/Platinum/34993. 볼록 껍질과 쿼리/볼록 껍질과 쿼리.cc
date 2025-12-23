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
#define print_end endl
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
 
int trash_input;
intint ans[102];
void cal(int loop) {
    for (int i = 0; i < loop; i++) {
        vector<int>nums = { 6 * i + 1,6 * i + 2,6 * i + 3,6 * i + 4,6 * i + 5,6 * i + 6 };
        cout << "? 3 " << nums[0] << " " << nums[1] << " " << nums[2] << print_end;
        intint w;
        cin >> trash_input;
        set<intint>inputsA;
        set<intint>inputsB;
        for (int j = 0; j < 3; j++) {
            cin >> w.fi >> w.se;
            inputsA.insert(w);
        }
 
        cout << "? 3 " << nums[0] << " " << nums[3] << " " << nums[4] << print_end;
        cin >> trash_input;
        for (int j = 0; j < 3; j++) {
            cin >> w.fi >> w.se;
            if (inputsA.find(w) != inputsA.end()) {
                ans[nums[0]] = w;
                inputsA.erase(w);
            }
            else {
                inputsB.insert(w);
            }
        }
 
        cout << "? 3 " << nums[1] << " " << nums[4] << " " << nums[5] << print_end;
        cin >> trash_input;
        for (int j = 0; j < 3; j++) {
            cin >> w.fi >> w.se;
            if (inputsA.find(w) != inputsA.end()) {
                ans[nums[1]] = w;
                inputsA.erase(w);
            }
            else if (inputsB.find(w) != inputsB.end()) {
                ans[nums[4]] = w;
                inputsB.erase(w);
            }
            else {
                ans[nums[5]] = w;
            }
        }
 
        ans[nums[2]] = *inputsA.begin();
        ans[nums[3]] = *inputsB.begin();
    }
}
 
void print_ans(int n) {
    cout << "!";
    for (int i = 1; i <= n; i++) {
        cout << " " << ans[i].fi << " " << ans[i].se;
    }
    cout << print_end;
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    intint w;
    cin >> n;
    vector<int>nums;
    if (n % 6 == 2 || n % 6 == 4) {
        cal(n / 6 - 1);
        int start_num = 6 * (n / 6 - 1) + 1;
        for (int i = start_num; i <= n; i++) {
            nums.push_back(i);
        }
 
        if (n % 6 == 2) {
            set<intint>inputsA;
            set<intint>inputsB;
 
            cout << "? 3 " << nums[0] << " " << nums[1] << " " << nums[2] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                inputsA.insert(w);
            }
            
            cout << "? 3 " << nums[3] << " " << nums[4] << " " << nums[5] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                inputsB.insert(w);
            }
 
            cout << "? 3 " << nums[0] << " " << nums[3] << " " << nums[6] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                if (inputsA.find(w) != inputsA.end()) {
                    inputsA.erase(w);
                    ans[nums[0]] = w;
                }
                else if (inputsB.find(w) != inputsB.end()) {
                    inputsB.erase(w);
                    ans[nums[3]] = w;
                }
                else {
                    ans[nums[6]] = w;
                }
            }
 
            cout << "? 3 " << nums[1] << " " << nums[4] << " " << nums[7] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                if (inputsA.find(w) != inputsA.end()) {
                    inputsA.erase(w);
                    ans[nums[1]] = w;
                }
                else if (inputsB.find(w) != inputsB.end()) {
                    inputsB.erase(w);
                    ans[nums[4]] = w;
                }
                else {
                    ans[nums[7]] = w;
                }
            }
 
            ans[nums[2]] = *inputsA.begin();
            ans[nums[5]] = *inputsB.begin();
        }
        else if (n % 6 == 4) {
            set<intint>inputsA;
            set<intint>inputsB;
            set<intint>inputsC;
            set<intint>inputsD;
 
            cout << "? 3 " << nums[0] << " " << nums[1] << " " << nums[2] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                inputsA.insert(w);
            }
 
            cout << "? 3 " << nums[0] << " " << nums[3] << " " << nums[4] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                if (inputsA.find(w) != inputsA.end()) {
                    inputsA.erase(w);
                    ans[nums[0]] = w;
                }
                else {
                    inputsB.insert(w);
                }
            }
 
            cout << "? 3 " << nums[1] << " " << nums[6] << " " << nums[7] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                if (inputsA.find(w) != inputsA.end()) {
                    inputsA.erase(w);
                    ans[nums[1]] = w;
                }
                else {
                    inputsC.insert(w);
                }
            }
 
            ans[nums[2]] = *inputsA.begin();
 
            cout << "? 3 " << nums[6] << " " << nums[5] << " " << nums[8] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                if (inputsC.find(w) != inputsC.end()) {
                    inputsC.erase(w);
                    ans[nums[6]] = w;
                }
                else {
                    inputsD.insert(w);
                }
            }
 
            ans[nums[7]] = *inputsC.begin();
 
            cout << "? 3 " << nums[3] << " " << nums[8] << " " << nums[9] << print_end;
            cin >> trash_input;
            for (int i = 0; i < 3; i++) {
                cin >> w.fi >> w.se;
                if (inputsB.find(w) != inputsB.end()) {
                    inputsB.erase(w);
                    ans[nums[3]] = w;
                }
                else if (inputsD.find(w) != inputsD.end()) {
                    ans[nums[8]] = w;
                    inputsD.erase(w);
                }
                else {
                    ans[nums[9]] = w;
                }
            }
 
            ans[nums[4]] = *inputsB.begin();
            ans[nums[5]] = *inputsD.begin();
 
        }
 
        print_ans(n);
        return 0;
    }
    cal(n / 6);
    int start_num = 6 * (n / 6) + 1;
    for (int i = start_num; i <= n; i++) {
        nums.push_back(i);
    }
 
    if (n % 6 == 1) {
        cout << "? 3 " << 1 << " " << 2 << " " << nums[0] << print_end;
        cin >> trash_input;
        for (int i = 0; i < 3; i++) {
            cin >> w.fi >> w.se;
            if (ans[1] == w || ans[2] == w)continue;
            ans[nums[0]] = w;
        }
    }
    else if (n % 6 == 3) {
        set<intint>inputsA;
        cout << "? 3 " << 1 << " " << nums[0] << " " << nums[1] << print_end;
        cin >> trash_input;
        for (int i = 0; i < 3; i++) {
            cin >> w.fi >> w.se;
            if (ans[1] == w)continue;
            inputsA.insert(w);
        }
        cout << "? 3 " << 1 << " " << nums[1] << " " << nums[2] << print_end;
        cin >> trash_input;
        for (int i = 0; i < 3; i++) {
            cin >> w.fi >> w.se;
            if (ans[1] == w)continue;
            if (inputsA.find(w) != inputsA.end()) {
                ans[nums[1]] = w;
                inputsA.erase(w);
            }
            else {
                ans[nums[2]] = w;
            }
        }
        ans[nums[0]] = *inputsA.begin();
    }
    else if (n % 6 == 5) {
        set<intint>inputsA;
        set<intint>inputsB;
        cout << "? 3 " << nums[0] << " " << nums[1] << " " << nums[2] << print_end;
        cin >> trash_input;
        for (int i = 0; i < 3; i++) {
            cin >> w.fi >> w.se;
            inputsA.insert(w);
        }
        cout << "? 3 " << nums[0] << " " << nums[1] << " " << nums[3] << print_end;
        cin >> trash_input;
        for (int i = 0; i < 3; i++) {
            cin >> w.fi >> w.se;
            if (inputsA.find(w) != inputsA.end()) {
                inputsB.insert(w);
            }
            else {
                ans[nums[3]] = w;
            }
        }
        cout << "? 3 " << nums[1] << " " << nums[2] << " " << nums[4] << print_end;
        cin >> trash_input;
        for (int i = 0; i < 3; i++) {
            cin >> w.fi >> w.se;
            if (inputsA.find(w) != inputsA.end()) {
                if (inputsB.find(w) != inputsB.end()) {
                    ans[nums[1]] = w;
                    inputsB.erase(w);
                }
                else {
                    ans[nums[2]] = w;
                }
            }
            else {
                ans[nums[4]] = w;
            }
        }
        ans[nums[0]] = *inputsB.begin();
    }
 
    print_ans(n);
    return 0;
}
