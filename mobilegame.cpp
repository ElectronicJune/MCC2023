#include<bits/stdc++.h>
#define all(arr) arr.begin(), arr.end()
#define print(arr) {for (auto &i : arr) cerr << i << ' '; cerr << '\n';}
using namespace std;

void solve(){
  int n, a, b;
  cin >> n >> a >> b;
  vector<int> enemies(n);
  for (int i = 0; i < n; ++i){
    cin >> enemies[i];
  }
  sort(enemies.rbegin(), enemies.rend());
  int count = 0;
  int i = 0; 
  do {
    if (a >= b){
      cout << count << '\n';
      return;
    }
    if (a > enemies[i]){
      a += enemies[i];
      ++count;
      enemies.erase(enemies.begin() + i);
      i = 0;
      continue;
    }
    ++i;
  }while(i < enemies.size());
  if (a >= b){
    cout << count << '\n';
  }else{
    cout << -1 << '\n';
  }
}

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n;
  cin >> n;
  for (int i = 0; i < n; ++i){
    solve();
  }
  return 0;
}