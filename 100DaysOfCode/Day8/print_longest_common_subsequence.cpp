// TC : O(n * m)
// SC : O(n * m)


int t[1001][1001];

string findLCS(int n, int m,string &s1, string &s2){
	// Write your code here.	

	for(int i = 0; i < n + 1; i++) {
		for(int j = 0; j < m + 1; j++) {

			if(i == 0 || j == 0) {
				t[i][j] = 0;
			}
		}
	}

	
	for(int i = 1; i < n + 1; i++) {
		for(int j = 1; j < m + 1; j++) {
			if(s1[i-1] == s2[j-1]) {
				t[i][j] = 1 + t[i-1][j-1];
			}
			else {
				t[i][j] = max(t[i-1][j],t[i][j-1]);
			}
		}
	}

	int length = t[n][m];
	// Upto here same code as finding the length of longest commom subsequence


	int index = length - 1;
	string ans = "";
	for(int i=0 ; i<length; i++) ans += '$';

	int i = n;
	int j = m;

	while(i > 0 && j > 0) {

		if(s1[i-1] == s2[j-1]) {
			ans[index] = s1[i-1];
			i--;
			j--;
			index--;
		}

		else if(t[i][j-1] > t[i-1][j]){
			j--;
	
		}
		else { // t[i-1][j] > t[i][j-1]) 
			i--;
		}
	}

	return ans;
}