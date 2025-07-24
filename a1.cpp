#include <bits/stdc++.h>
using namespace std;
using ll = long long;
//........Bit_Manipulation.............//
#define msb(musk) (63-__builtin_clzll(musk)); /// 0 -> -1
#define lsb(musk) __builtin_ctzll(musk); /// 0 -> 64
#define cntsetbit(musk) __butiltin_popcountll(musk)
#define checkbit(musk,bit) ((musk >> bit) & 1LL)
#define onbit(musk,bit) (musk|(1LL<<bit))
#define offbit(musk,bit) (musk&~(1LL<<bit))
#define flipbit(musk,bit) (musk^(1<<bit))

const int MOD = 1e9+7;
const ll INF = LLONG_MAX>>1;
const int MAXN = 2e5+1;

vector<int> spf(MAXN);
void spf_sieve(vector<int>& spf) {
    for(int i=1; i<MAXN; i++) spf[i] = i;
    for(int i=2; i<MAXN; i++) if(spf[i]==i) {
        for(int j=i*i; j<MAXN; j+=i) if(spf[j]==j) {
            spf[j] = i;
        }
    }
}

vector<int> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for(int i = 2; i*i <= n; i++) if(is_prime[i]) {
        for(int j = i*i; j <= n; j += i) is_prime[j] = false;
    }
    vector<int> primes;
    for(int i = 2; i <= n; i++) if(is_prime[i]) primes.push_back(i);
    return primes;
}

vector<pair<int,int>> factorize(ll n) {
    vector<pair<int,int>> fact;
    int p = spf[n];
    while(n > 1) {
        int cnt = 0;
        while (n % p == 0) n /= p, cnt++;
        fact.push_back({p, cnt});
        p = spf[n];
    }
    if(n > 1) fact.push_back({n, 1});
    return fact;
}

//................Range_Query...................//
ll xor1ton(ll n) {
    if(n%4 == 0) return n;
    if(n%4 == 1) return 1;
    if(n%4 == 2) return n+1;
    return 0;
}
ll xorofrange(ll l, ll r) { 
    return xor1ton(r) ^ xor1ton(l-1); 
}

ll orofrange(ll l, ll r) {
    ll res = 0;
    for(int i= 63; i >= 0; --i) {
        if(((l >> i)&1) != ((r >> i)&1)) {
            res |= ((1LL << (i+1)) - 1); break;
        }
        else if((l >> i)&1) res |= (1LL << i);
    }
    return res;
}

ll andofrange(ll l, ll r) {
    int shift = 0;
    while (l < r) {
        l >>= 1;
        r >>= 1;
        ++shift;
    }
    return l << shift;
}

//............Math............//
