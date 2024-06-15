struct Hash{
    ll base;
    ll mod;
    vector <ll> mul ,hs;
    void built(ll _base, ll _mod, int n,string s){
        base = _base;
        mod = _mod;
        mul.resize(n + 1);
        hs.reserve(n + 1);
        mul[0] = 1;
        for (int i = 1 ; i <= n ; i++) mul[i] = mul[i - 1]*base % mod;

        for (int i = 1 ; i <= n ; i++) hs[i] = (hs[i - 1]*base + s[i]) % mod;
    }

    ll get(int l, int r){
        return ((hs[r] - hs[l - 1]*mul[r - l + 1]) % mod + mod) % mod;
    }
};