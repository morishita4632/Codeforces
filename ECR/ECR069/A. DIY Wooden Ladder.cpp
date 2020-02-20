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

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];

    if (n == 2) {
      cout << 0 << endl;
      continue;
    }

    sort(all(a), greater<int>());

    cout << min(a[1] - 1, n - 2) << endl;
  }
}