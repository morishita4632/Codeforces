#include <iostream>
#include <vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)

#pragma region BIT
template <typename T>
struct BIT {
  int n;
  vector<T> bit;
  // 1-indexed
  BIT(int n_) : n(n_ + 1), bit(n + 1, 0) {
  }

  T sum(int i) {
    T s(0);
    for (int x = i; x > 0; x -= (x & -x))
      s += bit[x];
    return s;
  }

  void add(int i, T a) {
    if (i == 0)
      return;
    for (int x = i; x <= n; x += (x & -x))
      bit[x] += a;
  }

  // [l, r)
  T query(int l, int r) {
    return sum(r - 1) - sum(l - 1);
  }

  int lower_bound(int w) {
    if (w <= 0)
      return 0;
    int x = 0, r = 1;
    while (r < n)
      r <<= 1;
    for (int k = r; k > 0; k >>= 1) {
      if (x + k <= n && bit[x + k] < w) {
        w -= bit[x + k];
        x += k;
      }
    }
    return x + 1;
  }

  // 0-indexed
  T sum0(int i) {
    return sum(i + 1);
  }
  void add0(int i, T a) {
    add(i + 1, a);
  }
  T query0(int l, int r) {
    return sum(r) - sum(l);
  }
};
#pragma endregion

signed main() {
  int n, q;
  scanf("%d %d", &n, &q);

  BIT<int> bt(n);
  rep(i, n) {
    int a;
    scanf("%d", &a);
    bt.add(a, 1);
  }

  while (q-- > 0) {
    int k;
    scanf("%d", &k);
    if (k < 0) {  // remove
      k = abs(k);
      int ind = bt.lower_bound(k);
      bt.add(ind, -1);
    } else {  // insert
      bt.add(k, 1);
    }
  }

  int ans = bt.lower_bound(1);
  if (ans > n)
    ans = 0;
  printf("%d\n", ans);
}