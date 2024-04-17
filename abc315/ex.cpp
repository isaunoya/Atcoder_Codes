#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...)
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep1(a) for (int i = 0; i < a; i++)
#define rep2(i, a) for (int i = 0; i < a; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
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
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

template <class... T> void read() {}
template <class T> void read(T &x) { cin >> x; }
template <class T> void read(vector<T> &v) {
  for (T &x : v)
    cin >> x;
}
template <class T, class S> void read(pair<T, S> &v) {
  cin >> v.first >> v.second;
}
template <class T, class... Ts> void read(T &a, Ts &...b) {
  read(a), read(b...);
}

namespace Poly {
const int P = 998244353;
const int G = 3;
int power(int x, int y) {
  int res = 1;
  for (; y; y >>= 1, x = 1ll * x * x % P)
    if (y & 1)
      res = 1ll * res * x % P;
  return res;
}
int inc(int x, int y) { return ((x += y) >= P) ? x - P : x; }
int dec(int x, int y) { return ((x -= y) < 0) ? x + P : x; }
vector<int> rev, rt;
int lim = 1;
void init(const int &len) {
  int l = 0;
  lim = 1;
  while (lim <= len) {
    lim <<= 1, l++;
  }
  rev.resize(lim), rt.resize(lim);
  for (int i = 0; i < lim; i++)
    rev[i] = rev[i >> 1] >> 1 | (i & 1) << l - 1;
  for (int len = 1; len < lim; len <<= 1) {
    int w = power(G, (P ^ 1) / (len << 1));
    rt[len] = 1;
    for (int i = 1; i < len; i++) {
      rt[i + len] = 1ll * rt[i + len - 1] * w % P;
    }
  }
}
void ntt(vector<int> &f) {
  f.resize(lim);
  for (int i = 0; i < lim; i++)
    if (i < rev[i]) {
      swap(f[i], f[rev[i]]);
    }
  for (int len = 1; len < lim; len <<= 1) {
    for (int i = 0; i < lim; i += len << 1) {
      for (int j = 0; j < len; j++) {
        int x = f[i + j], y = 1ll * f[i + j + len] * rt[j + len] % P;
        f[i + j] = inc(x, y), f[i + j + len] = dec(x, y);
      }
    }
  }
}

vector<int> operator*(vector<int> f, vector<int> g) {
  int n = f.size(), m = g.size(), inv;
  init(n + m - 2), inv = power(lim, P - 2), ntt(f), ntt(g);
  for (int i = 0; i < lim; i++)
    f[i] = 1ll * f[i] * g[i] % P;
  reverse(f.begin() + 1, f.end()), ntt(f), f.resize(n + m - 1);
  for (int &x : f)
    x = 1ll * x * inv % P;
  return f;
}
} // namespace Poly
using namespace Poly;

const int BLOCK = 3000;
void solve() {
  int N;
  read(N);
  vi A(N);
  read(A);
  vi F = {1};
  int conv_sum = 0;
  while (sz(F) < N + 1) {
    int len = sz(F);
    vi res = F * F;
    int len2 = len + BLOCK;
    cmin(len2, N + 1);
    F.resize(len2, 0);
    rep (i, len, len2) {
      conv_sum += (i - 1 < sz(res)) ? res[i - 1] : 0;
      if (conv_sum >= P) {
        conv_sum -= P;
      }
      rep (x, len, i) {
        conv_sum += (ll) F[x] * F[i - 1 - x] % P * (i - 1 - x < len ? 2LL : 1LL) % P;
        if (conv_sum >= P) {
          conv_sum -= P;
        }
      }
      F[i] = (ll) A[i - 1] * conv_sum % P;
    }
  }

  rep (i, 1, N + 1) {
    cout << F[i] << " \n"[i == N];
  }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  int t = 1;
  // cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}