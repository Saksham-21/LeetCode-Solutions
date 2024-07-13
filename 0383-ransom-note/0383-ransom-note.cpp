class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int arr[26];
        for(int i=0;i<magazine.size();i++){
            arr[magazine[i]-'a']++;
        }
        for(int j=0;j<ransomNote.size();j++){
            arr[ransomNote[j]-'a']--;
            if(arr[ransomNote[j]-'a']<0){
                return false;
            }
        }
        return true;
    }
};