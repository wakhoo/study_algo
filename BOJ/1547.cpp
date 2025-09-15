#include <bits/stdc++.h>
using namespace std;

int main() {
    int M; 
    if (!(cin >> M)) return 0;
    int pos = 1;
    while (M--) {
        int a, b; 
        cin >> a >> b;
        if (pos == a) pos = b;
        else if (pos == b) pos = a;
    }
    cout << pos << "\n";
    return 0;
}
