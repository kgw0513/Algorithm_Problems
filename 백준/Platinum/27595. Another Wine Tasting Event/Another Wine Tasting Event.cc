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
//#include <ext/rope>
#pragma warning(disable:4996)
#define f first
#define s second
using namespace std;
//using namespace __gnu_cxx;

const long long INF = 2147483647;
const long long lINF = 9000000000000000000;
const int nINF = 1000000000;
unsigned long long MOD = 1000000007;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<short, short>sh_sh;
typedef pair<int, int> intint;
typedef pair<int, double> int_d;
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
	int n;
	string w;
	cin >> n >> w;
	ll now_white_wine = 0;
	for (int i = 0; i < n; i++) {
		if (w[i] == 'W')now_white_wine++;
	}
	ll now_max_ans = 0;
	for (int i = n-1; i < w.size(); i++) {
		if (now_max_ans <= now_white_wine) {
			now_max_ans = now_white_wine;
		}

		if (w[i + 1 - n] == 'W')now_white_wine--;
		if (w[i + 1] == 'W')now_white_wine++;
    }
	cout << now_max_ans;
}