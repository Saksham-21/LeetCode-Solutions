class Solution {
public:
    int climbStairs(int n) {
        if (n == 0) return 0;  // Handle case when there are 0 steps
    if (n == 1) return 1;  // Handle case when there is only 1 step
    if (n == 2) return 2;  // Handle case when there are 2 steps
        
        int arr[n+1];
        arr[0]=0;
        arr[1]=1;
        arr[2]=2;
        for(int i=3;i<=n;i++){
            arr[i]=arr[i-1]+arr[i-2];
        }
        return arr[n];
    }
};