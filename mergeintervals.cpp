#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;

//using Stack
void mergeOverlappingIntervals(vector<vector<int>>& intervals) {
    
    
    sort(intervals.begin(),intervals.end());            
    stack<vector<int>> st;
    st.push(intervals[0]);
    
     vector<int> temp=st.top();
     

    for(int i=1;i<intervals.size();i++){
        
        if(intervals[i][0]<=temp[1]){
temp[1]=max(temp[1],intervals[i][1]); 
        st.top()[1]=temp[1];
        
        }
        
        else{
            st.push(intervals[i]);
            temp=st.top();
        }
    }
    
    stack<vector<int>> ans;
    while(st.empty()==false){
        ans.push(st.top());
        st.pop();
    }
    
    while(ans.empty()==false){
        cout<<ans.top()[0]<<" "<<ans.top()[1]<<endl;
        
        ans.pop();
    }
}


//using vectors only
void mergeOverlappingIntervals(vector<vector<int>>& intervals) {

 sort(intervals.begin(),intervals.end());
        
        vector<int> tempinterval=intervals[0];
       vector< vector<int>> ans;
        for(auto it:intervals){
            if(it[0]<=tempinterval[1]){
                tempinterval[1]=max(tempinterval[1],it[1]);
            }
            else{
                ans.push_back(tempinterval);
                tempinterval=it;
            }
        }
        ans.push_back(tempinterval);
        
        for(auto it:ans){
            cout<<it[0]<<" "<<it[1]<<endl;
        }

}


int main() {
  int n;
  cin >> n ;

  vector<vector<int>> arr( n, vector<int>(2) );



  // input
  for (int i = 0; i < n ; i++ ) {
    cin >> arr[i][0];
    cin >> arr[i][1];
  }


  mergeOverlappingIntervals(arr);

}
