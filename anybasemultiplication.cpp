#include<iostream>
using namespace std;

int getSum(int b, int n1, int n2) {
    // write your code here
    int res=0;
    int p=1;
    int c=0;
    while(n1>0 || n2>0 || c>0){
        int d1=n1%10;
        int d2=n2%10;
        n1/=10;
        n2/=10;
        int dig=d1+d2+c;
        c=dig/b;
        dig=dig%b;
        
        res+=dig*p;
        p*=10;
    }
    return res;
}

int getProductWithSingleDigit(int b,int n1,int d2){
    int rv=0;
    int c=0;
    int p=1;
    
    while(n1>0 || c>0){
        int d1=n1%10;
        n1/=10;
        
        int sprd = d1*d2 +c;
        int rem = sprd%b;
        c=sprd/b;
        rv+=rem*p;
        p*=10;
    }
    
    return rv;
}

int getProduct(int b, int n1, int n2){
   
    int rv=0;
    int p=1;
    
    while(n2>0){
        int d2=n2%10;
        n2/=10;
        int sp = getProductWithSingleDigit(b,n1,d2);
        
        rv=getSum(b,rv,sp*p);
        p*=10;
    }
    return rv;
}

int main(){
    int b, n1, n2;
    cin>>b>>n1>>n2;
    cout<<getProduct(b,n1,n2)<<endl;
}