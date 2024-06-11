class Solution {
public:
    void sortColors(vector<int>& nums) {
        // int n=nums.size();
        // int onep=0,twop=0,threep=0;
        // for (int i=0;i<n;i++){
        //     if(nums[i]==0)onep++;
        //     else if(nums[i]==1) twop++;
        //     else threep++;
        // }
        // for(int i=0;i<n;i++){
        //     if(onep>0){
        //         nums[i]=0;
        //         onep--;
        //     }else if(twop>0){
        //         nums[i]=1;
        //         twop--;
        //     }else if(threep>0){
        //         nums[i]=2;
        //         threep--;
        //     }
        // }
        
        
        // D N F   A P P R O A C H 
        
        
        int n=nums.size();
        int low=0,mid=0,high=n-1;
        while(mid<=high){
            if(nums[mid]==0){
                swap(nums[low],nums[mid]);
                low++,mid++;
            }else if(nums[mid]==1){
                // swap(nums[mid],)
                mid++;
            }else{
                swap(nums[mid],nums[high]);
                high--;
            }
        }
        
        
    }
};