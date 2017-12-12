#include <bits/extc++.h>
#include <bits/stdc++.h>
using namespace __gnu_pbds;
using namespace std;

template <class T>
using Tree = tree<T, null_type, std::less<T>, rb_tree_tag,
                  tree_order_statistics_node_update>;

int main(int argc, char *argv[]) {
  Tree<long long> tree;
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int op, x;
    scanf("%d%d", &op, &x);
    long long v = x;
    if (op == 1) {
      tree.insert(v << 20 | i);
    } else if (op == 2) {
      tree.erase(tree.lower_bound(v << 20));
    } else if (op == 3) {
      auto it = tree.lower_bound(v << 20);
      printf("%d\n", (int)tree.order_of_key(*it) + 1);
    } else if (op == 4) {
      printf("%d\n", (int)(*tree.find_by_order(v - 1) >> 20));
    } else if (op == 5) {
      auto it = tree.lower_bound(v << 20);
      --it;
      printf("%d\n", (int)(*it >> 20));
    } else {
      auto it = tree.lower_bound((v + 1) << 20);
      printf("%d\n", (int)(*it >> 20));
    }
  }
  return 0;
}
