class Solution {
private:
int count(int n){
    long long c = 0;
    while(n > 0){
      c += n % 2;  // Add 1 if the bit is set, 0 if it's not
      n /= 2;      // Shift to the next bit
    }
    return c;
}

public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            ans.push_back(count(i));
        }
        return ans;
    }
};