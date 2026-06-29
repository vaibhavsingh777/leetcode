class Solution {
private:
int solve(vector<int>& coins, int rem, vector<int>& memo){
    if(rem < 0) return -1;
    if(rem == 0) return 0;
    if(memo[rem] != -2) return memo[rem];

    int min_count = INT_MAX;

    for(int coin : coins){
        int result = solve(coins, rem - coin, memo);
        if(result >= 0 && result < min_count){
            min_count = 1 + result;
        }
    }
    memo[rem] = (min_count == INT_MAX) ? -1 : min_count;
    return memo[rem];
}
public:
    int coinChange(vector<int>& coins, int amount) {
       vector<int> memo(amount + 1, -2);
       return solve(coins, amount, memo);
    }
};