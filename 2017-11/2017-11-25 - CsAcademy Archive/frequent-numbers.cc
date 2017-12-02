#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, k;
  cin >> n >> k;
  vector<int> a(1001);
  for (int i = 0, t; i < n; i++) {
    cin >> t;
    a[t]++;
  }
  int cnt = 0;
  for (int i = 0; i <= 1000; i++) {
    cnt += (a[i] >= k);
  }
  cout << cnt << endl;
  return 0;
}
