Input: 3
Output: [1,3,3,1]
Input: 4
Output: [1,4,6,4,1]

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> vi(rowIndex + 1);
       	vi[0] = 1;
        for (int i = 0; i <= rowIndex ; ++i)
        {
        	for (int j = i; j > 0; --j)
        	{
	        	vi[j] = vi[j] + vi[j-1];
        	}
        }
        return vi;
    }
};
