#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int A, B, C, D, E, F;
  cin >> A >> B >> C >> D >> E >> F;
  vector<int> a(F + 1), b(F + 1);
  a[0] = b[0] = 1;
  for (int i = 0; i <= F; i++) {
    if (a[i] && i + A <= F) a[i + A] = 1;
    if (a[i] && i + B <= F) a[i + B] = 1;
    if (b[i] && i + C <= F) b[i + C] = 1;
    if (b[i] && i + D <= F) b[i + D] = 1;
  }
  double mx = -1, x, y;
  for (int i = 0; i <= F; i++) {
    if (b[i]) {
      for (int j = 1; j <= F; j++) {
        if (j * E >= i && i + j * 100 <= F && a[j]) {
          if (i * 1.0 / (i + 100 * j) > mx) {
            mx = i * 1.0 / (i + 100 * j);
            x = i + j * 100, y = i;
          }
        }
      }
    }
  }
  cout << x << " " << y << endl;
  return 0;
}
