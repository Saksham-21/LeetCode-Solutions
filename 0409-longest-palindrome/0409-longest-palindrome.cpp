class Solution {
public:
    int longestPalindrome(string s) {
        vector<int> arr(128,0);
        for(char ch:s){
            arr[ch]++;
        }
        int ans=0;
        bool odd_found=false;
        for(int i=0;i<128;i++){
            if(arr[i]%2==0){
                ans+=arr[i];
            }else{
                ans+=(arr[i]-1);
                odd_found=true;
            }
        }
        if(odd_found){
            ans+=1;
        }
        return ans;
    }
};