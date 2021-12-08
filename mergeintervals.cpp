#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>

using namespace std;



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