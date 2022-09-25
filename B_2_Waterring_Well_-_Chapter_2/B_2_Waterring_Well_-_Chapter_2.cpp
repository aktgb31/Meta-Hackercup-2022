/*
  Created by: Amit Kumar at 17:55 on 11 Sep 22
*/
#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define db(...)
#endif
using namespace std;

#define all(x) x.begin(), x.end()

inline constexpr int MAXN = 2e5 + 1;
inline constexpr int mod = 1e9 + 7;

#define int long long

void solve()
{
    int n, q;
    cin >> n;

    vector<int> x(n), y(n);
    for (int i = 0; i < n; i++)
        cin >> x[i] >> y[i];

    int sumOfSquareX = 0, sumOfSquareY = 0, sumOfX = 0, sumOfY = 0;
    for (int i = 0; i < n; i++)
    {
        sumOfSquareX += x[i] * x[i];
        sumOfSquareY += y[i] * y[i];
        sumOfX += x[i];
        sumOfY += y[i];

        sumOfSquareX %= mod;
        sumOfSquareY %= mod;
        sumOfX %= mod;
        sumOfY %= mod;
    }

    cin >> q;
    int fans = 0;
    for (int i = 0; i < q; i++)
    {
        int qx, qy;
        cin >> qx >> qy;
        int ans = 0;

        int squareQx = (qx * qx) % mod;
        int squareQy = (qy * qy) % mod;
        ans = (ans + n * squareQx) % mod;
        ans = (ans + n * squareQy) % mod;
        ans = (ans + sumOfSquareX) % mod;
        ans = (ans + sumOfSquareY) % mod;
        ans = (ans - 2ll * qx * sumOfX) % mod;
        ans = (ans - 2ll * qy * sumOfY) % mod;

        fans = (fans + ans) % mod;
    }
    fans = (fans + mod) % mod;
    cout << fans << "\n";
}
int32_t main()
{
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    auto started = std::chrono::high_resolution_clock::now();
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    t = 1;
    cin >> t;
    for (int I = 1; I <= t; I++)
    {
        cout << "Case #" << I << ": ";
        solve();
    }
#ifdef LOCAL
    auto done = std::chrono::high_resolution_clock::now();
    cerr << "Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " ms\n";
#endif
    return 0;
}