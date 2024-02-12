class Solution
{
    
    // TC : O(m + n) , m = length of pattern, n = length of text
    // SC : O(m)
    
    public:
    
        void find_LPS(string pat,vector<int> &LPS,int m) {
            
            int i = 1;
            int length = 0;
            LPS[0] = 0;
            
            while(i < m) {
                if(pat[i] == pat[length]) {
                    length++;
                    LPS[i] = length;
                    i++;
                }
                
                else {
                    if(length > 0) {
                        length = LPS[length - 1];
                    }
                    else {
                        LPS[i] = 0;
                        i++;
                    }
                }
            }
        }
        
        
        vector <int> search(string pat, string txt)
        {
            //code here
            int m = pat.length();
            int n = txt.length();
            
            vector<int>ans;
            
            vector<int>LPS(m,0);
            
            find_LPS(pat,LPS,m);
            
            int i = 0;
            int j = 0;
            
            while(i < n) {
                
                if(txt[i] == pat[j]) {
                    i++;
                    j++;
                }
                
                if(j == m) {
                    ans.push_back(i-j+1);
                    j = LPS[j-1];
                }
                else if(txt[i] != pat[j]) {
                    if(j > 0) {
                       j = LPS[j-1]; 
                    }
                    else {
                        i++;
                    }
                }
            }
            
            return ans;
        }
     
};