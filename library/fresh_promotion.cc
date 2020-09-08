#include <iostream>
#include <vector>
#include <string>


using namespace std;


bool CalWinner(int i, int j, const vector<int>& flat_code, const vector<int>& shopping_cart,
               vector<int>* dp_ptr) {
  int n = flat_code.size();
  if (i >= n)
    return true;
  int m = shopping_cart.size();
  if (j >= m)
    return false;

  auto& dp = *dp_ptr;
  if (dp[i][j] != -1)
    return dp[i][j];

  if (flat_code[i] == "*")
    dp[i][j] = CalWinner(i+1, j, flat_code, shopping_cart, dp_ptr) || CalWinner(i, j+1, flat_code, shopping_cart, dp_ptr);
  else if (flat_code[i] == "anything" || flat_code[i] == shopping_cart[j])
    dp[i][j] = CalWinner(i+1, j+1, flat_code, shopping_cart, dp_ptr);
  else
    dp[i][j] = false;
  return dp[i][j];
}


bool CheckWinner(vector<vector<string>> code_list, vector<string> shopping_cart) {
  vector<string> flat_code(1, "*");
  for (auto& group : code_list) {
    for (auto& fruit : group)
      flat_code.emplace_back(fruit);
    flat_code.emplace_back("*");
  }

  int n = flat_code.size();
  int m = shopping_cart.size();
  vector<vector<int>> dp(n, vector<int>(m, -1));

  return CalWinner(0, 0, flat_code, shopping_cart, &dp);
}
