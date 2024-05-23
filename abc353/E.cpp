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

// #include <atcoder/string>
void solve() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (auto &s : S) {
    cin >> s;
  }

  sort(all(S));
  vector<pair<int, int>> st;
  st.emplace_back(sz(S[0]), 1);
  long long sum = sz(S[0]);
  long long ans = 0;
  for (int i = 1; i < N; i++) {
    int lcp = 0;
    while (lcp < sz(S[i - 1]) && lcp < sz(S[i]) && S[i - 1][lcp] == S[i][lcp]) {
      lcp += 1;
    }
    int cnt = 0;
    while (!st.empty() && st.back().first >= lcp) {
      cnt += st.back().second;
      sum -= 1ll * st.back().fi * st.back().se;
      st.pop_back();
    }
    if (cnt > 0) {
      sum += 1ll * lcp * cnt;
      st.emplace_back(lcp, cnt);
    }
    ans += sum;
    sum += 1ll * sz(S[i]);
    st.emplace_back(sz(S[i]), 1);
  }
  cout << ans << "\n";
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