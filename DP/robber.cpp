int maxProfitByRobbingTD(int i, int *gold, vector<int> &dp) {
  if(i == 0) return gold[0];
  if(i == 1) return max(gold[0], gold[1]);
  if(dp[i] != -1) return dp[i];
  return dp[i] = max(maxProfitByRobbingTD(i-2, gold, dp) + gold[i], maxProfitByRobbingTD(i-1, gold, dp));
}

int maxProfitByRobbing(int i, int *gold) {
  if(i == 0) return gold[0];
  if(i == 1) return max(gold[0], gold[1]);
  return max(maxProfitByRobbing(i-2, gold) + gold[i], maxProfitByRobbing(i-1, gold));
}