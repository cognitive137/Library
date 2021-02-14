// top down dp = memoization
int fib(int n, int *dp) {
  if(n == 0 or n == 1) return n;
  if(dp[n] != -1) {
    // if dp[n] was -1 that means we are calculating for the first time
    // if dp[n] is not -1 then we already have a right ans
    return dp[n];
  }
  return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}


// bottom up - tabulation
int fibBU(int n) {
  int a = 0, b = 1, c;
  if(n == 0 or n == 1) return n;
  for(int i = 2; i <= n; i++) {
    c = a + b;
    a = b;
    b = c;
  }
  return c;
}
