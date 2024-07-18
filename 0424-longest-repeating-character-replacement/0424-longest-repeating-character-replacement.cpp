class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxfreq=0;
        map<char,int> mpp;
        for(;r<s.size();r++){
            mpp[s[r]]++;
            maxfreq=max(maxfreq,mpp[s[r]]);
            while((r-l+1)-maxfreq>k){
                mpp[s[l]]--;
                l++;
            }
            maxlen=max(maxlen,r-l+1);   
        }
        return maxlen;
    }
};