/*
  Created by: Amit Kumar at 22:31 on 24 Sep 22
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
    string s;
    cin >> s;

    int q;
    cin >> q;

    vector<vector<int>> cnt(s.size() + 1, vector<int>(26, 0));

    for (int i = 0; i < s.size(); i++)
    {
        cnt[i + 1] = cnt[i];
        cnt[i + 1][s[i] - 'a']++;
    }

    int ans = 0;

    auto check = [&](int l, int mid, int r) -> bool
    {
        vector<int> temp1(26, 0);
        vector<int> temp2(26, 0);
        for (int i = 0; i < 26; i++)
        {
            temp1[i] = cnt[mid][i] - cnt[l - 1][i];
            temp2[i] = cnt[r][i] - cnt[mid][i];
        }

        bool possible = true;
        int diff = 0;
        for (int i = 0; i < 26; i++)
        {
            if (temp1[i] != temp2[i])
            {
                if (diff)
                    possible = false;
                else
                    diff = abs(temp1[i] - temp2[i]);
            }
        }
        if (diff != 1)
            possible = false;
        return possible;
    };
    while (q--)
    {
        int l, r;
        cin >> l >> r;

        if ((r - l + 1) % 2 == 0)
            continue;

        if (check(l, (l + r) / 2, r) || check(l, (l + r) / 2 - 1, r))
        {
            ++ans;
        }
        db(ans);
    }
    cout << ans << "\n";
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