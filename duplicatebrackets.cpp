#include<bits/stdc++.h>
using namespace std;
int main(){
    string str;
    getline(cin,str);
    bool ans=false;
    stack<char> st;
   
   for(int i=0;i<str.size();i++){
       if(str[i]==')'){
           if(st.top()=='('){
               ans=true;
               break;
           }
           else{
               while(st.top()!='('){
                   st.pop();
               }
               st.pop();
           }
       }
       else{
           st.push(str[i]); 
       }
   }
    if(ans==true)cout<<"true"<<endl;
    else cout<<"false"<<endl;
}