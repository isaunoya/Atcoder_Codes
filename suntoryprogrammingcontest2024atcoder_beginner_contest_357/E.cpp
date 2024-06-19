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

// #include<atcoder/scc>
// using namespace atcoder;

void solve() {
  int N;
  cin >> N;
  vi A(N);
  rep(N) cin >> A[i], --A[i];
  vi deg(N);
  rep(N) deg[A[i]]++;
  vi q;
  rep(N) if (!deg[i]) q.pb(i);
  rep(sz(q)) {
    int u = q[i];
    if (!--deg[A[u]])
      q.pb(A[u]);
  }
  vi ans(N);
  rep(N) if (!ans[i] && deg[i] == 1) {
    int u = i, c = 0;
    do {
      c++;
      u = A[u];
    } while (u != i);
    do {
      ans[u] = c;
      u = A[u];
    } while (u != i);
  }
  for (int i = sz(q) - 1; i >= 0; i--) {
    ans[q[i]] = ans[A[q[i]]] + 1;
  }
  ll ANS = 0;
  rep(N) ANS += ans[i];
  cout << ANS << "\n";
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