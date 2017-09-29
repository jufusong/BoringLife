#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    vector<pair<int, int>> a(4);
    for (int i = 0; i < 4; i++) {
      cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());
    bool flag = false;
    do {
      auto dis = [](pair<int, int> a, pair<int, int> b) {
        return (b.first - a.first) * (b.first - a.first) + (b.second - a.second) * (b.second - a.second);
      };
      if (dis(a[0], a[1]) == dis(a[2], a[3]) && dis(a[0], a[3]) == dis(a[1], a[2]) && dis(a[0], a[1]) + dis(a[0], a[3]) == dis(a[1], a[3])) {
        flag = true;
      }
    } while (next_permutation(a.begin(), a.end()));
    cout << flag << endl;
  }
  return 0;
}
