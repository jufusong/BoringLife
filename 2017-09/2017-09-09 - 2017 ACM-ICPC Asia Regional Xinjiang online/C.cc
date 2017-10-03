#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int T;
  cin >> T;
  while (T--) {
    int n, B;
    cin >> n >> B;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    for (int i = 1; i < n; i++) {
      cin >> b[i];
    }
    bool flag = true;
    for (int i = 1, sum = a[0]; i < n; i++) {
      if (sum < b[i] * B) {
        flag = false;
        break;
      }
      sum -= b[i] * B;
      sum += a[i];
    }
    cout << (flag ? "Yes" : "No") << endl;
  }
  return 0;
}
