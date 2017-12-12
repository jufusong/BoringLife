#include <bits/stdc++.h>

using namespace std;

void cal(int n) {
  int cnt = 0;
  for (int i = 0; i < 1 << n; ++i) {
    for (int j = 0; j < 1 << n; ++j) {
      if (__builtin_popcount(i) > 1 && __builtin_popcount(j) == __builtin_popcount(i) && (i & j) == 0) {
        vector<int> a, b;
        for (int k = 0; k < n; k++) {
          if ((1 << k) & i) a.push_back(k);
          if ((1 << k) & j) b.push_back(k);
        }
        int x = 0;
        for (int k = 0; k < a.size(); ++k) {
          x |= (a[k] > b[k]) * 2;
          x |= (a[k] < b[k]);
        }
        cnt += (x == 3);
      }
    }
  }
  cout << cnt / 2 << endl;
}

int main(int argc, char *argv[]) {
  cal(4);
  cal(7);
  cal(12);
  return 0;
}
