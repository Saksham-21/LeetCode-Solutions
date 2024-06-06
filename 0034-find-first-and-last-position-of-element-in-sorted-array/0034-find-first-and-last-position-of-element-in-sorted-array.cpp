class Solution {
public:
    int firstOccurence(vector<int>& nums,int target){
        int low=0;
        int high=nums.size()-1;
        int first=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                first=mid;
                high=mid-1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return first;
    }
    int lastOccurence(vector<int>&nums,int target){
        int low=0;
        int high=nums.size()-1;
        int last=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(nums[mid]==target){
                last=mid;
                low=mid+1;
            }
            else if(nums[mid]<target){
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return last;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        int first=firstOccurence(nums,target);
        vector<int> vc;
        if(first==-1){
            vc.push_back(-1);
            vc.push_back(-1);
            return vc;
        }
        int last =lastOccurence(nums,target);
        vc.push_back(first);
        vc.push_back(last);
        return vc;
    }
};