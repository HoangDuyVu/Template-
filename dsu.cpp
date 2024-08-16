struct dsu {
    vector <int> rank, par;
    int n;
    dsu(int _n = 0){
        n = _n;
        rank.assign(n + 1,0);
        par.assign(n + 1,-1);
    }

    int find_set(int u) {
        if (par[u] != -1) return par[u] = find_set(par[u]);
        return u;
    }

    bool Join_set(int u,int v) {
        u = find_set(u);
        v = find_set(v);

        if (u == v) return false;

        if (rank[u] == rank[v]) rank[u]++;
        if (rank[u] < rank[v]) swap(u,v);
        par[v] = u;
        return true;
    }
};

