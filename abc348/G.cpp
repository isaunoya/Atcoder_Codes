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
  vc<pll> A(N);
  rep(i, N) cin >> A[i].se >> A[i].fi;
  sort(all(A));
  vi d(N);
  iota(all(d), 0);
  sort(all(d), [&](int i, int j) { return A[i].se > A[j].se; });
  vi AA(N);
  rep(i, N) AA[d[i]] = i;
  Fenwick<int> cnt(N);
  Fenwick<ll> sum(N);
  vl ans(N + 1);
  int cur = -1;
  auto move = [&](int x) {
    while (cur < x) {
      cur++;
      cnt.add(AA[cur], 1);
      sum.add(AA[cur], A[cur].se);
    }
    while (cur > x) {
      cnt.add(AA[cur], -1);
      sum.add(AA[cur], -A[cur].se);
      cur--;
    }
  };
  auto eval = [&](int k) {
    int r = cnt.kth(k);
    ll S = sum.sum(r);
    // debug(cur,k,S);
    return S;
  };
  auto solve = [&](auto &solve, int l, int r, int ql, int qr) -> void {
    if (l > r)
      return;
    int m = (l + r) / 2, qm = ql;
    ll cur = -LNF;
    for (int i = max(m - 1, ql); i <= qr; i++) {
      move(i - 1);
      ll valA = eval(m - 1) + A[i].se;
      ll valB = A[i].fi;
      if (valA - valB > cur) {
        cur = valA - valB;
        qm = i;
      }
    }
    ans[m] = cur;
    solve(solve, l, m - 1, ql, qm);
    solve(solve, m + 1, r, qm, qr);
  };
  solve(solve, 1, N, 0, N - 1);
  for (int i = 1; i <= N; i++) {
    cout << ans[i] << "\n";
  }
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