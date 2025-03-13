#include <iostream>
bool check[1000001];
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    for (int i = 1; i <= 1000000; i++) {
        bool now_win = false;
        for (int j = 1; j * j <= i; j++) {
            now_win |= !check[i - j * j];
        }
        check[i] = now_win;
    }
    int t;
    std::cin >> t;
    while (t--) {
        int n;
        std::cin >> n;
        std::cout << (check[n] ? "koosaga" : "cubelover") << "\n";
    }
}