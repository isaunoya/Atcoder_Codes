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
vector<int> manacher(const vi &s) {
  vector<int> p(s.size() * 2 + 1);
  string t = "~";
  t += "-";
  for (int i = 0; i < (int)s.size(); i++) {
    t += s[i];
    t += "-";
  }
  int n = (int)t.size();
  int m = -1, r = -1;
  for (int i = 0; i < n; i++) {
    if (i <= r) {
      p[i] = min(p[m * 2 - i], r - i + 1);
    }
    while (i - p[i] >= 0 && i + p[i] < n && t[i + p[i]] == t[i - p[i]]) {
      ++p[i];
    }
    if (i + p[i] > r) {
      r = i + p[i] - 1;
      m = i;
    }
    --p[i];
  }
  string().swap(t);
  return p;
}
void solve() {
  int N;
  cin >> N;
  vi a(N);
  rep(i, N) {
    cin >> a[i];
  }

  vc<vi> adj(N);
  rep(i, N) {
    if (i - a[i] > 0 && i + a[i] < N - 1) {
      adj[i + a[i] + 1].pb(i - a[i] - 1);
    }
  }

  vi S(N);
  int r = 0;
  rep(i, N) {
    while (r < i) {
      r++;
      set<int> s;
      for (auto l : adj[r]) {
        s.emplace(S[l]);
      }
      while (s.count(S[r])) {
        S[r]++;
      }
    }
    while (r < i + a[i]) {
      r++;
      S[r] = S[i * 2 - r];
    }
  }

  auto p = manacher(S);
  // debug(S, p);
  bool ok = true;
  rep(i, N) {
    if (p[i + i + 2] / 2 != a[i]) {
      ok = false;
      break;
    } 
  }
  if (ok) {
    cout << "Yes\n";
    for (int i = 0; i < N; i++) {
      cout << S[i] + 1 << " \n"[i + 1 == N];
    }
  } else {
    cout << "No\n";
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