#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    vector<bool> b(2000001);
    cout << "YES" << endl;
    for (int i = 1, cnt = 0; i <= 1000000 && cnt < n; i++) {
      if (!b[i]) {
        cout << i << " ";
        cnt++;
        for (int j = 0; j < n; j++) {
          for (int k = 0; k < j; k++) {
            b[a[j] - a[k] + i] = true;
          }
        }
      }
    }
    cout << endl;
  }
  return 0;
}
