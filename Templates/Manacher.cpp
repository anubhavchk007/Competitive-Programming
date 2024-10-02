class Manacher {
    public:
    vector<int> p;
    string s;
    Manacher (string& original) {
        for (auto &x : original) s += '#', s += x;
        s += "#";
        int n = s.size();
        p.assign(n, 1);
        int l = 1, r = 1;
        for (int i = 1; i < n; i++) {
            p[i] = max(1LL, min(r - i, (l + r - i < 0 or l + r - i >= n ? (int) 1e9 : p[l + r - i])));
            while (i - p[i] >= 0 and i + p[i] < n and s[i + p[i]] == s[i - p[i]]) {
                p[i]++;
            }
            if (i + p[i] > r) {
                l = i - p[i], r = i + p[i];
            }
        }
    }

    int getLongest (int pos, bool odd) {    // finds longest palindrome centered around pos (0-based)
        pos = 2 * pos + 1 + not odd;        // for odd length, center is pos
        return p[pos] - 1;                  // for even length, center is between pos and pos + 1
    }

    bool checkPalindrome (int l, int r) {   // checks if substring [l, r] (0-based, both inclusive) is a palindrome
        return r - l + 1 <= getLongest((l + r) >> 1, l % 2 == r % 2);
    }
};
