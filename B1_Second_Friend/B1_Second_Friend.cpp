/*
  Created by: Amit Kumar at 15:39 on 27 Aug 22
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
    int r, c;
    cin >> r >> c;
    vector<string> arr(r);

    int countTree = 0;
    for (auto &str : arr)
    {
        cin >> str;
        countTree += count(all(str), '^');
    }
    if ((r == 1 || c == 1) && countTree)
    {
        cout << "Impossible\n";
    }
    else
    {
        cout << "Possible\n";
        if (r > 1 && c > 1)
            for (auto &str : arr)
            {
                fill(all(str), '^');
            }

        for (auto &str : arr)
        {
            cout << str << '\n';
        }
    }
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