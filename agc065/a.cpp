#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, K;
  cin >> N >> K;
  vector<int> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  sort(A.begin(), A.end());
  vector<pair<int, int>> B;
  B.push_back(make_pair(A[0], 1));
  for (int i = 1; i < N; i++) {
    if (A[i] == A[i - 1]) {
      B.back().second++;
    } else {
      B.push_back(make_pair(A[i], 1));
    }
  }
  int cnt = B.size();
  int cnt_mx = 0;
  for (int i = 0; i < cnt; i++) {
    cnt_mx = max(cnt_mx, B[i].second);
  }
  vector<int> idx;
  for (int i = 0; i < cnt; i++) {
    if (B[i].second == cnt_mx) {
      idx.push_back(i);
    }
  }
  int cnt2 = idx.size();
  long long ans = 0;
  for (int i = 0; i < cnt2; i++) {
    long long a = B[idx[i]].first;
    long long b = B[idx[(i + 1) % cnt2]].first;
    long long d = (b - a + K) % K;
    if (a == b) {
      d = K;
    }
    ans = max(ans, (long long)K * (N - cnt_mx) - K + d);
  }
  cout << ans << endl;
}