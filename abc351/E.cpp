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
  vc<pii> A(N);
  for (auto &[x, y] : A)
    cin >> x >> y;

  auto solve = [&](const vc<pii> &a) {
    vi px, py;
    for (auto [x, y] : a) {
      px.pb(x + y);
      py.pb(x - y);
    }

    ll ans = 0;
    sort(all(px));
    sort(all(py));
    ll S1 = 0;
    ll S2 = 0;
    for (int i = 0; i < sz(px); i++) {
      ans += 1ll * px[i] * i - S1;
      ans += 1ll * py[i] * i - S2;
      S1 += px[i];
      S2 += py[i];
    }
    return ans / 2;
  };

  vc<pii> pot[2];
  for (auto [x, y] : A) {
    pot[(x + y) % 2].pb(x, y);
  }

  cout << solve(pot[0]) + solve(pot[1]) << "\n";
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