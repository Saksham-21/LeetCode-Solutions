class Solution {
public:
    bool ispossible(vector<int>& vc,int m,int k,int mid){
        int cnt=0;
        int no_of_bouquets=0;
        for(int i=0;i<vc.size();i++){
            if(vc[i]<=mid){
                cnt++;
                if(cnt==k){
                    no_of_bouquets++;
                    cnt=0;
                }
            }else{
                cnt=0;
            }
        }
        // no_of_bouquets+=(cnt/k);
        return no_of_bouquets>=m;
    }
    int minDays(vector<int>& vec, int m, int k) {
        if(vec.size()< static_cast<long long>(m) * k){
            return -1;
        }
        int low=*min_element(vec.begin(),vec.end());
        int high=*max_element(vec.begin(),vec.end());
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(ispossible(vec,m,k,mid)){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;   
            }
        }
        return ans;
    }
};