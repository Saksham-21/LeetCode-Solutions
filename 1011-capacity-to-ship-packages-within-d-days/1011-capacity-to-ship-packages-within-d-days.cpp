class Solution {
public:
    int fun2(vector<int> vc,int mid){
        int days=1;
        int load=0;
        for(int i=0;i<vc.size();i++){
            if(load+vc[i]>mid){
                days++;
                load=vc[i];
            }else{
                load+=vc[i];
            }
        }
        return days;
    }
    int shipWithinDays(vector<int>& vc, int d) {
        int low=*max_element(vc.begin(),vc.end());
        int high=accumulate(vc.begin(),vc.end(),0);
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int n_days=fun2(vc,mid);
            if(n_days<=d){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};