/*
  Created by: Amit Kumar at 23:29 on 24 Sep 22
*/
#include <bits/stdc++.h>
#ifdef LOCAL
#include "debug.h"
#else
#define db(...)
#endif
using namespace std;

#define all(x) x.begin(), x.end()

#define int long long
const int MAXN = 1e18 + 1;

struct FenwickTree
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTree(int n)
    {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(const vector<int> &a) : FenwickTree(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r)
    {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r)
    {
        if (l == 0)
            return sum(r);
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int solve(int diff, int tillZ1, int tillZ2, int tillZ3, int afterZ1, int afterZ2, int afterZ3)
{
    if (diff == 0)
        return 0;

    if (diff < 0)
    {
        swap(tillZ1, afterZ1);
        swap(tillZ2, afterZ2);
        swap(tillZ3, afterZ3);
        diff = -diff;
    }

    int ans = MAXN;

    if (diff >= 2)
    {
        // swaps 1s with 2s
        int x = min(tillZ1, afterZ2);
        int _diff = max(0ll, diff - x * 2);
        int used = (diff - _diff) / 2;
        if (x)
            ans = min(ans, solve(_diff, tillZ1 - used, tillZ2 + used, tillZ3, afterZ1 + used, afterZ2 - used, afterZ3) + used);

        // swaps 2s with 3s
        x = min(tillZ2, afterZ3);
        _diff = max(0ll, diff - x * 2);
        used = (diff - _diff) / 2;
        if (x)
            ans = min(ans, solve(_diff, tillZ1, tillZ2 - used, tillZ3 + used, afterZ1, afterZ2 + used, afterZ3 - used) + used);
    }

    if (diff >= 4)
    {
        // swaps 1s with 3s
        int x = min(tillZ1, afterZ3);
        int _diff = max(0ll, diff - x * 4);
        int used = (diff - _diff) / 4;
        if (x)
            ans = min(ans, solve(_diff, tillZ1 - used, tillZ2, tillZ3 + used, afterZ1 + used, afterZ2, afterZ3 - used) + used);
    }

    db(diff, ans, tillZ1, tillZ2, tillZ3, afterZ1, afterZ2, afterZ3);
    return ans >= MAXN ? MAXN : ans;
}

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> arr(n + 1);
    FenwickTree ft[] = {FenwickTree(n + 1), FenwickTree(n + 1), FenwickTree(n + 1), FenwickTree(n + 1)};

    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        ft[x].add(i, 1);
        arr[i] = x;
        ft[0].add(i, x);
    }

    int fans = 0;
    while (m--)
    {
        int x, y, z;
        cin >> x >> y >> z;

        ft[0].add(x, -arr[x]);
        ft[arr[x]].add(x, -1);
        arr[x] = y;
        ft[0].add(x, arr[x]);
        ft[arr[x]].add(x, 1);

        int tillZ1 = ft[1].sum(1, z);
        int tillZ2 = ft[2].sum(1, z);
        int tillZ3 = ft[3].sum(1, z);

        int afterZ1 = ft[1].sum(z + 1, n);
        int afterZ2 = ft[2].sum(z + 1, n);
        int afterZ3 = ft[3].sum(z + 1, n);

        int sumTillZ = ft[0].sum(1, z);
        int sumAfterZ = ft[0].sum(z + 1, n);

        assert(tillZ1 + tillZ2 * 2 + tillZ3 * 3 == sumTillZ);
        assert(afterZ1 + afterZ2 * 2 + afterZ3 * 3 == sumAfterZ);
        db(arr);

        // Ans stores minimum number of swaps required to make sumTillZ=sumAfterZ
        int ans = 0;

        if (abs(sumAfterZ - sumTillZ) % 2)
        {
            ans = -1;
        }
        else
        {
            ans = solve(sumAfterZ - sumTillZ, tillZ1, tillZ2, tillZ3, afterZ1, afterZ2, afterZ3);
            db(sumAfterZ, sumTillZ, tillZ1, tillZ2, tillZ3, afterZ1, afterZ2, afterZ3);
            db(x, y, z, ans);
            ans = ans >= MAXN ? -1 : ans;
        }
        fans += ans;
    }
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