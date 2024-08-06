class Solution {
public:
    int minimumPushes(string word) {
        int arr[26] = {0};
        for(int i=0;i<word.size();i++){
            arr[word[i]-'a']++;
        }
        int n=sizeof(arr) / sizeof(arr[0]);
        sort(arr,arr+26,greater<int>());
        int ans=0;
        for(int i=0;i<26;i++){
            // cout<<arr[i]<<" "<<endl;
            if(arr[i] == 0) break;
            if(i < 8){
                ans += arr[i];
            }
            else if(i < 16){
                ans += arr[i] * 2;
            }
            else if(i < 24){
                ans += arr[i] * 3;
            }
            else{
                ans += arr[i] * 4;
            }
        }
        return ans;   
    }
};