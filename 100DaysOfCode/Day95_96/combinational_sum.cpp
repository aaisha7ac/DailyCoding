class Solution {

    // TC : O(2^n * k) , 2n = we have two choices pick or notpick , k = for transferring ds into ans
    // SC : O(k * x), x = no.of combinations

public:

    void solve(int ind,vector<int>& candidates,int target,vector<int>ds,vector<vector<int>> &ans) {

        if(ind == candidates.size()) {
            if(target == 0){
                ans.push_back(ds);
            }
            return;
        }

        if(candidates[ind] <= target) {
            ds.push_back(candidates[ind]);
            solve(ind,candidates,target - candidates[ind],ds,ans);
            ds.pop_back();
        }

        solve(ind + 1,candidates,target,ds,ans);
    }
    

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<int>ds;
        vector<vector<int>>ans;
        solve(0,candidates,target,ds,ans);
        return ans;
        
    }
};