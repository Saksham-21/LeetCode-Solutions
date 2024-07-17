class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int l=0,r=0,maxlen=0;
        map<int,int> mpp;
        for(;r<fruits.size();r++){
            mpp[fruits[r]]++;
            while(mpp.size()>2){
                if(mpp[fruits[l]]==1){
                    mpp.erase(fruits[l]);
                }else{
                    mpp[fruits[l]]--;
                }
                l++;
            }
            maxlen=max(maxlen,r-l+1);
        }
        return maxlen;
    }
};