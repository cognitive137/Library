int minStepsBU(int n) {
  vector<int> dp(n+1, INT_MAX);
  // base case
  dp[2] = 1;
  dp[3] = 1;
  for(int i = 4; i<= n; i++) {
    int div_by_3 = INT_MAX, div_by_2 = INT_MAX, sub_by_1 = INT_MAX;
    if(i % 3 == 0) {
      div_by_3 = dp[i/3];
    }
    if(i % 2 == 0) {
      div_by_2 = dp[i/2];
    }
    sub_by_1 = dp[i-1];
    dp[i] = 1 + min({div_by_3, div_by_2, sub_by_1});
  }
  return dp[n];
}

int minStepsTD(int n, vector<int> &dp) {
  if(n == 2 or n == 3) return 1; 
  if(dp[n] != INT_MAX) return dp[n];
  int div_by_3 = INT_MAX, div_by_2 = INT_MAX, sub_by_1 = INT_MAX;
  if(n % 3 == 0) {
    div_by_3 = minStepsTD(n/3, dp);
  }
  if(n % 2 == 0) {
    div_by_2 = minStepsTD(n/2, dp);
  }
  sub_by_1 = minStepsTD(n-1, dp);;
  dp[n] = 1 + min({div_by_3, div_by_2, sub_by_1});
  return dp[n];
}