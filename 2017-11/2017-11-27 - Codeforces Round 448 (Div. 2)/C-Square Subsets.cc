#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;
typedef long long ll;

int main(int argc, char *argv[]) {
  cin.sync_with_stdio(false);
  int n;
  cin >> n;
  vector<int> a(n, 0);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  vector<int> pr = {2,  3,  5,  7,  11, 13, 17, 19, 23, 29,
                    31, 37, 41, 43, 47, 53, 59, 61, 67};
  vector<int> b(1 << pr.size());
  b[0] = 1;
  for (auto x : a) {
    int v = 0;
    
  }
  return 0;
}
