#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    if (!(cin >> N)) return 0;

    vector<int> T(N + 2), P(N + 2);
    for (int i = 1; i <= N; ++i) {
        cin >> T[i] >> P[i];
    }

    vector<long long> dp(N + 2, 0);

    for (int i = N; i >= 1; --i) {
        int finish = i + T[i];
        if (finish <= N + 1) {
            dp[i] = max(dp[i + 1], P[i] + dp[finish]);
        } else {
            dp[i] = dp[i + 1];
        }
    }

    cout << dp[1] << "\n";
    return 0;
}
