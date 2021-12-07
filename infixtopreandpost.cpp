#include <bits/stdc++.h>


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

string preoperation(string v1, string v2, string optor){
      if(optor=="+"){
        return (optor+v1+v2);
    }
    else if(optor=="-"){
        return (optor+v1+v2);
    }
    else if(optor=="*"){
        return (optor+v1+v2);
    }
    else{
        return (optor+v1+v2);
    }
}

string postoperation(string v1, string v2, string optor){
      if(optor=="+"){
        return (v1+v2+optor);
    }
    else if(optor=="-"){
        return (v1+v2+optor);
    }
    else if(optor=="*"){
        return (v1+v2+optor);
    }
    else{
        return (v1+v2+optor);
    }
}

int main() {
  string str;
  getline(cin, str);

  stack<string> post;
  stack<string> pre;
  stack<char> ops;
  
  for(int i=0;i<str.size();i++){
      char ch=str[i];
      
      if(ch=='('){
          ops.push(ch);
      }
      else if ((ch>='0' && ch<='9')||(ch>='a' && ch<='z')||(ch>='A' && ch<='Z')){
          string op;
          op+=ch;
          pre.push(op);
          post.push(op);
      }
      else if(ch==')'){
          while(ops.top()!='('){
              char op=ops.top();
              ops.pop();
              string optor;
              optor+=op;
              
              string prev2=pre.top();
              pre.pop();
              string prev1=pre.top();
              pre.pop();
              string preres=preoperation(prev1,prev2,optor);
              pre.push(preres);
              
              string postv2=post.top();
              post.pop();
              string postv1=post.top();
              post.pop();
              string postres=postoperation(postv1,postv2,optor);
              post.push(postres);
          }
          ops.pop();
      }
      else if(ch=='+' || ch=='-' || ch=='*' ||ch=='/'){
           while(ops.empty()==false && ops.top()!='(' && precedence(ch)<=precedence(ops.top())){
              char op=ops.top();
              ops.pop();
              string optor;
              optor+=op;
              
              string prev2=pre.top();
              pre.pop();
              string prev1=pre.top();
              pre.pop();
              string preres=preoperation(prev1,prev2,optor);
              pre.push(preres);
              
              string postv2=post.top();
              post.pop();
              string postv1=post.top();
              post.pop();
              string postres=postoperation(postv1,postv2,optor);
              post.push(postres);
          }
          ops.push(ch);
      }
  }
      while(ops.empty()==false){
              char op=ops.top();
              ops.pop();
              string optor;
              optor+=op;
              
              string prev2=pre.top();
              pre.pop();
              string prev1=pre.top();
              pre.pop();
              string preres=preoperation(prev1,prev2,optor);
              pre.push(preres);
              
              string postv2=post.top();
              post.pop();
              string postv1=post.top();
              post.pop();
              string postres=postoperation(postv1,postv2,optor);
              post.push(postres);
          }
      
    cout<<post.top()<<endl<<pre.top()<<endl;
  return 0;
}