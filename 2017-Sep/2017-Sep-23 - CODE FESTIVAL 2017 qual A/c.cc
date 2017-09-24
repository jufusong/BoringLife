#include <bits/stdc++.h>

using namespace std;

int b[105][105];

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  vector<int> a(255);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (auto c : s) {
      a[c]++;
    }
  }
  int x = 0, y = 0;
  if ((n & 1) && (m & 1)) {
    y = 1;
    x = n - 1 + m - 1;
  } else if (n & 1) {
    x = m;
  } else if (m & 1) {
    x = n;
  }
  int z = n * m - x - y;
  for (int i = 'a'; i <= 'z'; ) {
    if (a[i] >= 4 && z >= 4) {
      a[i] -= 4, z -= 4;
    } else if (a[i] >= 2 && x >= 2) {
      a[i] -= 2, x -= 2;
    } else if (a[i] >= 1 && y >= 1) {
      a[i] -= 1, y -= 1;
    } else if (a[i] == 0) {
      i++;
    } else {
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
  return 0;
}
