#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> A(N);
  for (int i = 0; i < N; i++)
    cin >> A[i], --A[i];
  vector<int> P(N);
  for (int i = 0; i < N; i++)
    P[A[i]] = i;
  vector<pair<int, int>> ops;
  for (int i = 0; i < N; i++) {
    int p = P[i];
    if (p != i)
      ops.emplace_back(i, p), swap(A[i], A[p]), P[A[i]] = i, P[A[p]] = p;
  }
  cout << (int)(ops.size()) << "\n";
  for (auto [x, y] : ops) {
    cout << x + 1 << " " << y + 1 << "\n";
  }
}