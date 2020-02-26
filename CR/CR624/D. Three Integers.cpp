#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define repp(i, A, b) for (int i = A; i <= (b); ++i)
#define repr(i, A, b) for (int i = A; i >= (b); --i)
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
inline bool chmin(T& A, T b) {
  if (A > b) {
    A = b;
    return true;
  }
  return false;
}

template <class T>
inline bool chmax(T& A, T b) {
  if (A < b) {
    A = b;
    return true;
  }
  return false;
}

__attribute__((constructor)) void initial() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);
  cout << fixed << setprecision(15);
}

vector<ll> divisor(ll n) {
  vector<ll> ret;
  for (ll i = 1; i * i <= n; i++) {
    if (n % i == 0) {
      ret.push_back(i);
      if (i * i != n)
        ret.push_back(n / i);
    }
  }
  sort(begin(ret), end(ret));
  return (ret);
}

signed main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int a, b, c;
    cin >> a >> b >> c;

    int mn = INF;
    vector<int> ans(3);

    repp(B, 1, 1e+4 + 10) {
      int A, C;
      int A_mn = INF;
      vector<int> div = divisor(B);
      for (int d : div) {
        if (chmin(A_mn, abs(a - d)))
          A = d;
      }

      int C_1 = c / B;
      int cand1 = B * C_1, cand2 = B * (C_1 + 1);
      if (cand1 < B)
        cand1 = -INF;
      C = (abs(cand1 - c) < abs(cand2 - c)) ? cand1 : cand2;

      int temp = abs(A - a) + abs(B - b) + abs(C - c);
      if (chmin(mn, temp)) {
        ans[0] = A, ans[1] = B, ans[2] = C;
      }
    }
    cout << mn << endl;
    cout << ans << endl;
  }
}