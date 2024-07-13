// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1;
        int h=n;
        int bad=-1;
        while(l<=h){
            int mid=l+(h-l)/2;
            if(isBadVersion(mid)){
                bad=mid;
                h=mid-1;
            }else{
                l=mid+1;
            }
        }
        return bad;
    }
};