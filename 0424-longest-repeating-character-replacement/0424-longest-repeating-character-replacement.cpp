class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0,r=0,maxlen=0,maxfreq=0;
        map<char,int> mpp;
        for(;r<s.size();r++){
            mpp[s[r]-'A']++;
            maxfreq=max(maxfreq,mpp[s[r]-'A']);
            while((r-l+1)-maxfreq>k){
                if(mpp[s[l]]==1){
                    mpp.erase(s[l]);
                }else{
                    mpp[s[l]-'A']--;
                    maxfreq=0;
                    for(auto ch:mpp){
                        maxfreq=max(maxfreq,ch.second);
                    }
                }
                l++;
            }
            if((r-l+1)-maxfreq<=k){
                maxlen=max(maxlen,r-l+1);   
            }
        }
        return maxlen;
    }
};