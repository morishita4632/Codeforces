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
const int INF = 1001001001001001001ll;
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
    vector<int> A(n);
    rep(i, n) {
      cin >> A[i];
    }

    vector<int> L(n + 1);
    rep(i, n) {
      L[i + 1] = L[i] + A[i];
    }

    vector<int> R(n + 1);
    rep(i, n) {
      R[i + 1] = R[i] + A[n - 1 - i];
    }

    int l = 0, r = 0;
    int g = 0;
    int a = 0, b = 0;
    int Ltemp = 0, Rtemp = 0;
    while (l + r < n) {
      auto liter = upper_bound(all(L), L[l] + Rtemp);
      int nl = distance(L.begin(), liter);
      chmin(nl, n - r);
      Ltemp = L[nl] - L[l];
      a += Ltemp;
      l = nl;
      g++;

      if (l + r == n)
        break;

      auto riter = upper_bound(all(R), R[r] + Ltemp);
      int nr = distance(R.begin(), riter);
      chmin(nr, n - l);
      Rtemp = R[nr] - R[r];
      b += Rtemp;
      r = nr;
      g++;
    }
    cout << g << ' ' << a << ' ' << b << endl;
  }
}