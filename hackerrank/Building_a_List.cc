#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    string s;
    cin >> n >> s;
    vector<string> vec;
    for (int i = 1; i < 1 << n; i++) {
      string t;
      for (int j = 0; j < n; j++) {
        if ((1 << j) & i) {
          t += s[j];
        }
      }
      vec.push_back(t);
    }
    sort(vec.begin(), vec.end());
    for (auto x : vec) {
      cout << x << endl;
    }
  }
  return 0;
}
