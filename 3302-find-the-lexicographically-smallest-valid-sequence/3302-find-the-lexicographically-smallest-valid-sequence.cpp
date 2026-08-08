class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();
        
        // suf[i] stores the max j in word2 such that word2[j..m-1] 
        // can be matched as a subsequence of word1[i..n-1] with no changes.
        vector<int> suf(n + 1, m);
        int j = m - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                j--;
            }
            suf[i] = j + 1; // points to the first unmatched index in word2 from i onwards
        }
        
        vector<int> res;
        int j2 = 0;
        bool changed = false;
        
        for (int i = 0; i < n && j2 < m; ++i) {
            if (word1[i] == word2[j2]) {
                res.push_back(i);
                j2++;
            } else if (!changed && suf[i + 1] <= j2 + 1) {
                // We use our single change option here
                res.push_back(i);
                changed = true;
                j2++;
            }
            // Otherwise, we skip word1[i]
        }
        
        if (res.size() == m) {
            return res;
        }
        return {};
    }
};
