struct Segment_tree{
    vector <ll> f ;
    vector <vector <ll> >  lazy , pre;
    int n;

    Segment_tree(int _n = 0){
        n = _n;
        f.assign(n*4,0);
        lazy.assign(4,vector <ll>(n*4,0));
        pre.assign(4,vector <ll>(n + 10,0));

        for (int i = 1 ; i <= n ; i++){
            ll g = 1;
            for (int j = 0 ; j < 4 ; j++){
                pre[j][i] = (pre[j][i - 1] + g) % mod;
                g = g * i % mod;
            }
        }     
    }

    inline ll prepare(int id,int l , int r){
        return (pre[id][r] - pre[id][l - 1] + mod) % mod;
    }

    void add(ll &x , ll y){
        x += y;
        x %= mod;
        x += mod;
        if (x >= mod) x -= mod;
    }

    void Push_down(int i, int l , int r){
        int m = (l + r) >> 1;
        for (int j = 0 ; j < 3 ; j++){
            add(lazy[j][i*2],lazy[j][i]);
            add(lazy[j][i*2 + 1],lazy[j][i]);
            add(f[i*2],lazy[j][i]*prepare(j,l,m));
            add(f[i*2 + 1],lazy[j][i]*prepare(j,m + 1,r));
            lazy[j][i] = 0;
        }
    }

    void update(int i, int l, int r, int d, int c, ll a[]){
        if (d > r || l > c || d > c || l > r) return ;
        if (d <= l && r <= c){
            for (int j = 0 ; j < 4 ; j++){
                add(lazy[j][i],a[j]);
                add(f[i],a[j]*prepare(j,l,r));
            }
            return ;
        }
        Push_down(i,l,r);
        int m = (l + r) >> 1;
        update(i*2,l,m,d,c,a);
        update(i*2 + 1,m + 1,r,d,c,a);
        f[i] = (f[i*2] + f[i*2 + 1] + mod) % mod;
    }

    ll get(int i, int l, int r, int d, int c){
        if (d > r || l > c || d > c || l > r) return 0;
        if (d <= l && r <= c) return f[i];
        Push_down(i,l,r);
        int m = (l + r) >> 1;
        return (get(i*2,l,m,d,c) + get(i*2 + 1,m + 1,r,d,c)) % mod;
    }
} ;


Segment_tree IT;