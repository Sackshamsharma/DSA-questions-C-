#include <bits/stdc++.h>
using namespace std;
void display(vector<int>a) {
  for (int i = 0; i < a.size(); i++)
  {
    cout << a[i] << endl;
  }
}
vector<int> solve(vector<int> arr)
{
int n= arr.size();
  vector<int> res(n,0);
  
  stack<int> st;
  res[n-1]=-1;
  st.push(arr[n-1]);
  for(int i=n-2;i>=0;i--){
      while( st.empty()==false && st.top()<=arr[i]){
          st.pop();
      }
      
      if(st.empty()==true){
          res[i]=-1;
          st.push(arr[i]);
      }
      
      if(st.top()>arr[i]){
          res[i]=st.top();
          
          st.push(arr[i]);
          
      }
      
    
  }
  return res;
}

int main(int argc, char** argv)
{
  int n;
  cin >> n;
  vector<int>arr(n, 0);
  for (int i = 0; i < n; i++)
  {
    cin >> arr[i];
  }
  vector<int>nge(n, 0);
  nge = solve(arr);
  display(nge);
  return 0;
}