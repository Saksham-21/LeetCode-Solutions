class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
        int onep=0,twop=0,threep=0;
        for (int i=0;i<n;i++){
            if(nums[i]==0)onep++;
            else if(nums[i]==1) twop++;
            else threep++;
        }
        cout<<onep<<twop<<threep<<endl;
        for(int i=0;i<n;i++){
            if(onep>0){
                nums[i]=0;
                onep--;
                // break;
            }else if(twop>0){
                nums[i]=1;
                twop--;
                // break;
            }else if(threep>0){
                nums[i]=2;
                threep--;
                // break;
            }
        }
    }
};