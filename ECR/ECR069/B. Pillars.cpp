#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1e9 + 7;

template <class T>
inline bool chmin(T &a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T &a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

int main() {
  int n;
  cin >> n;

  vector<int> a(n);
  rep(i, n) cin >> a[i];

  int max_a = 0;
  int max_ind;
  rep(i, n) {
    if (chmax(max_a, a[i])) max_ind = i;
  }

  bool yes = true;
  repp(i, 0, max_ind - 2) {
    if (a[i] > a[i + 1]) yes = false;
  }
  repp(i, max_ind + 1, n - 2) {
    if (a[i] < a[i + 1]) yes = false;
  }

  if (yes) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
}