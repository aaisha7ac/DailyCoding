#include <bits/stdc++.h>
using namespace std;

#define N 10


/*     
 * Complete the 'counterDiagonal' function below.
 * Print the counter diagonal traversal of the matrix, seperated by space
 * @params
 *   mat -> square matrix of size (n x n) 
 *   n -> integer denoting size of square matrix
 */
// TC : O(n^3)
// SC : O(n * n)
void counterDiagonal(int mat[N][N], int n) {
  // Write your code here
  vector<vector<int>>vis(n,vector<int>(n,0));
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            int col = j;
            if(vis[i][j] != 1) {
                for(int k = i; k < n && col >= 0; k++) {
                    cout << mat[k][col] << " ";
                    vis[k][col] = 1;
                    col--;
                }
            }
        }
    }
}

int main()
{
    int n;
    cin >> n;
	int mat[N][N];
	for (int i = 0; i < n; i++)
	    for (int j = 0; j < n; j++)
	        cin >> mat[i][j];
	        
	counterDiagonal(mat, n);

	return 0;
}