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

vi kmp(string s) {
  int N = sz(s);
  vi nxt(N);

  int j = -1;
  nxt[0] = -1;
  rep(i, 1, N) {
    while (j != -1 && s[j + 1] != s[i]) {
      j = nxt[j];
    }

    if (s[j + 1] == s[i]) {
      j += 1;
    }
    nxt[i] = j;
  }

  return nxt;
}

void solve() {
  int N;
  cin >> N;
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }

  vector<string> NS;
  sort(all(S), [&](string i, string j) { return i.size() > j.size(); });

  for (int i = 0; i < N; i++) {
    bool ok = true;
    for (int j = 0; j < (int)NS.size(); j++) {
      if (i == j) {
        continue;
      }
      if (NS[j].find(S[i]) != NS[j].npos) {
        ok = false;
      }
    }
    if (ok) {
      NS.pb(S[i]);
    }
  }
  S.swap(NS);
  N = S.size();

  vector<vector<int>> A(N, vector<int>(N));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (i == j) {
        continue;
      }
      string cur = S[j] + "#" + S[i];

      A[i][j] = kmp(cur).back() + 1;
    }
  }

  vector<vector<int>> dp(N, vector<int>(1 << N, INF));
  for (int i = 0; i < N; i++) {
    dp[i][1 << i] = S[i].size();
  }
  for (int s = 1; s < 1 << N; s++) {
    for (int i = 0; i < N; i++) {
      if (s >> i & 1) {
        for (int j = 0; j < N; j++) {
          if (~s >> j & 1) {
            int ns = s | (1 << j);
            cmin(dp[j][ns], dp[i][s] + (int)S[j].size() - A[i][j]);
          }
        }
      }
    }
  }

  int ans = INF;
  for (int i = 0; i < N; i++) {
    cmin(ans, dp[i].back());
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