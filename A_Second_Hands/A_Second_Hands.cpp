/*
  Created by: Amit Kumar at 22:31 on 26 Aug 22
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

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> mp(101, 0);
    int count = 0;

    bool possible = true;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        ++mp[x];
        if (mp[x] > 2)
        {
            possible = false;
        }
        else
            ++count;
    }
    // cerr << count << " " << n << " " << k << "\n";
    if (!possible || count > 2 * k)
        cout << "NO\n";
    else
        cout << "YES\n";
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