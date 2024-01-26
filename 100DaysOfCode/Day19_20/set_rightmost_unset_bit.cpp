// TC : O(n)
// SC : O(1)

int setBits(int N){
    // Write your code here.
    int i = 0;
    int num = N;

    // finds the first unset bit
    while(N != 0) {
        if((N & 1) == 0) {
            break;
        }
        N = N >> 1;
        i++;
    }
  
    if(N == 0) {
        return num;
    }
    
    return (num | (1 << i));

}
