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
constexpr unsigned long long MOD1 = 1000000363;
constexpr unsigned long long MOD2 = 1000000007;
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

vector<int>arr = { 220,284,1184,1210,2620,2924,5020,5564,6232,6368,10744,10856,12285,14595,17296,18416,63020,76084,66928,66992,67095,71145,69615,87633,79750,88730,100485,124155,122265,139815,122368,123152,141664,153176,142310,168730,171856,176336,176272,180848,185368,203432,196724,202444,280540,365084,308620,389924,319550,430402,356408,399592,437456,455344,469028,486178,503056,514736,522405,525915,600392,669688,609928,686072,624184,691256,635624,712216,643336,652664,667964,783556,726104,796696,802725,863835,879712,901424,898216,980984 };
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	while (1) {
		int w;
		cin >> w;
		if (w == 0)break;
		cout << "\n";

		cout << "Amicable numbers between 1 and " << w << "\n";
		bool found_one = false;
		for(int i=0;i<arr.size();i+=2){
			if (arr[i] > w)break;
			if (arr[i + 1] > w)continue;
			found_one = true;
			cout << arr[i] << " " << arr[i + 1] << "\n";
		}
		if (!found_one) {
			cout << "None\n";
		}
	}
}