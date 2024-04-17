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
  ll N;
  cin >> N;
  vi p[26];
  string s;
  cin >> s;
  vi oc(26);
  for (int i = 0; i < (int)s.size(); i++) {
    p[s[i] - 'a'].pb(i);
    oc[s[i] - 'a']++;
  }
  string t;
  cin >> t;
  rep(i, (int)t.size()) if (!oc[t[i] - 'a']) {
    cout << 0 << "\n";
    return;
  }
  ll lo = 0, hi = LNF;
  auto check = [&](ll m) {
    ll repeat = 1, cur = 0;
    for (auto i : t) {
      int w = i - 'a';
      ll all = p[w].size();
      ll rem = p[w].end() - lower_bound(all(p[w]), cur);
      if (rem >= m) {
        int t = lower_bound(all(p[w]), cur) - begin(p[w]);
        cur = p[w][t + m - 1] + 1;
      } else {
        ll now = m - rem - 1;
        repeat++;
        repeat += now / all;
        if (repeat > N) {
          return false;
        }
        now %= all;
        cur = p[w][now] + 1;
      }
    }
    return repeat <= N;
  };
  while (hi - lo > 1) {
    ll m = (lo + hi) / 2;
    if (check(m)) {
      lo = m;
    } else {
      hi = m;
    }
  }
  cout << lo << "\n";
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