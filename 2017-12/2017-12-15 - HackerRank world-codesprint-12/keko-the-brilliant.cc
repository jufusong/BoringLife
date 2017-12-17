#include <bits/stdc++.h>

using namespace std;

namespace treap {
template <class T> struct Node {
  int sz, fix;
  T key;
  bool lazy;
  Node *ch[2];
  Node(T key) : sz(1), key(key), fix(rand()), lazy(false) {
    ch[0] = ch[1] = nullptr;
  }
  void pushup() {
    sz = 1;
    for (int i = 0; i < 2; i++) {
      if (ch[i]) {
        sz += ch[i]->sz;
      }
    }
  }
  void pushdown() {
    if (lazy) {
      lazy = false;
      std::swap(ch[0], ch[1]);
      if (ch[0] != nullptr) ch[0]->lazy ^= 1;
      if (ch[1] != nullptr) ch[1]->lazy ^= 1;
    }
  }
};
template <class T> Node<T> *merge(Node<T> *A, Node<T> *B) {
  if (B == nullptr) return A;
  if (A == nullptr) return B;
  if (A->fix < B->fix) {
    A->pushdown();
    A->ch[1] = merge(A->ch[1], B);
    A->pushup();
    return A;
  } else {
    B->pushdown();
    B->ch[0] = merge(A, B->ch[0]);
    B->pushup();
    return B;
  }
}
template <class T> std::pair<Node<T> *, Node<T> *> split(Node<T> *A, int k) {
  if (A == nullptr) return {nullptr, nullptr};
  A->pushdown();
  std::pair<Node<T> *, Node<T> *> ret;
  if ((A->ch[0] ? A->ch[0]->sz : 0) >= k) {
    ret = split(A->ch[0], k);
    A->ch[0] = ret.second;
    A->pushup();
    ret.second = A;
  } else {
    ret = split(A->ch[1], k - 1 - (A->ch[0] ? A->ch[0]->sz : 0));
    A->ch[1] = ret.first;
    A->pushup();
    ret.first = A;
  }
  return ret;
}
template <class T> int order_by_key(Node<T> *A, T val) {
  if (A == nullptr) return 0;
  int lsz = (A->ch[0] == nullptr ? 0 : A->ch[0]->sz);
  if (A->key >= val) return lsz + 1 + order_by_key(A->ch[1], val);
  return order_by_key(A->ch[0], val);
}
} // namespace Treap

const int N = 200005;

vector<int> g[N];
int R[N];
treap::Node<int>* r[N];

void dfs(int u, int fa) {
  r[u] = nullptr;
  for (auto v : g[u]) {
    if (v != fa) {
      dfs(v, u);
      if (r[u] == nullptr || r[u]->sz < r[v]->sz) {
        swap(r[u], r[v]);
      }
      while (r[v] != nullptr) {
        auto l1 = treap::split(r[v], 1);
        r[v] = l1.second;
        int v = l1.first->key;
        int k = treap::order_by_key(r[u], v);
        auto l2 = treap::split(r[u], k);
        r[u] = treap::merge(l2.first, l1.first);
        r[u] = treap::merge(r[u], l2.second);
      }
    }
  }
  if (r[u] == nullptr) {
    r[u] = new treap::Node<int>(R[u]);
    return;
  }
  int k = treap::order_by_key(r[u], R[u]);
  if (k == r[u]->sz) {
    r[u] = treap::merge(r[u], new treap::Node<int>(R[u]));
    return;
  }
  auto l1 = treap::split(r[u], k);
  auto l2 = treap::split(l1.second, 1);
  l2.first->key = R[u];
  r[u] = treap::merge(treap::merge(l1.first, l2.first), l2.second);
}

int main(int argc, char *argv[]) {
  int n;
  cin >> n;
  for (int i = 1; i <= n; ++i) {
    cin >> R[i];
  }
  for (int i = 0; i < n - 1; ++i) {
    int u, v;
    cin >> u >> v;
    g[u].push_back(v);
    g[v].push_back(u);
  }
  dfs(1, 0);
  cout << n - r[1]->sz << endl;
  return 0;
}
