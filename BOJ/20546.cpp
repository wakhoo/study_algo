#include <bits/stdc++.h>
using namespace std;

int main() {
    int M; 
    if (!(cin >> M)) return 0;

    vector<int> price(14);
    for (int i = 0; i < 14; i++) cin >> price[i];

    int cash_bnp = M, stock_bnp = 0;
    int cash_tmg = M, stock_tmg = 0;

    for (int i = 0; i < 14; i++) {
        int p = price[i];
        if (cash_bnp >= p) {
            int qty = cash_bnp / p;
            stock_bnp += qty;
            cash_bnp -= qty * p;
        }
        if (i >= 3) {
            int a = price[i - 3], b = price[i - 2], c = price[i - 1];
            if (a < b && b < c) {
                if (stock_tmg > 0) {
                    cash_tmg += stock_tmg * p;
                    stock_tmg = 0;
                }
            } else if (a > b && b > c) {
                if (cash_tmg >= p) {
                    int qty = cash_tmg / p;
                    stock_tmg += qty;
                    cash_tmg -= qty * p;
                }
            }
        }
    }

    int final_bnp = cash_bnp + stock_bnp * price.back();
    int final_tmg = cash_tmg + stock_tmg * price.back();

    if (final_bnp > final_tmg) cout << "BNP\n";
    else if (final_bnp < final_tmg) cout << "TIMING\n";
    else cout << "SAMESAME\n";

    return 0;
}
