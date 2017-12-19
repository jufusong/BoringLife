#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  vector<long long> a(51, 0);
  a[0] = 1;
  for (int i = 1; i <= 50; i++) {
    for (int j = 1; j <= 4 && j <= i; j++) {
      a[i] += a[i - j];
    }
  }
  cout << a[5] << endl;
  cout << a[50] << endl;
  return 0;
}
