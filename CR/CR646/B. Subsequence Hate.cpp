#pragma region head
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
#define double long double
typedef double ld;
const int INF = 1001001001001001001ll;
const ll LINF = 1001001001001001001ll;
const int MOD = 1000000007;
const double EPS = 1e-9;
const double PI = acos(-1.0);

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
#pragma endregion

signed main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    string s;
    cin >> s;
    int n = len(s);

    vector<int> l0(n + 1), l1(n + 1);
    rep(i, n) {
      l0[i + 1] = l0[i] + (s[i] == '0');
      l1[i + 1] = l1[i] + (s[i] == '1');
    }

    vector<int> r0(n + 1), r1(n + 1);
    repr(i, n, 1) {
      r0[i - 1] = r0[i] + (s[i - 1] == '0');
      r1[i - 1] = r1[i] + (s[i - 1] == '1');
    }

    int ans = INF;
    rep(i, n + 1) {
      chmin(ans, l0[i] + r1[i]);
      chmin(ans, l1[i] + r0[i]);
    }

    cout << ans << endl;
  }
}