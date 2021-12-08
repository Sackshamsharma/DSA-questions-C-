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

string prefixoperation(string v1, string v2, string optor){
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

 stack<int> res;
 stack<string>infix;
 stack<string> prefix;
 
 
 for(int i=0;i<str.size();i++){
     char ch=str[i];
     
     if(ch=='+' || ch=='-' || ch=='*' || ch=='/'){
         int val2=res.top();
         res.pop();
         int val1=res.top();
         res.pop();
         int val=operation(val1,val2,ch);
         res.push(val);
         
         string i2=infix.top();
         infix.pop();
         string i1=infix.top();
         infix.pop();
         string optori;
         optori+=ch;
         string vali=infixoperation(i1,i2,optori);
         infix.push(vali);
         
         string pre2=prefix.top();
         prefix.pop();
         string pre1=prefix.top();
         prefix.pop();
         string optorpre;
         optorpre+=ch;
         string valpre=prefixoperation(pre1,pre2,optorpre);
         prefix.push(valpre);
     }
     else{
         res.push(ch-'0');
         string val;
         val+=ch;
         infix.push(val);
         prefix.push(val);
     }
 }

 cout<<res.top()<<endl<<infix.top()<<endl<<prefix.top()<<endl;
  return 0;
}