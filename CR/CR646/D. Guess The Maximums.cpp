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

void query(vector<int>& vec, int& res) {
  int n = len(vec);
  cout << '?' << ' ' << n << ' ';
  rep(i, n) {
    cout << (vec[i] + 1) << (i == n - 1 ? '\n' : ' ');
  }
  cout.flush();
  cin >> res;
}

void answer(vector<int>& vec) {
  int n = len(vec);
  cout << '!' << ' ';
  rep(i, n) {
    cout << vec[i] << (i == n - 1 ? '\n' : ' ');
  }
  cout.flush();
  string judge;
  cin >> judge;
}

signed main() {
  int t;
  cin >> t;
  while (t-- > 0) {
    int n, k;
    cin >> n >> k;
    vector<int> c(k);
    vector<vector<int>> S(k);
    rep(i, k) {
      cin >> c[i];
      rep(j, c[i]) {
        int temp;
        cin >> temp;
        temp--;
        S[i].pb(temp);
      }
    }

    vector<int> q(n);
    rep(i, n) {
      q[i] = i;
    }

    int mx;
    query(q, mx);
    q.clear();


    int l = 0, r = k - 1;
    while (l < r) {
      int m = (l + r) / 2;  // [l, m] [m+1, r]
      vector<int> q;
      repp(i, l, m) {
        for (int j : S[i])
          q.pb(j);
      }

      int res;
      query(q, res);
      q.clear();

      if (res == mx) {
        r = m;
      } else {
        l = m + 1;
      }
    }

    int maxSind = l;

    int sec_max;

    vector<bool> in_maxS(n, false);
    for (int j : S[maxSind]) {
      in_maxS[j] = true;
    }

    rep(i, n) {
      if (!in_maxS[i])
        q.pb(i);
    }
    query(q, sec_max);

    vector<int> ans(k);
    rep(i, k) {
      ans[i] = (i == maxSind ? sec_max : mx);
    }

    answer(ans);
  }
}