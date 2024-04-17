#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#include <bits/stdc++.h>
#define debug(...) 42
#define rep1(a) for (auto i = 0; i < a; i++)
#define rep2(i, a) for (auto i = 0; i < a; i++)
#define rep3(i, a, b) for (auto i = a; i < b; i++)
#define rep4(i, a, b, c) for (auto i = a; i < b; i += c)
#define overload4(a, b, c, d, e, ...) e
#define rep(...) overload4(__VA_ARGS__, rep4, rep3, rep2, rep1)(__VA_ARGS__)

#define pb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  x = x < y ? x : y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  x = x > y ? x : y;
}
template <typename T> using vc = vector<T>;
using ll = long long;
using vi = vector<int>;
using vl = vector<ll>;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
mt19937 rng(time(NULL));
const int INF = 1000000000;
const ll LNF = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second
#endif

const int P = 998244353;
void solve() {
  ll N, M;
  cin >> N >> M;
  vl A(N);
  for (auto &a : A) {
    cin >> a;
  }

  auto prime = [&](ll X) {
    vl p;
    for (int i = 2; 1ll * i * i <= X; i++) {
      if (X % i == 0) {
        p.pb(i);
        while (X % i == 0) {
          X /= i;
        }
      }
    }
    if (X > 1) {
      p.pb(X);
    }
    return p;
  };

  auto p = prime(M);

  vi pw(N + 1);
  pw[0] = 1;
  rep(i, N) { pw[i + 1] = pw[i] * 2 % P; }

  int w = sz(p);
  vi c(1 << w);
  rep(i, N) {
    if (M % A[i] == 0) {
      int k = 0;
      for (int j = 0; j < (int)p.size(); j++) {
        ll pi = p[j];
        if (M / pi % A[i] == 0) {
          k |= 1 << j;
        }
      }
      c[k]++;
    }
  }

  rep(w) {
    rep(j, 1 << w) {
      if (j >> i & 1) {
        c[j ^ (1 << i)] += c[j];
      }
    }
  }

  int ans = 0;
  rep(1 << w) {
    if (__builtin_parity(i) == 0) {
      ans += pw[c[i]];
    } else {
      ans += P - pw[c[i]];
    }
    if (ans >= P) {
      ans -= P;
    }
  }
  if (w == 0) {
    ans += P - 1;
  }
  if (ans >= P) {
    ans -= P;
  }
  cout << ans << "\n";
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  while (t--) {
    solve();
  }
  return 0;
}