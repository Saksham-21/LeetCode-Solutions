class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while(l<=r){
            char chl=s[l];
            char chr=s[r];
            if(isalnum(chl)==0){
                // cout<<chl<<endl;
                l++;
            }else if(isalnum(chr)==0){
                r--;
            }else{
                if(tolower(chl)==tolower(chr)){
                    l++;
                    r--;
                    // continue;
                }else{
                    return false;
                }
            }
        }
        return true;
    }
};