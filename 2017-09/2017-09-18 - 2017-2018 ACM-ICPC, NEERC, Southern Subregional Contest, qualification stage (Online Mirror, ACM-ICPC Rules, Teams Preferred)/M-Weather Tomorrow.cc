#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  bool flag = true;
  for (int i = 2; i < n; i++) {
    flag &= (a[i] - a[i - 1] == a[1] - a[0]);
  }
  cout << (flag ? a.back() + a[1] - a[0] : a.back()) << endl;
  return 0;
}
