#include<iostream>
using namespace std;

int main() {
  int n1, n2;
  cin >> n1;
  int* a1 = new int[n1];
  for (int i = 0 ; i < n1; i++) {
    cin >> a1[i];
  }

  cin >> n2;
  int* a2 = new int[n2];
  for (int i = 0 ; i < n2; i++) {
    cin >> a2[i];
  }

 
    int diff[n2];
    for(int i=0;i<n2;i++){
        diff[i]=0;
    }
    
    int n= sizeof(diff)/sizeof(diff[diff[0]]);
    // cout<<n<<endl;
    
    int i=n1-1;
    int j=n2-1;
    int k=n-1;
    
    int c=0;
    while(k>=0){
        int d=0;
        int a1v = i>=0?a1[i]:0;
        
        if(a2[j]+c >= a1v){
            d=a2[j]+c-a1v;
            c=0;
        }
        else{
          d =a2[j]+c+10-a1v;
          c=-1;
        }
        
        diff[k]=d;
        // cout<<d<<endl;
        i--;
        j--;
        k--;
        
        
    }
    
    int idx=0;
    while(idx<=n){
        if(diff[idx]==0){
            idx++;
        }
        else{
            break;
        }
    }
    
    while(idx<n){
        cout<<diff[idx]<<endl;
        idx++;
    }
    
}