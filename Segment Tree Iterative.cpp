#include<bits/stdc++.h>
using namespace std;

struct SegmentTree {
    int64_t n, IDENTITY;
    vector<int64_t> t;
    int64_t Fun(int64_t L, int64_t R) {
        return L+R; // sum
        // return min(L,R); // min
        // return max(L,R); // max
        // return L^R; // Xor
    }
    // Constrictor = Build
    SegmentTree(const vector<int> &a) {
        n = a.size();
        t.assign(2*n, 0);
        IDENTITY = 0; // Sum or Xor // LLONG_MAX for min // LLONG_MIN for max
        for(int i = 0; i < n; i++) t[n+i] = a[i];
        for(int i = n-1; i > 0; --i) t[i] = Fun(t[i<<1], t[i<<1 | 1]);
    }
    // a point update
    void update(int p, int64_t val) {
    	for(t[p += n] = val; p > 1; p >>= 1) t[p >> 1] = Fun(t[p], t[p^1]);
    }
    // query -> [l, r]
    int64_t query(int l, int r) { // 0 based inclusive
        int64_t L = IDENTITY, R = IDENTITY;
        for(l += n, r += n; l <= r; l >>= 1, r >>= 1) {
            if(l&1) L = Fun(L, t[l++]);
            if(!(r&1)) R = Fun(t[r--], R);
        }
        return Fun(L,R);
    }
};
int main() {
    vector<int> a = {1, 2, 3, 4, 5};
    SegmentTree st(a);
    cout << st.query(2, 3) << endl;
}
