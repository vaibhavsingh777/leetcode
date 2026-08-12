class Solution {
private:
int convertTime(string& keyTime){
    int hours = stoi(keyTime.substr(0,2));
    int mins = stoi(keyTime.substr(3,2));
    return hours * 60 + mins;
}


public:
    vector<string> alertNames(vector<string>& keyName, vector<string>& keyTime) {
       unordered_map<string, vector<int>> userTimes;
       for(int i = 0; i < keyName.size(); i++){
        userTimes[keyName[i]].emplace_back(convertTime(keyTime[i]));
       }

       vector<string> result;

       for(auto& [user, times] : userTimes){
        sort(times.begin(), times.end());
        for (int i = 2; i < times.size(); i++) {
                if (times[i] - times[i - 2] <= 60) {
                    result.push_back(user);
                    break; 
                }
            }
       }
       sort(result.begin(), result.end());
       return result;
    }
};