class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for(int x : s){
            if(!s.count(x-1)){
                int curr = x, cnt = 1;
                while(s.count(curr+1))
                {
                    curr++;
                    cnt++;
                }
                ans = max(cnt, ans);
            }
        }
        return ans;
    }
};