struct segment_tree {
    vector <ll> f;
    vector <ll> lazy, lazy2;
    int n;

    segment_tree(int _n = 0) {
        n = _n;
        f.assign(n*4,0);
        lazy.assign(n*4,0);
        lazy2.assign(n*4,-1);

    }

    void PushDown(int i,int l ,int r){

        if (lazy2[i] != -1) {
            lazy[i*2] = 0;
            lazy[i*2 + 1] = 0;
            lazy2[i*2] = 1;
            lazy2[i*2 + 1] = 1;
            f[i*2] = 0;
            f[i*2 + 1] = 0;
        }

        int m =(l + r) >> 1;
        lazy[i*2] += lazy[i];
        lazy[i*2 + 1] += lazy[i];

        f[i*2] += 1ll*(m - l + 1)*lazy[i];
        f[i*2 + 1] += 1ll*(r - m)*lazy[i];
        lazy[i] = 0;
        lazy2[i] = -1;
    }

    void update_x(int i,int l,int r ,int d,int c,ll x) {
        if (l > c || d > r || d > c) return ;
        if (d <= l && r <= c) {
            f[i] = 1ll*(r - l + 1)*x;
            lazy[i] = x;
            lazy2[i] = 1;
            return ;
        }

        PushDown(i,l,r);
        int m = (l + r) >> 1;

        update_x(i*2,l,m,d,c,x);
        update_x(i*2 + 1,m+1,r,d,c,x);

        f[i] = f[i*2] + f[i*2 + 1];
    }

    void update_val(int i,int l,int r ,int d,int c,ll x) {
        if (l > c || d > r || d > c) return ;
        if (d <= l && r <= c) {
            f[i] += 1ll*(r - l + 1)*x;
            lazy[i] += x;
            return ;
        }

        PushDown(i,l,r);
        int m = (l + r) >> 1;

        update_val(i*2,l,m,d,c,x);
        update_val(i*2 + 1,m+1,r,d,c,x);

        f[i] = f[i*2] + f[i*2 + 1];
    }

    ll get(int i,int l,int r ,int d,int c) {
        if (l > c || d > r || d > c) return 0;
        if (d <= l && r <= c) return f[i];

        PushDown(i,l,r);
        int m = (l + r) >> 1;

        return get(i*2,l,m,d,c) + get(i*2 + 1,m+1,r,d,c);
    }
};
