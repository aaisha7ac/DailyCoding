// TC : O(1)
// SC : O(1)


int XOR(int temp) {
    int rem = temp % 4;
    if(rem == 0) {
        return temp;
    }
    else if(rem == 1) {
        return 1;
    }
    else if(rem == 2) {
        return temp + 1;
    }
    else { // (rem == 3)
        return 0;
    }
}

int findXOR(int L, int R){
    // Write your code here.

    int ans = XOR(R) ^ XOR((L-1));

    return ans;
}