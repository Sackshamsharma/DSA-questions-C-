int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> st;
        for(int i=0;i<n;i++){
            st.push(i);
        }
        
        while(st.size()>=2){
            int e2=st.top();
            st.pop();
            int e1=st.top();
            st.pop();
            if(M[e1][e2]==1){
                st.push(e2);
            }
            else{
                st.push(e1);
            }
        }
        
        int pot=st.top();
        st.pop();
        
        for(int i=0;i<n;i++){
            if(i!=pot){
                if(M[pot][i]==1 || M[i][pot]==0)return -1;
            }
        }
        
        return pot;
    }

    