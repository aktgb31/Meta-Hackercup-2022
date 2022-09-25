/*
  Created by: Amit Kumar at 22:57 on 24 Sep 22
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

class Node
{
public:
    int value;
    Node() { value = INT_MAX; }; // Identity
    explicit Node(int v) { value = v; }
    static Node mergeSegNodes(const Node &a, const Node &b)
    {
        Node res;
        res.value = min(a.value, b.value);
        return res;
    }
    template <typename T>
    explicit operator T() { return static_cast<T>(value); }
    template <typename Ostream>
    friend typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type operator<<(Ostream &os, const Node &t)
    {
        os << t.value;
        return os;
    }
};

template <typename segNode>
class segTree
{
    int size;
    vector<segNode> Seg;
    void build(int node, int start, int end, const vector<segNode> &Base) // Recursively Builds the tree
    {
        if (start == end)
        {
            Seg[node] = Base[start];
            return;
        }
        int mid = (start + end) >> 1;
        build(node + 1, start, mid, Base);
        build(node + 2 * (mid - start + 1), mid + 1, end, Base);
        Seg[node] = segNode::mergeSegNodes(Seg[node + 1], Seg[node + 2 * (mid - start + 1)]);
    }

    segNode rQuery(int node, int start, int end, int qstart, int qend) const // Range Query
    {
        if (qend < start || qstart > end || start > end)
            return segNode();
        if (qstart <= start && end <= qend)
            return Seg[node];
        int mid = (start + end) >> 1;
        segNode l, r;
        if (qstart <= mid)
            l = rQuery(node + 1, start, mid, qstart, qend);
        if (qend >= mid + 1)
            r = rQuery(node + 2 * (mid - start + 1), mid + 1, end, qstart, qend);
        return segNode::mergeSegNodes(l, r);
    }

    void pUpdate(int node, int start, int end, int pos, segNode val, int type)
    {
        if (start == end)
        {
            Seg[node] = type ? segNode::mergeSegNodes(Seg[node], val) : val;
            return;
        }
        int mid = (start + end) >> 1;
        if (pos <= mid)
            pUpdate(node + 1, start, mid, pos, val, type);
        else
            pUpdate(node + 2 * (mid - start + 1), mid + 1, end, pos, val, type);
        Seg[node] = segNode::mergeSegNodes(Seg[node + 1], Seg[node + 2 * (mid - start + 1)]);
    }

public:
    segTree() : segTree(0){};
    explicit segTree(int n) : size(n), Seg(n << 1){};
    explicit segTree(const vector<segNode> &Base) : size(Base.size())
    {
        Seg = vector<segNode>(size << 1);
        build(1, 0, size - 1, Base);
    }
    segNode get(int pos) const
    {
        assert(pos >= 0 && pos < size);
        return rQuery(1, 0, size - 1, pos, pos);
    }
    segNode get(int left, int right) const
    {
        assert(left <= right && left >= 0 && right < size);
        return rQuery(1, 0, size - 1, left, right);
    }
    void update(int pos, segNode val) // Updates according to merge
    {
        assert(pos >= 0 && pos < size);
        pUpdate(1, 0, size - 1, pos, val, 1);
    }
    void set(int pos, segNode val) // Force sets value of node
    {
        assert(pos >= 0 && pos < size);
        pUpdate(1, 0, size - 1, pos, val, 0);
    }
    template <typename Ostream, typename T>
    friend typename enable_if<is_same<Ostream, ostream>::value, Ostream &>::type operator<<(Ostream &os, const segTree<T> &t)
    {
        for (int i = 0; i < t.size; i++)
            os << t.get(i) << " ";
        return os;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    cin >> arr;
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
#ifdef LOCAL
        cerr << "Case #" << I << ": ";
#endif
        solve();
    }
#ifdef LOCAL
    auto done = std::chrono::high_resolution_clock::now();
    cerr << "Time = " << std::chrono::duration_cast<std::chrono::milliseconds>(done - started).count() << " ms\n";
#endif
    return 0;
}