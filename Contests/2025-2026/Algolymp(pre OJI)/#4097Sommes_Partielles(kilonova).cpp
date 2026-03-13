#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;

const int mod = 1e9 + 7;
const int MAX = 2e6 + 10;
long long fact[MAX], inv_fact[MAX];

long long modpow(long long base, long long exp, long long mod) {
    long long res = 1;
    while (exp > 0) {
        if (exp & 1) res = (res * base) % mod;
        base = (base * base) % mod;
        exp >>= 1;
    }
    return res;
}
void precompute() {
    fact[0] = 1;
    for (int i = 1; i < MAX; i++) {
        fact[i] = (fact[i-1] * i) % mod;
    }
    inv_fact[MAX-1] = modpow(fact[MAX-1], mod-2, mod);
    for (int i = MAX-2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % mod;
    }
}
long long nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return fact[n] * inv_fact[r] % mod * inv_fact[n-r] % mod;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    precompute();
    int n;
    long long t;
    cin >> n >> t;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long total = 0;
    for (int j = 0; j < n; j++) {
        long long coef = nCr(t + n - 1 - j, t);
        total = (total + a[j] * coef % mod + mod) % mod;
    }
    cout << total <<"\n";
    return 0;
}   
