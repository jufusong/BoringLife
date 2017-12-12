#include <bits/stdc++.h>

namespace Treap {
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
} // namespace Treap

using namespace std;

int main(int argc, char *argv[]) {
  int n, m;
  scanf("%d%d", &n, &m);
  Treap::Node<int>* root = nullptr;
  for (int i = 1; i <= n; i++) {
    root = Treap::merge(root, new Treap::Node<int>(i));
  }
  for (int i = 0; i < m; ++i) {
    int l, r;
    scanf("%d%d", &l, &r);
    auto r2 = Treap::split(root, r);
    auto r1 = Treap::split(r2.first, l - 1);
    r1.second->lazy ^= 1;
    root = Treap::merge(Treap::merge(r1.first, r1.second), r2.second);
  }
  for (int i = 0; i < n; i++) {
    auto r = Treap::split(root, 1);
    printf("%d ", r.first->key);
    root = r.second;
  }
  return 0;
}
