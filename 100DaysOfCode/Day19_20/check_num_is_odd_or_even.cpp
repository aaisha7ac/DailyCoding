// TC : O(1)
// SC : O(1)


string oddEven(int N){
    // Write your code here.

    if(N & 1 == 1) {
        return "odd";
    }
    else {
        return "even";
    }
}