class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(auto ch:s){
            if(st.empty()){
                cout<<ch<<"1"<<endl;
                st.push(ch);
            }else{
                char c=st.top();
                if(c=='(' && ch==')'){
                    cout<<"Poping ()"<<endl;
                    st.pop();
                }else if(c=='{' && ch=='}'){
                    cout<<"Poping {}"<<endl;
                    st.pop();
                }else if(c=='[' && ch==']'){
                    cout<<"Poping []"<<endl;
                    st.pop();
                }else{
                    cout<<ch<<"2"<<endl;
                    st.push(ch);
                }
            }
        }
        return st.empty();
    }
};