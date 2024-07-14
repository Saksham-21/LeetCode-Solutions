class Solution {
public:
    string addBinary(string a, string b) {
        int n = std::max(a.size(), b.size());
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int carry = 0;
        string ans;
        for (int i = 0; i < n; ++i) {
            int bitA = (i < a.size()) ? a[i] - '0' : 0;
            int bitB = (i < b.size()) ? b[i] - '0' : 0;
            int sum = bitA + bitB + carry;
            ans.push_back((sum % 2) + '0');
            carry = sum / 2;
        }
        if (carry) {
            ans.push_back('1');
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};