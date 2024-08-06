class Solution {
public:
    int minimumPushes(string word) {
        int arr[26];
        for(int i=0;i<word.size();i++){
            arr[word[i]-'a']++;
        }
        int n=sizeof(arr) / sizeof(arr[0]);
        sort(arr,arr+26,greater<int>());
        int ans=0;
        for(int i=0;i<26;i++){
            cout<<arr[i]<<" "<<endl;
            if(i >= 0 && i <= 7){
                ans += arr[i] * 1;
            }
            else if(i >= 8 && i <= 15){
                ans += arr[i] * 2;
            }
            else if(i >= 16 && i <= 23){
                ans += arr[i] * 3;
            }
            else{
                ans += arr[i] * 4;
            }
        }
        return ans;
    }
};