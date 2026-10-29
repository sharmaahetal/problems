class Solution {
    int LOG;
    int n;

    vector<vector<int>> adj;
    vector<vector<int>> up;

    vector<int> tin, tout, depth;
    vector<int> initialMask;
    vector<int> bit;

    int timer = 0;

    // Fenwick Tree: point update and prefix XOR query
    void updateBIT(int idx, int val) {
        while (idx <= n) {
            bit[idx] ^= val;
            idx += idx & -idx;
        }
    }

    int queryBIT(int idx) {
        int result = 0;

        while (idx > 0) {
            result ^= bit[idx];
            idx -= idx & -idx;
        }

        return result;
    }

    // DFS: Euler Tour, depth, ancestors, and initial prefix masks
    void dfs(int u, int parent, int mask, string& s) {
        tin[u] = ++timer;

        mask ^= (1 << (s[u] - 'a'));
        initialMask[u] = mask;

        up[u][0] = parent;

        for (int j = 1; j < LOG; j++) {
            up[u][j] = up[up[u][j - 1]][j - 1];
        }

        for (int v : adj[u]) {
            if (v == parent) continue;

            depth[v] = depth[u] + 1;
            dfs(v, u, mask, s);
        }

        tout[u] = timer;
    }

    // Find Lowest Common Ancestor
    int lca(int u, int v) {
        if (depth[u] < depth[v]) {
            swap(u, v);
        }

        int diff = depth[u] - depth[v];

        for (int j = LOG - 1; j >= 0; j--) {
            if (diff & (1 << j)) {
                u = up[u][j];
            }
        }

        if (u == v) return u;

        for (int j = LOG - 1; j >= 0; j--) {
            if (up[u][j] != up[v][j]) {
                u = up[u][j];
                v = up[v][j];
            }
        }

        return up[u][0];
    }

public:
    vector<bool> palindromePath(int n,
                                vector<vector<int>>& edges,
                                string s,
                                vector<string>& queries) {
        this->n = n;

        LOG = 1;
        while ((1 << LOG) <= n) {
            LOG++;
        }

        adj.assign(n, {});
        up.assign(n, vector<int>(LOG, 0));

        tin.assign(n, 0);
        tout.assign(n, 0);
        depth.assign(n, 0);
        initialMask.assign(n, 0);

        // Fenwick Tree uses 1-based indexing
        bit.assign(n + 2, 0);

        for (auto& e : edges) {
            int u = e[0];
            int v = e[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // Root the tree at node 0
        dfs(0, 0, 0, s);

        vector<bool> answer;

        for (string& q : queries) {
            string type;
            int u;

            stringstream ss(q);
            ss >> type >> u;

            if (type == "update") {
                char c;
                ss >> c;

                // Current character at node u
                char oldChar = s[u];

                int oldBit = 1 << (oldChar - 'a');
                int newBit = 1 << (c - 'a');

                // Difference between old and new characters
                int change = oldBit ^ newBit;

                // Update every prefix mask in u's subtree
                updateBIT(tin[u], change);
                updateBIT(tout[u] + 1, change);

                s[u] = c;
            }
            else {
                int v;
                ss >> v;

                int maskU = initialMask[u] ^ queryBIT(tin[u]);
                int maskV = initialMask[v] ^ queryBIT(tin[v]);

                int ancestor = lca(u, v);

                int ancestorMask =
                    initialMask[ancestor] ^
                    queryBIT(tin[ancestor]);

                int pathMask =
                    maskU ^ maskV ^
                    (1 << (s[ancestor] - 'a'));

                // A palindrome can have at most one odd-frequency character
                bool possible =
                    (pathMask == 0) ||
                    ((pathMask & (pathMask - 1)) == 0);

                answer.push_back(possible);
            }
        }

        return answer;
    }
};