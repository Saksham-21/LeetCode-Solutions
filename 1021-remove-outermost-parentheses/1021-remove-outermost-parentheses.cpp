class Solution {
public:
    string removeOuterParentheses(string s) {
        stack<char> st;
        int n=s.size();
        string ans;
        int cnt=0;
        for(int i=0;i<n;i++){
            if(s[i]=='('){
                if(cnt>0){
                    ans+=s[i];
                }
                cnt++;   
                // st.push("(")
            }else if(s[i]==')'){
                cnt--;
                if(cnt>0){
                    ans+=s[i];
                }
                // ans.append()
            }
        }
        return ans;
    }
};