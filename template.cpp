#include <iostream>
#include <bits/stdc++.h>
#include <map>
#include <set>
#include <iomanip>
using namespace std;

#define int long long
/*
// ======================================================================================
// 1. Sieve & Prime Factorization
// ======================================================================================
const int MAX_SIEVE = 1e5 + 5;
vector<int> spf(MAX_SIEVE);

void sieve() {
    for(int i = 0; i < MAX_SIEVE; i++) spf[i] = i;
    for(int i = 2; i * i < MAX_SIEVE; i++) {
        if(spf[i] == i) {
            for(int j = i * i; j < MAX_SIEVE; j += i) {
                if(spf[j] == j) spf[j] = i;
            }
        }
    }
}

vector<int> primeFactorisation(int n) {
    vector<int> primes;
    while(n != 1) {
        int x = spf[n];
        while(n % x == 0) n /= x;
        primes.push_back(x);
    }
    return primes;
}

// ======================================================================================
// 2. Combinatorics (Modular Exponentiation, Factorials, nCr)
// ======================================================================================
const int MOD = 1e9 + 7; // Change to 998244353 if needed
const int MAX_COMB = 1e6 + 5;
vector<int> fact(MAX_COMB), inv_fact(MAX_COMB);

int power(int a, int b, int m = MOD) {
    int res = 1;
    a %= m;
    while (b > 0) {
        if (b & 1) res = (res * a) % m;
        a = (a * a) % m;
        b >>= 1;
    }
    return res;
}

void precompute_factorials() {
    fact[0] = 1;
    for (int i = 1; i < MAX_COMB; i++) {
        fact[i] = (fact[i - 1] * i) % MOD;
    }
    inv_fact[MAX_COMB - 1] = power(fact[MAX_COMB - 1], MOD - 2);
    for (int i = MAX_COMB - 2; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i + 1] * (i + 1)) % MOD;
    }
}

int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return (((fact[n] * inv_fact[r]) % MOD) * inv_fact[n - r]) % MOD;
}
*/

void solve(){
}

int32_t main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // sieve();
    // precompute_factorials();
    int t;
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}