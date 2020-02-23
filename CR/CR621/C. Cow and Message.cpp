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
  string s;
  cin >> s;
  int n = len(s);

  int ans = 0;

  // 1 letter //
  cvector<int> cnt;
  rep(i, n) {
    cnt[s[i]]++;
  }

  repp(c, 'a', 'z') {
    chmax(ans, cnt[c]);
  }

  // 2 letters //
  vector<cvector<int>> cnt_l(n);
  rep(i, n - 1) {
    repp(c, 'a', 'z') {
      cnt_l[i + 1][c] = cnt_l[i][c] + (s[i] == c);
    }
  }


  cvector<cvector<int>> table;
  repp(i, 1, n - 1) {
    char r = s[i];
    repp(l, 'a', 'z') {
      table[l][r] += cnt_l[i][l];
    }
  }

  repp(i, 'a', 'z') {
    repp(j, 'a', 'z') {
      chmax(ans, table[i][j]);
    }
  }

  cout << ans << endl;
}