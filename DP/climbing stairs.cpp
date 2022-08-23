#include <bits/stdc++.h>

using namespace std;

//tabulation waala approach

int main() {

  int n=3;
  vector<int> dp(n+1,-1);
  
  dp[0]= 1;
  dp[1]= 1;
  
  for(int i=2; i<=n; i++){
      dp[i] = dp[i-1]+ dp[i-2];
  }
  cout<<dp[n];
  return 0;
}

//space optimised approach(poora vector lene ka zaroorat nahi hai, only two variables are being used therfore two variable are enough)
void func(){
    int n=3;
  
  int prev2 = 1;
  int prev = 1;
  
  for(int i=2; i<=n; i++){
      int cur_i = prev2+ prev;
      prev2 = prev;
      prev= cur_i;
  }
  cout<<prev;
  return;}