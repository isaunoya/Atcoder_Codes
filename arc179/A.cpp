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
  ll K;
  cin >> K;
  vl A(N);
  for (auto &ai : A)
    cin >> ai;
  sort(all(A));
  for (int t = 0; t < 2; t++) {
    vl B(N + 1);
    B[0] = 0;
    for (int i = 0; i < N; i++)
      B[i + 1] = B[i] + A[i];
    vi ok(N + 1);
    for (int i = 0; i <= N; i++)
      ok[i] = B[i] >= K;
    if (is_sorted(all(ok))) {
      cout << "Yes\n";
      for (auto ai : A) {
        cout << ai << " ";
      }
      return;
    }
    reverse(all(A));
  }
  cout << "No\n";
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