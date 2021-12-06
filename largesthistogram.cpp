#include <bits/stdc++.h>
using namespace std;
int main()
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int> rb(n,0);
  vector<int> lb(n,0);
  stack<int> st;
  st.push(n-1);
  rb[n-1]=n;
  for(int i=n-2;i>=0;i--){
      while(st.empty()==false && arr[st.top()]>=arr[i]){
          st.pop();
      }
      
      if(st.empty()==true){
          rb[i]=n;
      }else{
          rb[i]=st.top();
      }
      
      st.push(i);
  }
  
  stack<int> st1;
  st1.push(0);
  lb[0]=-1;
  for(int i=1;i<n;i++){
      while(st1.empty()==false && arr[st1.top()]>=arr[i]){
          st1.pop();
      }
      
      if(st1.empty()==true){
          lb[i]=-1;
      }else{
          lb[i]=st1.top();
      }
      
      st1.push(i);
  }
  
  int maxarea=0;
  for(int i=0;i<n;i++){
      int width=rb[i]-lb[i]-1;
      int area=width*arr[i];
      maxarea=max(maxarea,area);
  }
  
  cout<<maxarea<<endl;
  return 0;
}