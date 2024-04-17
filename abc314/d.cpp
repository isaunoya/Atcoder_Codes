#include <bits/stdc++.h>
#ifndef LOCAL
#define debug(...) 42
#endif
#define rep(i, x, y) for (int i = x; i < y; i++)
#define eb emplace_back
using namespace std;
template <typename T, typename T2> void cmin(T &x, const T2 &y) {
  if (x > y)
    x = y;
}
template <typename T, typename T2> void cmax(T &x, const T2 &y) {
  if (x < y)
    x = y;
}
using ll = long long;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)

void solve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  int q;
  cin >> q;
  vector<pair<int, char>> ops;
  int o = 0;
  while (q--) {
    int op, x;
    char c;
    cin >> op >> x >> c;
    --x;
    if (op == 1) {
      s[x] = c;
      ops.emplace_back(x, c);
    } else {
      o = op;
      ops.clear();
    }
  }
  if (o == 0) {
    cout << s << "\n";
  } else {
    for (int i = 0; i < n; i++) {
      if (o == 2) {
        if (s[i] >= 'A' && s[i] <= 'Z')
          s[i] = char(s[i] + 32);
      } else {
        if (s[i] >= 'a' && s[i] <= 'z')
          s[i] = char(s[i] - 32);
      }
    }
    for (auto [x, c] : ops) {
      s[x] = c;
    }
    cout << s << "\n";
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