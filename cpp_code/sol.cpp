#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

using ll = int64_t;
struct result {ll ans; ll worst_path;};

result dfs(ll x, const vector<vector<ll>>& g, const vector<ll>& F) {
    if (g[x].size() == 0) {
        return result{F[x],F[x]};
    } else {
        ll ans = 0;
        ll worst_path = 1e9;

        for (ll c : g[x]) {
            auto [total, path] = dfs(c, g, F);
            ans += total;
            worst_path = min(worst_path, path);
        }
        if (worst_path < F[x]) {
            ans += F[x] - worst_path;
            worst_path = F[x];
        }
        return result{ans, worst_path};
    }
}

int main() {
    ll T;
    scanf("%lld", &T);
    for (ll tcase=1; tcase<= T; tcase++) {
        ll n;
        // cin >> n;
        scanf("%lld", &n);

        vector<ll> F(n+1,0);
        for (ll i=0; i<n; i++) {
            scanf("%lld", &F[i+1]);
            //cin >> F[i+1];
        }

        vector<ll> P(n+1,-1);
        for (ll i=0; i<n; i++) {
            scanf("%lld", &P[i+1]);
            // cin >> P[i+1];
        }

        vector<vector<ll>> graph(n+1,vector<ll>{});
        for (ll i=1; i<=n; i++) {
            graph[P[i]].push_back(i);
        }
        
        auto [ans,root_path] = dfs(0,graph,F);
        printf("Case #%lld: %lld\n",tcase,ans);
        // cout << "Case #" << tcase << ": " << ans << endl;
    }

    return 0;
}