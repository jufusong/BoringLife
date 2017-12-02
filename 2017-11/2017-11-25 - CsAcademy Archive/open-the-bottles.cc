#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<vector<int>> a(3, vector<int>(3));
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> a[i][j];
    }
  }
  int ans = 0;
  for (int i = 0; i < 3; i++) {
    ans += min(a[i][0], min(a[i][1], a[i][2]));
  }
  cout << ans << endl;
  return 0;
}
