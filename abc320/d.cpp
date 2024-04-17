#include <bits/stdc++.h>
#include <memory>
#ifndef LOCAL
#define debug(...)
#else
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#endif
#define rep1(a) for (int i = 0; i < a; i++)
#define rep2(i, a) for (int i = 0; i < a; i++)
#define rep3(i, a, b) for (int i = a; i < b; i++)
#define rep4(i, a, b, c) for (int i = a; i < b; i += c)
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
using pii = pair<int, int>;
template <class T> using vc = vector<T>;
template <class T> using pq = priority_queue<T>;
template <class T> using pqg = priority_queue<T, vector<T>, greater<T>>;
mt19937 rng(time(NULL));
const int inf = 1000000000;
const ll lnf = 1000000000000000000;
#define sz(x) int((x).size())
#define all(x) begin(x), end(x)
#define fi first
#define se second


template <class... T> void read() {}
template <class T> void read(T &x) { cin >> x; }
template <class T, class S> void read(pair<T, S> &v) {
  read(v.first, v.second);
}
template <class T> void read(vector<T> &v) {
  for (T &x : v)
    read(x);
}
template <class T, class... Ts> void read(T &a, Ts &...b) {
  read(a), read(b...);
}

void solve() {
  int N, M;
  cin >> N >> M;
  vc<vc<array<int, 3>>> e(N);
  for (int i = 0; i < M; i++) {
    int A, B, X, Y;
    cin >> A >> B >> X >> Y;
    --A;
    --B;
    e[A].emplace_back(array<int, 3>{B, X, Y});
    e[B].emplace_back(array<int, 3>{A, -X, -Y});
  }

  vi vis(N);
  vector<array<ll, 2>> pos(N);
  auto dfs = [&](auto &self, int u) -> void {
    vis[u] = 1;
    for (auto [v, x, y] : e[u]) {
      if (vis[v]) continue;
      else {
        pos[v] = array<ll, 2>{pos[u][0] + x, pos[u][1] + y};
        self(self, v);
      }
    }
  };

  dfs(dfs, 0);
  for (int i = 0; i < N; i++) {
    if (!vis[i]) {
      cout << "undecidable\n";
    } else {
      cout << pos[i][0] << " " << pos[i][1] << "\n";
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