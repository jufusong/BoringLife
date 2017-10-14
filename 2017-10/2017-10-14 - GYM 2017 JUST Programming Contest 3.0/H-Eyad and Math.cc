#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    puts(b * log(a) < d * log(c) ? "<" : ">");
  }
  return 0;
}
