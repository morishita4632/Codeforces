#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, a, b) for (int i = a; i <= (b); ++i)
#define repr(i, a, b) for (int i = a; i >= (b); --i)
#define bit(n) (1LL << (n))
#define len(x) ((ll)(x).size())
#define debug(var) cout << "[" << #var << "]\n" << var << endl
#define int long long
typedef long long ll;
const int INF = 1001001001;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;

template <typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
  int len = v.size();
  for (int i = 0; i < len; ++i) {
    s << v[i];
    if (i < len - 1)
      s << ' ';
  }
  return s;
}

template <typename T>
ostream& operator<<(ostream& s, const vector<vector<T>>& vv) {
  int len = vv.size();
  for (int i = 0; i < len; ++i) {
    s << vv[i];
    if (i != len - 1)
      s << '\n';
  }
  return s;
}

template <class T>
inline bool chmin(T& a, T b) {
  if (a > b) {
    a = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& a, T b) {
  if (a < b) {
    a = b;
    return true;
  }
  return false;
}

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

signed main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) {
      cin >> a[i];
    }

    int mn = INF, mx = 0;
    rep(i, n) {
      if (a[i] == -1) {
        if (i > 0 && a[i - 1] != -1) {
          chmin(mn, a[i - 1]);
          chmax(mx, a[i - 1]);
        }
        if (i < n - 1 && a[i + 1] != -1) {
          chmin(mn, a[i + 1]);
          chmax(mx, a[i + 1]);
        }
      }
    }
    int ans = (mx + mn) / 2;

    rep(i, n) {
      if (a[i] == -1)
        a[i] = ans;
    }

    int m = 0;
    rep(i, n - 1) {
      chmax(m, abs(a[i] - a[i + 1]));
    }

    cout << m << ' ' << ans << endl;
  }
}