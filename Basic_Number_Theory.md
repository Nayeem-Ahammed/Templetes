
# Topics:
#### 1. GCD, LCM
#### 2. Divisibility Rules -> [2, 3, 4, 5, 9, 11]
#### 3. Sieve of Eratosthenes -> O(N log log N)
```
const int N = 1e6;
bool isPrime[N+1];

void sieve() {
    fill(isPrime, isPrime + N + 1, true);
    isPrime[0] = isPrime[1] = false;

    for (int i = 2; i * i <= N; ++i) {
        if (isPrime[i]) {
            for (int j = i * i; j <= N; j += i)
                isPrime[j] = false;
        }
    }
}

```

---

#### 4. Prime Factorization (Trail division) ->  O(√n)
```
vector<int> trial_division(int n) {
    vector<int> factors;
    for (int i = 2; i*i <= n; ++i) {
        while (n % i == 0) {
            factors.push_back(i);
            n /= i;
        }
    }
    if (n > 1) factors.push_back(n);
    return factors;
}

```

---

#### 5. Prime Factorization using Sieve(O(log N) per query)
- Smallest Prime Factor (SPF) <- (pre-compute)
```
const int N = 1e6;
int spf[N+1];

void sieve_spf() {
    for (int i = 0; i <= N; ++i) spf[i] = i;
    for (int i = 2; i*i <= N; ++i)
        if (spf[i] == i)
            for (int j = i*i; j <= N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
}

```

```
vector<int> factorize(int n) {
    vector<int> res;
    while (n > 1) {
        res.push_back(spf[n]);
        n /= spf[n];
    }
    return res;
}

```
---

#### 6. Modular Arithmetic
- +, -, * , /
- modular exponentiation -> find $a^b$ % m  -> O(log b)
		- [click here](https://cp-algorithms.com/algebra/binary-exp.html)
*  inverse mod (Fermat's Little Theorem)
- Negative modulo handle

```
const int MOD = 1e9 + 7;

int add(int a, int b) { return (a + b) % MOD; }
int sub(int a, int b) { return (a - b + MOD) % MOD; }
int mul(int a, int b) { return (1LL * a * b) % MOD; }
```

```
int modinv(int a, int mod) {
    return modpow(a, mod - 2, mod);
}
```
---

#### 7. Number of Divisors(using prime factors) {2 way}
If $n = p1^e1 * p2^e2 * ... * pk^ek$, then:
Number of divisors = $(e1+1)(e2+1)...(ek+1)$
```
int num_of_divisors(int n) {
    int res = 1;
    for (int i = 2; i*i <= n; ++i) {
        int count = 0;
        while (n % i == 0) {
            n /= i;
            count++;
        }
        res *= (count + 1);
    }
    if (n > 1) res *= 2;
    return res;
}
```
---

#### 8. Sum of Divisors
If $n = p1^e1 * p2^e2 * ... * pk^ek$, then:
$Sum = (p1^0 + p1^1 + ... + p1^e1) × ...$
```
int sum_of_divisors(int n) {
    int sum = 1;
    for (int i = 2; i*i <= n; ++i) {
        int curr_sum = 1, p = 1;
        while (n % i == 0) {
            n /= i;
            p *= i;
            curr_sum += p;
        }
        sum *= curr_sum;
    }
    if (n > 1) sum *= (1 + n);
    return sum;
}
```
---

#### 9. All divisors in O(sqrt(n))
```
vector<int> get_divisors(int n) {
    vector<int> divs;
    for (int i = 1; i*i <= n; ++i) {
        if (n % i == 0) {
            divs.push_back(i);
            if (i != n / i)
                divs.push_back(n / i);
        }
    }
    sort(divs.begin(), divs.end());
    return divs;
}
```
---

#### 10. Pre-computation Techniques
	- factorials modulo M
	- Inverse factorials
	- sieve based

(a) Factorials mod M
```
const int N = 1e6, MOD = 1e9+7;
int fact[N+1];

void compute_fact() {
    fact[0] = 1;
    for (int i = 1; i <= N; ++i)
        fact[i] = 1LL * fact[i-1] * i % MOD;
}
```

(b) Inverse Factorials
```
int inv_fact[N+1];

void compute_inv_fact() {
    inv_fact[N] = modinv(fact[N], MOD);
    for (int i = N - 1; i >= 0; --i)
        inv_fact[i] = 1LL * inv_fact[i + 1] * (i + 1) % MOD;
}
```

(c) nCr modulo M
```
int nCr(int n, int r) {
    if (r < 0 || r > n) return 0;
    return 1LL * fact[n] * inv_fact[r] % MOD * inv_fact[n - r] % MOD;
}
```



---

*@nayeem_ahammed*
