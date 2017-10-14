#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int y, x;
    scanf("%d%d", &y, &x);
    printf("%d\n", y * 100 / (100 + x));
  }
  return 0;
}
