#include<iostream>
using namespace std;

 int AnyToAny(int n, int b1, int b2) {
  
  int p=1;
  int res=0;
  while(n>0){
    int rem=n%b2;
    n/=b2;
    res+=rem*p;
    p=p*b1;
  }
  return res;
}
int main() {
  int n;
  int b1;
  int b2;
  cin >> n;
  cin >> b1;
  cin >> b2;
  int res = AnyToAny(n, b1, 10);
  res = AnyToAny(res, 10, b2);
  cout << res << endl;
}