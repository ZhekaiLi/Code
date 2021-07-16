/*
tansform 
(0, 0) (0, 1) (0, 2) (0, 3)
(1, 0) (1, 1) (1, 2) (1, 3)
(2, 0) (2, 1) (2, 2) (2, 3)
into
(0, 0) (0, 1) (1, 0) (2, 0) (1, 1) (0, 2) (0, 3) (1, 2) (2, 1) (2, 2) (1, 3) (3, 3)
*/


vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        if(matrix.empty()) return {}; //very important to return a empty vector if input is empty
        
        const int N = matrix.size();
        const int M = matrix[0].size(); //or this step and others will cast errors
        
        vector<int> res;
        for(int s = 0; s <= N + M - 2; ++s)
        {
            // for all i + j = s
            for(int x = 0; x <= s; ++x) 
            {
                int i = x;
                int j = s - i;
                if(s % 2 == 0) swap(i, j);

                if(i >= N || j >= M) continue;
                
                res.push_back(matrix[i][j]);
            }
        }
        
        return res;
    }
