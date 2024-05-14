class Solution {

    // TC : O(2^n)
    // SC : O(m) , length of wordDict
    
public:

    unordered_set<string>st;
    int n;
    int dp[301];

    bool solve(int ind,string s) {

        if(ind >= n) {
            return true;
        }

        if(st.find(s) != st.end()) {
            return true;
        }

        for(int l = 1; l < n; l++) {
            string temp = s.substr(ind,l);
            if(st.find(temp) != st.end() && solve(ind + l,s)) {
                return true;
            }
        }

        return false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {

        n = s.length();
        memset(dp,-1,sizeof(dp));
        for(string word: wordDict) {
            st.insert(word);
        }

        return solve(0,s);
    }
};


class Solution {
    
    // 2. Memoization
    // TC : O(2^n)
    // SC : O(m) , length of wordDict

public:

    unordered_set<string>st;
    int n;
    int dp[301];

    bool solve(int ind,string s) {

        if(ind >= n) {
            return true;
        }

        if(st.find(s) != st.end()) {
            return true;
        }

        if(dp[ind] != -1) {
            return dp[ind];
        }

        for(int l = 1; l < n; l++) {
            string temp = s.substr(ind,l);
            if(st.find(temp) != st.end() && solve(ind + l,s)) {
                return dp[ind] = true;
            }
        }

        return dp[ind] = false;
    }


    bool wordBreak(string s, vector<string>& wordDict) {

        n = s.length();
        memset(dp,-1,sizeof(dp));
        for(string word: wordDict) {
            st.insert(word);
        }

        return solve(0,s);
    }
};