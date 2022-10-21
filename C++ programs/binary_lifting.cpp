#include <bits/stdc++.h>
using namespace std;
 
 vector<vector<int>> edges;
 vector<int> val;
 int ans;
const int inf = 0x3f3f3f3f;
void dfs(int u, int par, int sum, int tar) {
    if (tar == u) {
        ans = max(0, max(0, sum) + val[u]);
        return;
    }
    
    for (auto v : edges[u]) {
        if (v != par) 
           dfs(v, u, max(sum, 0) + val[u], tar);
    }

}
signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;

    edges.resize(n + 1);
    val.resize(n + 1);

    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;

        edges[x].push_back(y);
        edges[y].push_back(x);
    }

    for (int i = 1; i <= n; i++) {
        cin >> val[i];
    }
    int q;
    cin >> q;
    while (q--) {
        int a, b;
        cin >> a >> b;
dfs(a, -1, 0, b);
        cout << ans<< endl;
    }
}
