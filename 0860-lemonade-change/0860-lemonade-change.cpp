class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int n = bills.size();

        int fivecount = 0;
        int tencount = 0;

        for(int i = 0; i < n; ++i){
            if(bills[i] == 5)
            {
                fivecount++;
            }
            else if(bills[i] == 10)
            {
                if(fivecount > 0){
                fivecount--;
                tencount++;
                }
                else return false;
            }
            else if(bills[i] == 20)
            {
                if(tencount > 0 && fivecount > 0)
                {
                    tencount--;
                    fivecount--;
                }
                else if(fivecount > 2)
                {
                    fivecount -= 3;
                }
                else return false;
            }
            else return false;
        }
        return true;
    }
};