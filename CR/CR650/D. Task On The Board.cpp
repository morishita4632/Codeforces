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
#define test(s) \
  if (!(s))     \
    cout << "Line " << __LINE__ << ": [" << #s << "] is false" << endl;
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


template <typename T>
struct cvector {
  vector<T> vec;
  cvector() : vec(26) {
  }
  cvector(T init) : vec(26, init) {
  }
  T& operator[](char c) {
    return vec[c - 'a'];
  }
};

template <typename T>
ostream& operator<<(ostream& s, const cvector<T>& cvector) {
  s << cvector.vec;
  return s;
}


signed main() {
  int q;
  cin >> q;
  while (q-- > 0) {
    string s;
    cin >> s;
    int m;
    cin >> m;
    vector<int> b(m);
    cvector<int> cnt;
    rep(i, m) {
      cin >> b[i];
    }

    for (char c : s)
      cnt[c]++;

    string ans(m, '.');
    for (char c = 'z'; c >= 'a'; c--) {
      vector<int> zero_ind;
      rep(i, m) {
        if (ans[i] == '.' && b[i] == 0)
          zero_ind.pb(i);
      }

      if (len(zero_ind) <= cnt[c]) {
        for (int j : zero_ind) {
          ans[j] = c;
          rep(k, m) {
            b[k] -= abs(k - j);
          }
        }
      }
    }
    cout << ans << endl;
  }
}