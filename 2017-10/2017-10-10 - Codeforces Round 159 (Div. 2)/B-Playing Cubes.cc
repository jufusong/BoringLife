#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int x, y;
  cin >> x >> y;
  cout << x + y - 1 - min(x, y) << " " << min(x, y) << endl;
  return 0;
}
