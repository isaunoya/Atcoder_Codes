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
template <typename T> struct Fenwick {
  int n;
  std::vector<T> a;

  Fenwick(int n = 0) { init(n); }

  void init(int n) {
    this->n = n;
    a.assign(n, T());
  }

  void add(int x, T v) {
    for (int i = x + 1; i <= n; i += i & -i) {
      a[i - 1] += v;
    }
  }

  T sum(int x) {
    auto ans = T();
    for (int i = x; i > 0; i -= i & -i) {
      ans += a[i - 1];
    }
    return ans;
  }

  T rangeSum(int l, int r) { return sum(r) - sum(l); }

  int kth(T k) {
    int x = 0;
    for (int i = 1 << std::__lg(n); i; i /= 2) {
      if (x + i <= n && k >= a[x + i - 1]) {
        x += i;
        k -= a[x - 1];
      }
    }
    return x;
  }
};

void solve() {
  int N;
  cin >> N;
  vi a(N);
  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }
  vector<int> p(N);
  for (int i = 0; i < N; i++) {
    p[i] = i;
  }
  sort(all(p), [&](int i, int j) { return a[i] < a[j]; });

  Fenwick<ll> c(N), t(N);
  ll ans = 0;
  for (int i : p) {
    ans += a[i] * c.sum(i);
    ans -= t.sum(i);
    c.add(i, 1);
    t.add(i, a[i]);
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