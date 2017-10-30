#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> a(1000001);
  a[1] = 1;
  vector<vector<int>> b(1000001);
  int ans = 0;
  for (int i = 1; i <= 1000000; i++) {
    for (auto x : b[i]) {
      a[i] += a[x];
    }
    if (a[i] == 252) {
      ans += i;
      cout << i << ",";
    }
    for (int j = i; j <= 1000000; j += i) {
      b[j].push_back(i);
    }
  }
  cout << endl;
  cout << ans << endl;
  return 0;
}
