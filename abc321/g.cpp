#include <bits/stdc++.h>
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

const int P = 998244353;
const int INV2 = (P + 1) / 2;

void solve() {
  int N, M;
  cin >> N >> M;
  vector<int> R(M), B(M);
  for (int i = 0; i < M; i++) {
    cin >> R[i];
    --R[i];
  }
  for (int i = 0; i < M; i++) {
    cin >> B[i];
    --B[i];
  }
  vector<long long> inv(M + 1);
  inv[1] = 1;
  for (int i = 2; i <= M; i++) {
    inv[i] = P - inv[P % i] * (P / i) % P;
  }
  vector<long long> fact(M + 1), invf(M + 1);
  fact[0] = invf[0] = 1;
  for (int i = 1; i <= M; i++) {
    fact[i] = fact[i - 1] * i % P;
    invf[i] = invf[i - 1] * inv[i] % P;
  }

  vector<int> X(N, 0);
  vector<int> Y(N, 0);
  for (int i = 0; i < M; i++) {
    X[R[i]] += 1;
    Y[B[i]] += 1;
  }
  
  vector<int> SX(1 << N, 0), SY(1 << N, 0);
  for (int i = 0; i < 1 << N; i++) {
    for (int j = 0; j < N; j++) {
      if (i >> j & 1) {
        SX[i] += X[j];
        SY[i] += Y[j];
      }
    }
  }
  
  vector<int> A(1 << N, 0);
  rep(i, 1, 1 << N) {
    if (SX[i] == SY[i]) {
      A[i] = fact[SX[i]] * fact[M - SX[i]] % P * invf[M] % P;
    }
  }

  rep(i, 1, 1 << N) {
    if (SX[i] == SY[i]) {
      for (int j = i - 1 & i; j > 0; --j &= i) {
        int k = i ^ j;
        if (j < k) {
          break;
        }
        int a = SX[k];
        int b = SX[(1 << N) - 1 - i];
        A[i] += P - A[j] * fact[a] % P * fact[b] % P * invf[a + b] % P;
        if (A[i] >= P) {
          A[i] -= P;
        }
      }
    }
  }

  int ans = 0;
  rep(i, 1, 1 << N) {
    ans += A[i];
    if (ans >= P) {
      ans -= P;
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
