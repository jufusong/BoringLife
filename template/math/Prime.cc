#include <bits/stdc++.h>

using namespace std;

vector<pair<int, int>> factorization(int n) {
  if (n == 1) return {{1, 1}};
  vector<pair<int, int>> vec;
  for (int i = 2; i * i <= n; i++) {
    int cnt = 0;
    while (n % i == 0) {
      n /= i;
      cnt++;
    }
    if (cnt) vec.push_back({i, cnt});
  }
  if (n > 1) vec.push_back({n, 1});
  return vec;
}
