#include <bits/stdc++.h>

#define mod 998244353

long long power(long long a, long long b) {
  long long x = 1, y = a;
  while (b > 0) {
    if (b & 1ll) {
      x = (x * y) % mod;
    }
    y = (y * y) % mod;
    b >>= 1;
  }
  return x % mod;
}

long long modular_inverse(long long n) { return power(n, mod - 2); }

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  long long n;
  cin >> n;

  long long invn = modular_inverse(n);

  vector<long long> hand = {0, 1};
  vector<long long> fee = {0, 0};

  for (long long q = 1; q < n; q++) {
    long long prob = (q * invn) % mod;
    long long fce = modular_inverse(mod + 1 - ((prob * prob) % mod));
    long long hce = ((mod + 1 - prob) * fce) % mod;

    vector<long long> chand = {(prob * hce) % mod, hce};
    vector<long long> cfee = {
        (prob * fce) % mod,
        (((prob * prob) % mod) * fce) % mod,
    };

    vector<long long> nhand = {0, 0};

    for (long long i = 0; i < 2; i++) {
      for (long long j = 0; j < 2; j++) {
        nhand[(i + j) % 2] += hand[i] * chand[j];
        nhand[(i + j) % 2] %= mod;

        fee[(i + j) % 2] += hand[i] * cfee[j];
        fee[(i + j) % 2] %= mod;
      }
    }

    hand = nhand;
  }
  cout << fee[0] % mod << " " << fee[1] % mod << "\n";
  return 0;
}