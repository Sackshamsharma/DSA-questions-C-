#include <bits/stdc++.h>
#include <ctype.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  vector<int> arr(n);
  for (int i = 0; i < n; i++) {
    cin >> arr[i];
  }
  int k;
  cin >> k;
  
  stack<int> st;
  int nge[n];
  nge[n-1]=n;
  st.push(n-1);
  
  for(int i=n-2;i>=0;i--){
      while(st.empty()==false && arr[i]>=arr[st.top()]){
          st.pop();
      }
      nge[i]=st.empty()?n:st.top();
      st.push(i);
  }
  
  int j=0;
  for(int i=0;i<=n-k;i++){
      if(j<i)j=i;
      
      while(nge[j]<i+k){
         j=nge[j];
      }
      cout<<arr[j]<<endl;
  }

  // write your code here

  return 0;
}