class Solution {

    // TC : O(nlogk) 
    // SC : O(k) 

public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {

        priority_queue<pair<int,pair<int,int>>>maxh;

        for(int i = 0; i < points.size(); i++) {

            maxh.push({points[i][0] * points[i][0] + points[i][1] * points[i][1],{points[i][0], points[i][1]}});

            if (maxh.size() > k) {
                maxh.pop();
            }

        }

        vector<vector<int>> ans;

        while(maxh.size() > 0) {
            vector<int> ds;
            ds.push_back(maxh.top().second.first);
            ds.push_back(maxh.top().second.second);
            ans.push_back(ds);
            maxh.pop();
        }

        return ans;
        
    }
};