#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

struct Rect{
  ll h, w;
};

ll blue_area(vector<Rect>::iterator a, vector<Rect>::iterator b){
  ll max_h = 0;
  ll sum_w = 0;
  while (a < b){
    sum_w += a->w;
    max_h = max(max_h, a->h);
    ++a;
  }
  return max_h * sum_w;
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  vector<Rect> rects(n);
  for (int i = 0; i < n; ++i){
    cin >> rects[i].h;
    cin >> rects[i].w;
  }
  vector<vector<ll>> dp(n + 1, vector<ll>(k + 1));
  for (int i = 1; i <= n; ++i){
    dp[i][1] = blue_area(rects.begin(), rects.begin() + i);
  }
  for (int i = 1; i <= k; ++i){
    dp[1][i] = blue_area(rects.begin(), rects.begin() + 1);
  }
  
  for (int i = 2; i <= n; ++i){
    for (int j = 2; j <= k; ++j){
      ll area = LLONG_MAX;
      for (int a = 1; a <= i; ++a){
        area = min(area, dp[a][j - 1] + blue_area(rects.begin() + a, rects.begin() + i));
      }
      dp[i][j] = area;
    }
  }
  cout << dp[n][k];
  return 0;
}