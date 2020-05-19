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

#pragma endregion

signed main() {
  int t;
  cin >> t;

  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;

    sort(all(s));
    vector<string> a(k);
    int ind = 0;
    while (ind < k) {
      a[ind].pb(s[ind]);
      ind++;
    }

    if (a[0] != a[k - 1]) {
      cout << a[k - 1] << endl;
    } else {
      if (s[ind] == s[n - 1]) {
        while (ind < n) {
          a[ind % k].pb(s[ind]);
          ind++;
        }
        cout << a[0] << endl;
      } else {
        while (ind < n) {
          a[0].pb(s[ind]);
          ind++;
        }
        cout << a[0] << endl;
      }
    }
  }
}