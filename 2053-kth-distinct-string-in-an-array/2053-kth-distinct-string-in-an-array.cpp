class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> mp;
        for(int i=0;i<arr.size();i++){
            mp[arr[i]]++;
        }
        int disCount=0;
        for(const auto& it:arr){
            if(mp[it]==1){
                disCount++;
                if(disCount==k){
                    return it;
                }
            }
        }
        return "";
    }
};