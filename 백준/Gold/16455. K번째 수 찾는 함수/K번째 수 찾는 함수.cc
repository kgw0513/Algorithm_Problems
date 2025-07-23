#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#define fi first
#define se second
using namespace std;
typedef pair<int, int> intint;

int kth(vector<int>& a, int k) {
    k = a.size() - k + 1;
    int s = -1000000000, e = 1000000000, ans = s;
    while (s <= e) {
        int mid = (s + e) / 2;
        int up_count = 0;
        for (int& h : a) {
            if (mid <= h)up_count++;
        }
        if (up_count >= k) {
            ans = mid;
            s = mid + 1;
        }
        else {
            e = mid - 1;
        }
    }
    return ans;
}