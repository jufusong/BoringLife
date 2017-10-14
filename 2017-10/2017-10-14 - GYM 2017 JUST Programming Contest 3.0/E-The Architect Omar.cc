#include <bits/stdc++.h>

using namespace std;

char s[55];

int main(int argc, char *argv[]) {
  int T;
  scanf("%d", &T);
  while (T--) {
    int n;
    scanf("%d", &n);
    int b = 0, k = 0, l = 0;
    for (int i = 0; i < n; i++) {
      scanf("%s", s);
      if (s[0] == 'b') b++;
      if (s[0] == 'k') k++;
      if (s[0] == 'l') l++;
    }
    printf("%d\n", min(b / 2, min(k, l)));
  }
  return 0;
}
