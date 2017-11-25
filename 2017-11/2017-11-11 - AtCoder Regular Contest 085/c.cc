#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  cin >> n >> m;
  int k = 1;
  for (int i = 0; i < m; i++, k *= 2);
  cout << ((n - m) * 100 + m * 1900) * k << endl;
  return 0;
}
