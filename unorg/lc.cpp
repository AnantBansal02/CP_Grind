#define ll long long
class Solution
{
public:
    vector<int> countVisitedNodes(vector<int> &edges)
    {
        ll N = edges.size();
        vector<vector<ll>> adj(N);
        for (ll i = 0; i < N; i++)
        {
            adj[i].push_back(edges[i]);
        }
        vector<vector<ll>> cycles;
        vector<ll> vis(N), color(N), par(N);
        function<void(ll, ll)> dfs = [&](ll u, ll p)
        {
            vis[u]++;
            if (color[u] == 2)
            {
                return;
            }
            if (color[u] == 1)
            {

                int cur = p;
                vector<ll> v;

                v.push_back(cur);
                while (cur != u)
                {
                    cur = par[cur];

                    v.push_back(cur);
                }
                cycles.push_back(v);
                return;
            }
            par[u] = p;
            color[u] = 1;
            for (int v : adj[u])
            {
                dfs(v, u);
            }
            color[u] = 2;
        };
        for (ll i = 0; i < N; i++)
            if (!color[i])
            {
                dfs(i, i);
            }

        set<ll> incyc;
        vector<int> ans(N);
        for (auto cycle : cycles)
        {
            ll sz = cycle.size();
            for (auto x : cycle)
            {
                ans[x] = sz;
                incyc.insert(x);
            }
        }

        fill(vis.begin(), vis.end(), 0);
        function<void(ll)> dfs1 = [&](ll u)
        {
            vis[u]++;
            for (auto v : adj[u])
            {
                if (incyc.find(v) != incyc.end())
                {
                    ans[u] += ans[v];
                }
                else if (!vis[v])
                {
                    dfs1(v);
                    ans[u] += ans[v];
                }
                else if (par[u] ^ v)
                {
                    ans[u] += ans[v];
                }
            }
            ans[u]++;
        };
        for (ll i = 0; i < N; i++)
            if (!vis[i] && (incyc.find(i) == incyc.end()))
            {
                dfs1(i);
            }
        return ans ;
    }
};