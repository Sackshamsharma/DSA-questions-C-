#include <bits/stdc++.h>
// #include <boost/algorithm/string.hpp>
using namespace std;
 
int main()
{
    string str,a,b;
    cin>>str;
    int a1=0,b1=0;
    for(int i=0;i<str.size();i++){
        if(str[i]==','){
            a =str.substr(0,i);
            b =str.substr(i+1,str.size()-i);
        }

    }
    
    stringstream geek(a);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int x = 0;
    geek >> x;

      stringstream geek1(b);
 
    // The object has the value 12345 and stream
    // it to the integer x
    int y = 0;
    geek1 >> y;

   cout<<__gcd(x,y)<<","<<(x*y)/__gcd(x,y);
}