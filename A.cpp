#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

const int MAXN = 200005;

// is_sq[i] is true if i is a perfect square
bool is_sq[MAXN];

// adj2_plus[d] stores square offsets s1 such that d = s1 + s2 or d = s1 - s2
vector<int> adj2_plus[MAXN];
// adj2_minus[d] stores square offsets s1 such that d = s2 - s1
vector<int> adj2_minus[MAXN];

// Global precomputation (Runs once)
void precompute() {
    for (int i = 1; i * i < MAXN; i++) {
        is_sq[i * i] = true;
    }
    
    // Iterate over all valid squares <= MAXN
    for (int x = 1; x * x < MAXN; x++) {
        int s1 = x * x;
        for (int y = 1; y * y < MAXN; y++) {
            int s2 = y * y;
            
            // Case 1: d = s1 + s2
            int d1 = s1 + s2;
            if (d1 < MAXN) {
                adj2_plus[d1].push_back(s1);
            }
            
            // Case 2: d = s1 - s2 (s1 > s2)
            int d2 = s1 - s2;
            if (d2 > 0 && d2 < MAXN) {
                adj2_plus[d2].push_back(s1);
            }
            
            // Case 3: d = s2 - s1 (s2 > s1)
            int d3 = s2 - s1;
            if (d3 > 0 && d3 < MAXN) {
                adj2_minus[d3].push_back(s1);
            }
        }
    }
}

// O(1) average time check if the distance is exactly 2
bool check2(int U, int V, int n) {
    if (U > V) swap(U, V);
    int d = V - U;
    
    // Check if intermediate node X = U + s1 is valid
    for (int s1 : adj2_plus[d]) {
        if (U + s1 <= n) return true;
    }
    
    // Check if intermediate node X = U - s1 is valid
    for (int s1 : adj2_minus[d]) {
        if (U - s1 >= 1) return true;
    }
    
    return false;
}

// O(sqrt(N)) check if the distance is exactly 3
bool check3(int U, int V, int n) {
    // Iterate through all 1-step neighbors of U
    for (int x = 1; x * x <= n; x++) {
        int sq = x * x;
        
        int nxt1 = U + sq;
        if (nxt1 <= n) {
            if (check2(nxt1, V, n)) return true;
        }
        
        int nxt2 = U - sq;
        if (nxt2 >= 1) {
            if (check2(nxt2, V, n)) return true;
        }
    }
    return false;
}

void solve() {
    int n, q;
    cin >> n >> q;
    
    for (int i = 0; i < q; i++) {
        int u, v;
        cin >> u >> v;
        
        int d = abs(u - v);
        
        if (is_sq[d]) {
            cout << 1 << "\n";
        } 
        else if (check2(u, v, n)) {
            cout << 2 << "\n";
        } 
        else if (check3(u, v, n)) {
            cout << 3 << "\n";
        } 
        else {
            cout << 4 << "\n";
        }
    }
}

int32_t main() {
    // Optimize standard I/O operations for speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    precompute();
    
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    
    return 0;
}