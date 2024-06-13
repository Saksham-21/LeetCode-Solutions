#include <cmath>
#include <algorithm>
#include <climits>
class Solution {
public:
    int calculatehours(vector<int> v,int mid,int h){
        int totalH=0;
        int n=v.size();
        for(int i=0;i<n;i++){
            totalH+= ceil((double)v[i]/ (double)mid);
            if(totalH>h) break;
        }
        return totalH;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        // cout<<high<<endl;
        int ans=INT_MAX;
        while(low<=high){
            int mid=low+(high-low)/2;
            int totalh=calculatehours(piles,mid,h);
            if(totalh<=h){
                ans=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return ans;
    }
};