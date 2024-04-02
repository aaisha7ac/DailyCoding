#include<bits/stdc++.h>
using namespace std;
class Result {
    string s;
    public:
  	Result(string s1){
		s=s1;
	}
	string revWordsOrder();
};

string Result::revWordsOrder()
{
    // Write your code here
    reverse(s.begin(),s.end());
    // cout << s << endl;
    string ans = "";
    int n = s.length();
    string temp = "";
    for(int i = 0; i < n; i++) {
        while(i < n && s[i] != ' ') {
            temp += s[i];
            i++;
        }
        reverse(temp.begin(), temp.end());
        ans += temp;
        if (i < n - 1)
            ans += ' ';
        temp = "";
    }
    return ans;
}

int main()
{
	int t;
    cin>>t;
    cin.ignore();
    while(t--){
        string str;
        getline(cin, str);
        Result r(str);
        cout<<r.revWordsOrder()<<endl;
    }
   return 0;
}