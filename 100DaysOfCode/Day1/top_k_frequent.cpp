class Solution {

    // TC : O(nlogk)
    // SC : O(n) + O(k)
    
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        

        map<int,int>mp;
        vector<int>ans;
        for(int i = 0; i < nums.size(); i++) {
            mp[nums[i]]++;
        }

        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> minh;

        for(auto it = mp.begin(); it != mp.end(); it++) {
            minh.push({it->second,it->first});
            if(minh.size() > k) {
                minh.pop();
            }
        }

        while(minh.size() > 0) {
            ans.push_back(minh.top().second);
            minh.pop();
        }


        return ans;
    }
};