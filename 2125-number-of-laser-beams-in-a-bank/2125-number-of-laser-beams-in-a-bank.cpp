class Solution {
public:
    int ones_count(const string& s) {
        return count(s.begin(), s.end(), '1');
    }
    int numberOfBeams(vector<string>& bank) {
        int pre = 0;
        int final_ans = 0;
    
        for (const auto& row : bank) {
            int current = ones_count(row);
            if (current > 0) {
                final_ans += pre * current;
                pre = current;
            }
        }
    
        return final_ans;
    }
};