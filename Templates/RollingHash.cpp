class RollingHash {
    public:
    int power(int a, int b, int mod) {int res = 1; while (b > 0) {if (b & 1)res = (res * a) % mod; a = (a * a) % mod; b = b >> 1;} return res;}
    vector<int> dp, dp2, inv, inv2;
    int MOD = 1e9 + 7, MOD2 = 1e9 + 9;
    RollingHash(string& s) {
        mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
        auto dist=uniform_int_distribution<int>(1000,5000);
        int n = s.size();
        int p = dist(rng), p2 = dist(rng), cnt = 1, cntt = 1;
        dp.resize(n + 1), inv.resize(n + 1), dp2.resize(n + 1), inv2.resize(n + 1);
        dp[0] = dp2[0] = s[0] - 'a' + 1;
        inv[0] = inv2[0] = 1;
        for (int i = 1; i < n; i++) {
            cnt = (cnt * p) % MOD, cntt = (cntt * p2) % MOD2;
            dp[i] = (dp[i - 1] + (s[i] - 'a' + 1) * cnt) % MOD;
            dp2[i] = (dp2[i - 1] + (s[i] - 'a' + 1) * cntt) % MOD2;
            inv[i] = power(cnt, MOD - 2, MOD);
            inv2[i] = power(cntt, MOD2 - 2, MOD2);
        }
    }
    int get(int l, int r) {
        int x = (dp[r] - (l ? dp[l - 1] : 0) + MOD) % MOD;
        x = (x * inv[l]) % MOD;
        int y = (dp2[r] - (l ? dp2[l - 1] : 0) + MOD2) % MOD2;
        y = (y * inv2[l]) % MOD2;
 
        return 3 * x + y;
    }
};
