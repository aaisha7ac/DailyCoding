class Solution {

    // TC : O(n * k log k) , for iterating each string in the vector and sorting them
    // SC : O(n)
    
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {

        vector<vector<string>>ans;

        map<string,vector<string>>mp;

        for(auto it: strs) {
            // cout << it << " ";
            string s = it;
            sort(s.begin(),s.end());
            mp[s].push_back(it);
        }

        for(auto it : mp) {
            ans.push_back(it.second); // Here we are pushing the whole group of string present at particular key
        }

        return ans;
        
    }
};