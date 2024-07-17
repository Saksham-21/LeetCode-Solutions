class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int r=0,l=0;;
        int ans=0;
        unordered_map<int,int> mp;
        for(;r<fruits.size();r++){
            mp[fruits[r]]++;
            for(;mp.size()>2;l++){
                mp[fruits[l]]--;
                if(mp[fruits[l]]==0){
                    mp.erase(fruits[l]);
                }
            }
            ans=max(ans,r-l+1);
        }
        return ans;
    }
};