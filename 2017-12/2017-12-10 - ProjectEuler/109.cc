#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<int> v1, v2;
  for (int i = 1; i <= 20; ++i) {
    v1.push_back(i);
    v1.push_back(i * 3);
    v2.push_back(i * 2);
  }
  v1.push_back(25);
  v2.push_back(50);
  v1.insert(v1.end(), v2.begin(), v2.end());
  int ans = v2.size();
  for (auto x : v1) {
    for (auto y : v2) {
      ans += (x + y < 100);
    }
  }
  for (int i = 0; i < v1.size(); i++) {
    for (int j = i; j < v1.size(); j++) {
      int x = v1[i], y = v1[j];
      for (auto z : v2) {
        ans += (x + y + z < 100);
      }
    }
  }
  cout << ans << endl;
  return 0;
}
