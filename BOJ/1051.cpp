#include <bits/stdc++.h>
using namespace std;

int main() {

    int N, M;
    if (!(cin >> N >> M)) return 0;

    vector<string> board(N);
    for (int i = 0; i < N; ++i)
	    cin >> board[i];

    int limit = min(N, M);

    for (int s = limit; s >= 1; --s) {
        for (int i = 0; i + s - 1 < N; ++i) {
            for (int j = 0; j + s - 1 < M; ++j) {
                char c = board[i][j];
                int i2 = i + s - 1, j2 = j + s - 1;
                if (c == board[i][j2] && c == board[i2][j] && c == board[i2][j2]) {
                    cout << s * s << '\n';
                    return 0;
                }
            }
        }
    }
    return 0;
}
