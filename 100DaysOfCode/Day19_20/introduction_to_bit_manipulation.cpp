vector<int> bitManipulation(int num, int i){
    // Write your code here.

    vector<int> ans;

    int mask = 1 << i - 1;
    if((num & mask) == 0) {
        ans.push_back(0);
    }
    else {
        ans.push_back(1);
    }


    ans.push_back(num | mask);
    ans.push_back(num & ~mask);
    return ans;

}