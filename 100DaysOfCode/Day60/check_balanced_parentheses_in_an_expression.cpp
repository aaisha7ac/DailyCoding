#include<bits/stdc++.h>
#include<stack>
using namespace std;
class balance{
    char *exp;
	public: 
  	balance(char p[]){ exp=p; }
	bool isMatchingPair(char, char);
	bool areBracketsBalanced();
};


bool balance:: isMatchingPair(char char1, char char2) {
  // Write your code here
 	if(char1 == '(' && char2 == ')' || char1 == '{' && char2 == '}' || char1 == '[' && char2 == ']') {
      return true;
    }
  return false;
}  
bool balance:: areBracketsBalanced( ) {
  // Write your code here
	stack<char>st;
	st.push('a');
  for(int i = 0; i < strlen(exp); i++) {
    if(exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
      st.push(exp[i]);
    }
    else if(exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
        if(!st.empty()) {
            if(isMatchingPair(st.top(),exp[i]) == true) {
                st.pop();
            }
          else {
            st.push(exp[i]);
          }
        }
        else {
            st.push(exp[i]);
        }
    }
  }
  if(st.size() == 1) {
    return true;
  }
  return false;
}


int main() 
{ 
  char exp[100]; 
  cin>>exp;
  balance obj(exp);
  if (obj.areBracketsBalanced( )) 
  cout<<"YES"<<endl;
     else
    cout<<"NO"<<endl;
 return 0; 
} 