class EulersTotientFunction {
public:
    vector<int> phi;
    EulersTotientFunction(int N) {
        phi.resize(N + 10);
        iota(phi.begin(), phi.end(), 0);
        for (int i = 2; i <= N; i++) {
            if (phi[i] == i) {
                for (int j = i; j <= N; j += i) {
                    phi[j] /= i;
                    phi[j] *= (i - 1);
                }
            }
        }
    }
};
