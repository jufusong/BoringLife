#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    bool f = true;
    for (int j = 0; j < n; j++) {
      if (j != i) {
        f &= (abs(a[i] - a[j]) > k);        
      }
    }
    cnt += f;
  }
  cout << cnt << endl;
  return 0;
}
