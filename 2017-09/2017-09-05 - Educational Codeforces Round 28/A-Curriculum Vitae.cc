#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, cnt = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    cnt += a[i];
  }
  for (int i = 0; i < n; i++) {
    int sum = 0;
    for (int j = 0; j < n; j++) {
      sum += (j <= i ? !a[j] : a[j]);
    }
    cnt = max(cnt, sum);
  }
  cout << cnt << endl;
  return 0;
}
