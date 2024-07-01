class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int n=g.size();
        int m=s.size();
        int gp=0,sp=0;
        int cnt=0;
        while(sp<m && gp<n){
            if(s[sp] >= g[gp]){
                cnt++;
                gp++;
            }
            sp++;
        }
        return cnt;
    }
};