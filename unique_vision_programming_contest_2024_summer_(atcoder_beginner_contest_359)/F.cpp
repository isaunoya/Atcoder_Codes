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

void solve() {
  int N;
  cin >> N;
  vl A(N);
  rep(i, N) cin >> A[i];
  sort(all(A));
  vl B(N);
  B[0] = N - 1;
  rep(i, 1, N) B[i] = 1;
  ll ans = 0;
  rep(i, N) ans += B[i] * B[i] * A[i];

  // debug(ans);

  priority_queue<pll, vc<pll>, greater<pll>> pq;
  priority_queue<pll, vc<pll>, greater<pll>> rmv;

  auto remove = [&](int i) {
    ll cur = B[i] * B[i] * A[i];
    ll nx = (B[i] + 1) * (B[i] + 1) * A[i];
    rmv.emplace(nx - cur, i);
  };

  auto push = [&](int i) {
    ll cur = B[i] * B[i] * A[i];
    ll nx = (B[i] + 1) * (B[i] + 1) * A[i];
    pq.emplace(nx - cur, i);
  };

  rep(i, 1, N) { push(i); }

  auto build = [&]() {
    while (!rmv.empty() && !pq.empty() && pq.top() == rmv.top()) {
      pq.pop();
      rmv.pop();
    }
  };

  rep(i, N - 1) {
    if (i > 0) {
      remove(i);
    }
    while (B[i] > 1) {
      build();
      ll X = (B[i] * B[i] - (B[i] - 1) * (B[i] - 1)) * A[i];
      // debug(i + 1, B[i], A[i]);
      // assert(pq.size());
      auto [Y, j] = pq.top();
      if (X > Y) {
        B[i]--;
        ans += Y - X;

        // debug(Y, B[j], j);
        remove(j);
        B[j]++;
        push(j);
      } else {
        break;
      }
    }
  }
  // debug(A);
  // debug(B);

  // ll cur = 0;
  // rep(i, N) cur += B[i] * B[i] * A[i];

  // debug(cur, ans);
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