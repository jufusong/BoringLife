#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, K, m, A;
  cin >> n >> K >> m >> A;
  vector<vector<int>> a(n + 1);
  for (int i = 1; i <= A; i++) {
    int t;
    cin >> t;
    a[t].push_back(i);
  }
  auto check1 = [&a, &n, &m, &A, &K](int p) {
    if (a[p].empty()) return false;
    if (K == n) return true;
    vector<int> vec;
    for (int i = 1; i <= n; i++) {
      if (i != p) {
        if (a[i].size() == a[p].size() && a[i].back() > a[p].back()) {
          vec.push_back(1);
        } else if (a[i].size() < a[p].size()) {
          vec.push_back((int)a[p].size() + 1 - (int)a[i].size());
        } else {
          vec.push_back(0);
        }
      }
    }
    sort(vec.begin(), vec.end());
    int sum = 0;
    for (int i = 0; i < K; i++) {
      sum += vec[i];
    }
    return sum > m - A;
  };
  auto check2 = [&a, &n, &m, &A, &K](int p) {
    if (a[p].empty() && m == A) return false;
    int num = a[p].size() + (m - A);
    int last = (m > A ? m : a[p].back());
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      if (i != p) {
        if ((int)a[i].size() > num || (int)a[i].size() == num && a[i].back() < last) cnt++;
      }
    }
    return cnt < K;
  };
  for (int i = 1; i <= n; i++) {
    if (check1(i)) cout << "1 ";
    else if (check2(i)) cout << "2 ";
    else cout << "3 ";
  }
  return 0;
}
