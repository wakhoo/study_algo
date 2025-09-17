#include <bits/stdc++.h>
using namespace std;

int main() {
    int board[5][5];
    pair<int,int> pos[26];
    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            int x; cin >> x;
            board[r][c] = x;
            pos[x] = {r, c};
        }
    }

    bool marked[5][5] = {false};

  //auto type detection
    auto countBingo = [&]() {
        int cnt = 0;
        for (int r = 0; r < 5; ++r) {
            bool ok = true;
            for (int c = 0; c < 5; ++c) if (!marked[r][c]) { ok = false; break; }
            if (ok) ++cnt;
        }
        for (int c = 0; c < 5; ++c) {
            bool ok = true;
            for (int r = 0; r < 5; ++r) if (!marked[r][c]) { ok = false; break; }
            if (ok) ++cnt;
        }
        {
            bool ok = true;
            for (int i = 0; i < 5; ++i) if (!marked[i][i]) { ok = false; break; }
            if (ok) ++cnt;
        }
        {
            bool ok = true;
            for (int i = 0; i < 5; ++i) if (!marked[i][4 - i]) { ok = false; break; }
            if (ok) ++cnt;
        }
        return cnt;
    };

    int callCount = 0;

    for (int r = 0; r < 5; ++r) {
        for (int c = 0; c < 5; ++c) {
            int x; cin >> x;
            ++callCount;

            auto [i, j] = pos[x];
            marked[i][j] = true;

            if (countBingo() >= 3) {
                cout << callCount << '\n';
                return 0;
            }
        }
    }
    return 0;
}
