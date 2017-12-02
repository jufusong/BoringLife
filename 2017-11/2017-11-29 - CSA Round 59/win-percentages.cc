#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int g1, g2, p1, p2;
  cin >> g1 >> p1 >> g2 >> p2;
  int x1 = 0, x2 = 0;
  while (x1 * 100 / g1 < p1) x1++;
  while (x2 * 100 / g2 < p2 + 1) x2++;
  cout << x2 - x1 - 1 << endl;
  return 0;
}
