#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  std::ios_base::sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n, 0), c(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }
  vector<vector<int>> b;
  vector<bool> vis(n);
  for (int i = 0; i < n; ++i) {
    if (!vis[i]) {
      vis[i] = true;
      vector<int> vec(1, i);
      for (int j = a[i]; j != i; j = a[j]) {
        vec.push_back(j);
        vis[j] = true;
      }
      if (vec.size() & 1) {
        int m = vec.size() / 2;
        c[vec[m]] = vec[0];
        for (int j = 0; j < m; ++j) {
          c[vec[j]] = vec[j + m + 1];
          c[vec[j + m + 1]] = vec[j + 1];
        }
      } else {
        b.push_back(vec);        
      }
    }
  }
  if (b.size() & 1) {
    cout << -1 << endl;
    return 0;
  }
  sort(b.begin(), b.end(), [](const vector<int>& v1, const vector<int>& v2) {
      return v1.size() < v2.size();
    });
  for (int i = 0; i < b.size(); i += 2) {
    if (b[i].size() != b[i + 1].size()) {
      cout << -1 << endl;
      return 0;
    }
    for (int j = 0; j < b[i].size(); ++j) {
      c[b[i][j]] = b[i + 1][j];
      c[b[i + 1][j]] = b[i][(j + 1) % b[i].size()];
    }
  }
  for (auto x : c) {
    cout << x + 1 << " ";
  }
  return 0;
}
