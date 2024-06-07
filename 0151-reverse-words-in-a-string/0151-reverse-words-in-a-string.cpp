class Solution {
public:
    void emptystack(stack<char>& st, string& ans) {
        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        ans += ' ';
    }
    string reverseWords(string s) {
        int n = s.size();
        stack<char> st;
        string ans;

        for (int i = n - 1; i >= 0; i--) {
            if(s[i]==' ' && st.empty()){
                continue;
            }
            else if (s[i] == ' ' && !st.empty()) {
                emptystack(st, ans);
                
            } else {
                st.push(s[i]);
            }
        }
        while (!st.empty()) {
            char ch = st.top();
            st.pop();
            ans += ch;
        }
        while(!ans.empty() && ans.back() == ' ') {
            ans.pop_back();
        }
        return ans;
    }
};