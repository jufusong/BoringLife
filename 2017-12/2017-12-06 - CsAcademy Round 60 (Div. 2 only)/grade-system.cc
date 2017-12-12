#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  vector<int> a(n);
  int sum = 0;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    sum += a[i];
  }
  sum -= *max_element(a.begin(), a.end());
  sum -= *min_element(a.begin(), a.end());
  printf("%.0f\n", floor(sum * 1.0 / (n - 2)));
  return 0;
}
