#include <bits/stdc++.h>
#include <climits>
#ifndef LOCAL
#define debug(...) 42
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
  vector<string> S(N);
  for (int i = 0; i < N; i++) {
    cin >> S[i];
  }
  vector<vector<int>> p[10];
  for (int i = 0; i < 10; i++) {
    p[i].resize(N);
  }
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      int c = S[i][j] - '0';
      if (p[c][i].size() < N)
        p[c][i].emplace_back(j);
    }
  }

  debug("ok");
  int ans = -1;
  for (int c = 0; c < 10; c++) {
    debug(c);
    vector<vi> adj(M);
    vector<int> q;
    bool ok = true;
    for (int i = 0; i < N; i++) {
      if (p[c][i].empty()) {
        ok = false;
      }
      for (auto j : p[c][i]) {
        q.pb(j);
        adj[j].pb(i);
      }
    }
    if (!ok) {
      continue;
    }
    sort(all(q));
    q.resize(unique(all(q)) - q.begin());
    int res = 0;
    vi mc(N, -1);
    vi vis(M);
    auto find = [&](auto self, int u) -> bool {
      vis[u] = 1;
      for (auto v : adj[u]) {
        if (mc[v] == -1 || (!vis[mc[v]] && self(self, mc[v]))) {
          mc[v] = u;
          return true;
        }
      }
      return false;
    };
    for (int t = 0;; t++) {
      for (auto i : q) {
        if (find(find, i)) {
          res += 1;
          if (res == N) {
            int v = i + t * M;
            if (ans == -1 || ans > v) {
              ans = v;
              break;
            }
          }
          vis.assign(N, 0);
        }
      }
      if (res == N) {
        break;
      }
    }
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