/*
  Created by: Amit Kumar at 17:07 on 11 Sep 22
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

template <typename Istream, typename T>
inline typename enable_if<is_same<Istream, istream>::value, Istream &>::type operator>>(Istream &is, vector<T> &A)
{
    for (int i = 0; i < A.size(); i++)
        is >> A[i];
    return is;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> A(n), B(n);
    cin >> A >> B;

    if (A == B)
    {
        if (k == 1)
            cout << "NO\n";
        else if (n == 2 && (k & 1))
            cout << "NO\n";
        else
            cout << "YES\n";
        return;
    }

    if (k != 0)
    {
        rotate(A.begin(), find(all(A), B[0]), A.end());
    }
    db(A, B);
    if (A == B)
    {
        if (n == 2 && (k % 2 == 0))
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    else
        cout << "NO\n";
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