class Solution {
public:
    int numberOfSubstrings(string s) {
        int l=0,r=0,cnt=0;
        map<char,int> mp;
        for(;r<s.size();r++){
            mp[s[r]]++;
            while(mp.size()==3){
                cnt+=s.size()-r;
                mp[s[l]]--;
                if(mp[s[l]]==0){
                    mp.erase(s[l]);
                }
                l++;
            }
        }
        return cnt;
    }
};