#include <bits/stdc++.h>
#include "/home/palayutm/pcl/number-theory/ntt.hpp"

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  vector<int> a(n + 1), b(m + 1);
  for (int i = 0; i <= n; i++) {
    scanf("%d", &a[i]);
  }
  for (int i = 0; i <= m; i++) {
    scanf("%d", &b[i]);
  }
  auto ret = ntt::convolution(a, b);
  for (int i = 0; i <= n + m; i++) {
    printf("%d ", ret[i]);
  }
  return 0;
}
