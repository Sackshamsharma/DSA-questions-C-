#include <bits/stdc++.h>
using namespace std;

string infixoperation(string v1, string v2, string optor){
      if(optor=="+"){
        return ("("+v1+optor+v2+")");
    }
    else if(optor=="-"){
         return ("("+v1+optor+v2+")");
    }
    else if(optor=="*"){
         return ("("+v1+optor+v2+")");
    }
    else{
         return ("("+v1+optor+v2+")");
    }
}

string postfixoperation(string v1, string v2, string optor){
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
  cin >> str;

 stack<int> res;
 stack<string>infix;
 stack<string> postfix;
 
 
 for(int i=str.size()-1;i>=0;i--){
     char ch=str[i];
     
     if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
         int val1=res.top();
         res.pop();
         int val2=res.top();
         res.pop();
         int val=operation(val1,val2,ch);
         res.push(val);
         
         string i1=infix.top();
         infix.pop();
         string i2=infix.top();
         infix.pop();
         string optori;
         optori+=ch;
         string vali=infixoperation(i1,i2,optori);
         infix.push(vali);
         
         string post1=postfix.top();
         postfix.pop();
         string post2=postfix.top();
         postfix.pop();
         string optorpost;
         optorpost+=ch;
         string valpost=postfixoperation(post1,post2,optorpost);
         postfix.push(valpost);
     }
     else{
         res.push(ch-'0');
         string val;
         val+=ch;
         infix.push(val);
         postfix.push(val);
     }
 }

 cout<<res.top()<<endl<<infix.top()<<endl<<postfix.top()<<endl;

  return 0;
}