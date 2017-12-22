#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<string> a(151);
  a[0] = "1";
  a[1] = "01";
  for (int i = 2; i <= 150; i++) {
    a[i] = a[i - 2][0];
    for (int j = 0; j < a[i - 1].size(); j++) {
      int x = (j + 1 >= a[i - 2].size() ? 0 : a[i - 2][j + 1] - '0');
      int y = a[i - 1][j] - '0';
      a[i] += (char)((x + y) % 2 + '0');
    }
  }
  int n;
  cin >> n;
  cout << a[n].size() - 1 << endl;
  for (auto c : a[n]) {
    cout << c << " ";
  }
  cout << endl;
  cout << a[n - 1].size() - 1 << endl;
  for (auto c : a[n - 1]) {
    cout << c << " ";
  }
  cout << endl;
  return 0;
}
