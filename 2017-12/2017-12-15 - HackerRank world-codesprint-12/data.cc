#include <bits/stdc++.h>

using namespace std;

int main(int argc, char *argv[]) {
  srand(time(0));
  cout << 5 << endl;
  for (int i = 0; i < 5; i++) {
    cout << rand() % 10 << " ";
  }
  cout << endl;
  return 0;
}
