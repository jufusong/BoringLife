#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  string s;
  int cx = 0, cy = 0;
  vector<int> a(1024, -1);
  while (cin >> s) {
    if (s == "END") {
      break;
    }
    int p;
    sscanf(s.c_str(), "%X", &p);
    p /= 16;
    cy++;
    if (a[p % 64] == p) {
      cx++;
      cout << "Hit" << endl;
    } else {
      a[p % 64] = p;
      cout << "Miss" << endl;
    }
  }
  printf("Hit ratio = %.2f%%\n", cx * 100.0 / cy);
  return 0;
}
