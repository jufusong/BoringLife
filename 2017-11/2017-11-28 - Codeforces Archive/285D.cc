#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a = {1,         0, 18,        0, 1800,      0, 670320,    0,
                   734832000, 0, 890786230, 0, 695720788, 0, 150347555, 0};
  cout << a[n - 1] << endl;
  return 0;
}
