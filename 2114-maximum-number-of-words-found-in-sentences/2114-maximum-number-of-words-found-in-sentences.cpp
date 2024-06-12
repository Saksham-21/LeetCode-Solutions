class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int n=sentences.size();
        int maxwords=0;
        for(int i =0;i<n;i++){
            int k=sentences[i].size();
            int words=0;
            for(auto ch:sentences[i]){
                // char ch=sentences[i];
                if(ch==' '){
                    words++;
                }
            }
            words++;
            maxwords=max(maxwords,words);
        }
        return maxwords;
    }
};