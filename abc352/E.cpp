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
struct unionfind {
  vector<int> p;
  unionfind(int N) { p = vector<int>(N, -1); }
  int root(int x) { return p[x] < 0 ? x : p[x] = root(p[x]); }
  bool same(int x, int y) { return root(x) == root(y); }
  void unite(int x, int y) {
    x = root(x);
    y = root(y);
    if (x != y) {
      if (p[x] < p[y]) {
        swap(x, y);
      }
      p[y] += p[x];
      p[x] = y;
    }
  }
  int size(int x) { return -p[root(x)]; }
};
void solve() {
  int N, M;
  cin >> N >> M;
  vi K(M), C(M);
  vc<vi> A(M);
  rep(i, M) {
    cin >> K[i] >> C[i];
    A[i].resize(K[i]);
    for (auto &a : A[i])
      cin >> a, --a;
  }

  vi p(M);
  rep(M) p[i] = i;
  sort(all(p), [&](int i, int j) { return C[i] < C[j]; });

  unionfind f(N);
  ll ans = 0;
  int cnt = 0;
  for (auto i : p) {
    int fir = A[i][0];
    for (auto &a : A[i]) {
      if (!f.same(fir, a)) {
        ans += C[i];
        f.unite(fir, a);
        cnt++;
      }
    }
  }
  if (cnt < N - 1) {
    ans = -1;
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