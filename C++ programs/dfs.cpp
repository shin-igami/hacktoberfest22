#include <bits/stdc++.h>

using namespace std;
using ll = long long;
ll visited[1000000];
vector<ll> edge[1000001];

void dfs(ll node)
{
    visited[node] = 1;

    cout << node << " ";

    for (ll child : edge[node])
    {
        if (visited[child] == 0)
        {
            dfs(child);
        }
    }
}

int main()
{
    std::ios::sync_with_stdio(false), cin.tie(__null), cout.tie(__null);

    freopen("input.txt", "r",
            stdin);
    freopen("output.txt", "w",
            stdout);

    ll n, e;

    cin >> n >> e;

    while (e--)
    {
        ll a, b;
        cin >> a >> b;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    for (long long i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            dfs(i);
        }
    }
}
