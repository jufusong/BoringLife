#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<vector<int>> a(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  auto check = [&a]() {
    for (auto v : a) {
      for (auto x : v) {
        if (x < 1) return false;
      }
    }
    int x = a[0][0] + a[0][1] + a[0][2];
    for (int i = 0; i < 3; i++) {
      int s1 = 0, s2 = 0;
      for (int j = 0; j < 3; j++) {
        s1 += a[i][j];
        s2 += a[j][i];
      }
      if (x != s1 || x != s2) return false;
    }
    return x == a[0][0] + a[1][1] + a[2][2] && x == a[2][0] + a[1][1] + a[0][2];
  };
  for (int i = 1; i <= 100000; i++) {
    a[0][0] = i;
    a[1][1] = a[0][0] + a[0][1] + a[0][2] - a[0][1] - a[2][1];
    a[2][2] = a[0][0] + a[0][1] + a[0][2] - a[0][2] - a[1][2];
    if (check()) {
      for (auto v : a) {
        for (auto x : v) {
          cout << x << " ";
        }
        cout << endl;
      }
      return 0;
    }
  }
  return 0;
}
