#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  auto cal = [](int n) {
    if(n == 1) return vector<int>{2};
    if(n == 2) return vector<int>{3, 4};
    vector<int> a((n & (~1)) - 1, 1);
    if (n & 1) a.push_back(2), a.push_back((n + 1) / 2);
    else a.push_back(n / 2 - 1);
    return a;
  };
  int n, m;
  cin >> n >> m;
  auto a = cal(n), b = cal(m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << a[i] * b[j] << " ";
    }
    cout << endl;
  }
  return 0;
}
