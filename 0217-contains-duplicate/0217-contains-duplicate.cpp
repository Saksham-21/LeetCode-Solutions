class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> st(nums.begin(),nums.end());
        if(nums.size()==st.size()){
            return false;
        }else{
            return true;
        }
    }
};