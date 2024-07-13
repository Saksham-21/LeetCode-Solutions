class Solution {
public:
    bool isAnagram(string s, string t) {
       int arr[26];
        for(int i=0;i<s.size();i++){
            arr[s[i]-'a']++;
        }
        for(int j=0;j<t.size();j++){
            arr[t[j]-'a']--;
        }
        
        
        for(int i=0;i<26;i++){
            if(arr[i]!=0){
                return false;
            }
        }
        return true;
    }
};