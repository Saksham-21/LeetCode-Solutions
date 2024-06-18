class Solution {
public:
    // void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    //     vector<int> ans;
    //     int i=0,j=0;
    //     while(i<m && j<n){
    //         if(nums1[i]<nums2[j]){
    //             ans.push_back(nums1[i]);
    //             i++;
    //         }else{
    //             ans.push_back(nums2[j]);
    //             j++;
    //         }
    //     }
    //     nums1=ans;
    // }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int left=m-1;
        int right=0;
        while(left>=0 && right<n){
            if(nums1[left]>nums2[right]){
                swap(nums1[left],nums2[right]);
                left--;
                right++;
            }else{
                break;
            }
        }
        for(int i=m;i<m+n;i++){
            nums1[i]=nums2[i-m];
        }
        sort(nums1.begin(),nums1.end());
    }
};