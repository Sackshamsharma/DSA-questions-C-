vector<int> FindExitPoint(vector<vector<int>>&matrix){
		// Code here
		int n=matrix.size();
		int m=matrix[0].size();
		int dir=0;
		int i=0;
		int j=0;
		while(i>=0 && i<n && j>=0 && j<m){
		    if(matrix[i][j]==1){
		        matrix[i][j]=0;
		        if(dir==0)dir=1;
		        else if(dir==1)dir=2;
		        else if(dir==2)dir=3;
		        else dir=0;
		    }
		    
		    if(dir==0)j++;
		    else if(dir==1)i++;
		    else if(dir==2)j--;
		    else if(dir==3)i--;
		}
		
		if(dir==0){
		    return {i,j-1};
		}
		else if(dir==1){
		    return {i-1,j};
		}
		else if(dir==2){
		    return {i,j+1};
		}
		else if(dir==3){
		    return {i+1,j};
		}
		else {
		    return {0,0};
		}
    }