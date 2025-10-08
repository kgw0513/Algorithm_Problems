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

struct Point {
    ll x, y, z;

    Point operator-(Point a) {
        Point h;
        h.x = this->x - a.x;
        h.y = this->y - a.y;
        h.z = this->z - a.z;

        return h;
    }

    ll operator*(Point a) {
        ll h = 0;
        h += this->x * a.x;
        h += this->y * a.y;
        h += this->z * a.z;

        return h;
    }
};

enum class State : uint8_t {
    None,
    p3Empty,
    Fill
};

class SpiderWeb {
private:
    State WebState = State::None;
    Point p[2];
    Point NormalVector;
    Point CCW(Point a, Point b) {
        Point c;
        c.x = a.y * b.z - a.z * b.y;
        c.y = a.x * b.z - a.z * b.x;
        c.y *= -1;
        c.z = a.x * b.y - a.y * b.x;
        return c;
    }

public:
    SpiderWeb(Point a, Point b) {
        p[0] = a;
        p[1] = b;
        WebState = State::p3Empty;
    }
    SpiderWeb() = delete;

    bool InsertFly(Point a) {
        if (WebState == State::p3Empty) {
            Point h = CCW(p[1] - p[0], a - p[0]);

            if (h.x == 0 && h.y == 0 && h.z == 0)return true;
            NormalVector = h;
            WebState = State::Fill;
            return true;
        }
        else {
            //법선벡터와의 내적했더니 0이 아닐경우 false만들기
            ll h = (a-p[0]) * NormalVector;
            if (h != 0) {
                return false;
            }
            return true;
        }
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    SpiderWeb* ans = nullptr;
    int t;
    cin >> t;
    if (t <= 3) {
        cout << "TAK";
        return 0;
    }

    t -= 2;

    {
        Point a, b;
        cin >> a.x >> a.y >> a.z;
        cin >> b.x >> b.y >> b.z;
        ans = new SpiderWeb(a, b);
    }

    while (t--) {
        Point a;
        cin >> a.x >> a.y >> a.z;
        if (!ans->InsertFly(a)) {
            cout << "NIE";
            return 0;
        }
    }
    cout << "TAK";
}