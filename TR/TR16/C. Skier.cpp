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
#pragma endregion

signed main() {
  int t;
  cin >> t;

  typedef pair<int, int> pos;
  typedef pair<pos, pos> path;
  map<char, int> c2d = {{'E', 0}, {'N', 1}, {'W', 2}, {'S', 3}};
  vector<int> di = {0, -1, 0, 1};
  vector<int> dj = {1, 0, -1, 0};


  while (t-- > 0) {
    string S;
    cin >> S;

    pos now(0, 0);
    set<path> st;
    int ans = 0;
    for (char c : S) {
      pos next(now.fi + di[c2d[c]], now.se + dj[c2d[c]]);
      path p(now, next);
      if (st.find(p) != st.end()) {
        ans += 1;
      } else {
        ans += 5;
        st.insert(p);
        st.insert(path(next, now));
      }
      now = next;
    }
    cout << ans << endl;
  }
}