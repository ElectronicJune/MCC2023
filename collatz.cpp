#include<bits/stdc++.h>
#define all(arr) arr.begin(), arr.end()
using namespace std;

int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  freopen("test.in", "r", stdin);
  freopen("test.out", "w", stdout);
  int n, k;
  cin >> n >> k;
  int sum = 0;
  for (int i = 0; i < n; ++i){
    int number;
    cin >> number;
    for (int j = 0; j < k; ++j){
      if (number % 2 == 0){
        number = number / 2;
      }else{
        number = 3 * number + 1;
      }
    }
    sum += number;
  }
  cout << sum;
  return 0;
}