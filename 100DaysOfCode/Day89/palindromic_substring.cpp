class Solution {

    // Recursive approach
    // TC : O(n^3)
    // SC : O(n)
    
public:

    bool check(int s,int e,string &str) {

        if(s > e) {
            return true;
        }

        if(str[s] == str[e]) {
            return check(s+1,e-1,str);
        }

        return false;
    }


    int countSubstrings(string s) {

        int n = s.length();

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(check(i,j,s)) {
                    cnt++;
                }
            }
        }

        return cnt++;
        
    }
};


class Solution {

    // Memoization
    // TC : O(n^3)
    // SC : O(n^2) for memoization
    
public:

    int t[1001][10001];
    bool check(int s,int e,string &str) {

        if(s > e) {
            return true;
        }

        if(t[s][e] != -1) {
            return t[s][e];
        }

        if(str[s] == str[e]) {
            return t[s][e] = check(s+1,e-1,str);
        }

        return t[s][e] = false;
    }


    int countSubstrings(string s) {

        int n = s.length();

        memset(t,-1,sizeof(t));

        int cnt = 0;

        for(int i = 0; i < n; i++) {
            for(int j = i; j < n; j++) {
                if(check(i,j,s)) {
                    cnt++;
                }
            }
        }

        return cnt++;
        
    }
};

class Solution {

    // TC : O(n^2)
    // SC : O(n^2)

public:
    int countSubstrings(string s) {

        int n = s.length();

        int cnt = 0;

        vector<vector<bool>>t(n,vector<bool>(n,false));

        for(int l = 1; l <= n; l++) { // for the string of every length
            for(int i = 0; i + l - 1 < n; i++) {
                int j = i + l - 1;

                if(i == j) { // 1 length string
                    t[i][j] = true;
                }
                else if(j == i + 1) { // 2 length string 
                    t[i][j] = (s[i] == s[j]);
                }
                else { // length > 2
                    t[i][j] = (s[i] == s[j] && t[i+1][j-1]);
                }

                if(t[i][j] == true) {
                    cnt++;
                }
            }
        }

        return cnt;
        
    }
};

class Solution {

    // TC : O(n^2)
    // SC : O(1)

public:

    int cnt = 0;


    void check(int i,int j,string s,int n) {

        while(i >= 0 && j < n && s[i] == s[j]) {
            cnt++;
            i--;
            j++;
        }
    }


    int countSubstrings(string s) {

        int n = s.length();

        for(int i = 0; i < n; i++) {
            check(i,i,s,n); // for odd length
            check(i,i+1,s,n); // for even length
        }

        return cnt;
        
    }
};