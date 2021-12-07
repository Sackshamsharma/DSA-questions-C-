#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int precedence(char optor){
    if(optor=='+'){
        return 1;
    }
    else if(optor=='-'){
        return 1;
    }
    else if(optor=='*'){
        return 2;
    }
    else{
        return 2;
    }
}

int operation(int v1, int v2, char optor){
      if(optor=='+'){
        return v1+v2;
    }
    else if(optor=='-'){
        return v1-v2;
    }
    else if(optor=='*'){
        return v1*v2;
    }
    else{
        return v1/v2;
    }
}

int main() {
  string str;
  getline(cin, str);
  
  stack<int> opnds;
  stack<char> optor;
  
  for(int i=0;i<str.size();i++){
      char ch=str[i];
      if(ch=='('){
          optor.push(ch);
      }
      else if(ch==')'){
          while(optor.top()!='('){
              char op=optor.top();
              optor.pop();
              int v2=opnds.top();
              opnds.pop();
              int v1=opnds.top();
              opnds.pop();
              
              int res = operation(v1,v2,op);
              opnds.push(res);
          }
          optor.pop();
      }
      else if(isdigit(ch)){
          opnds.push(ch-'0');
      }
      else if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
          while(optor.empty()==false && optor.top()!='(' && precedence(ch)<=precedence(optor.top())){
               char op=optor.top();
              optor.pop();
              int v2=opnds.top();
              opnds.pop();
              int v1=opnds.top();
              opnds.pop();
              
              int res = operation(v1,v2,op);
              opnds.push(res);
          }
          optor.push(ch);
          }
          
      }
      while(optor.empty()==false){
           char op=optor.top();
              optor.pop();
              int v2=opnds.top();
              opnds.pop();
              int v1=opnds.top();
              opnds.pop();
              
              int res = operation(v1,v2,op);
              opnds.push(res);
      }
      cout<<opnds.top()<<endl;
  return 0;
}