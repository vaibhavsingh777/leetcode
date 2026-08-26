class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int left = 0;
        int ans = 0;
        unordered_map<int,int> m;

        for(int i = 0; i < n; i++){
            m[fruits[i]]++;

            while(m.size() > 2){
                m[fruits[left]]--;
                if(m[fruits[left]] == 0)
                {
                    m.erase(fruits[left]);
                }
                left++;
            }
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};