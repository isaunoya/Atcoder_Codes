#if defined(LOCAL)
#include <D:/cp/templates/my_template_compiled.hpp>
#else
#pragma GCC optimize("Ofast,unroll-loops")
#pragma GCC target("avx2,popcnt")
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

void solve() {
  map<int, int> pre, nxt;
  int N;
  cin >> N;
  vi A(N);
  rep(i, N) cin >> A[i];
  nxt[0] = A[0];
  nxt[A.back()] = -1;
  rep(i, N - 1) nxt[A[i]] = A[i + 1], pre[A[i + 1]] = A[i];
  int Q;
  cin >> Q;
  while (Q--) {
    int op;
    cin >> op;
    if (op == 1) {
      int x, y;
      cin >> x >> y;
      int nx = nxt[x];
      nxt[y] = nx;
      nxt[x] = y;
      pre[y] = x;
      pre[nx] = y;
    } else {
      int x;
      cin >> x;
      int p = pre[x];
      int s = nxt[x];
      nxt[p] = s;
      pre[s] = p;
      pre.erase(x);
      nxt.erase(x);
    }
  }

  int x = 0;
  while (true) {
    if (x > 0) {
      cout << x << " ";
    }
    if (!nxt.count(x)) {
      break;
    } else {
      x = nxt[x];
    }
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