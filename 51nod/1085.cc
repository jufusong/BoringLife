#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, w;
  cin >> n >> w;
  vector<int> a(w + 1);
  for (int i = 0, x, y; i < n; i++) {
    cin >> x >> y;
    for (int j = w; j >= x; j--) {
      a[j] = max(a[j], a[j - x] + y);
    }
  }
  cout << a[w] << endl;
  return 0;
}
