class Solution {
public:
    vector<vector<int>> findSolution(CustomFunction& customfunction, int z)
	{
        vector<vector<int>> result;                  
        // Declare output vector
		
        for(int x=1; x<=1000; x++)                    
            // Iterate for all of the values of x
		{
            for(int y=1; y<=1000; y++)                
                // Iterate for all of the values of y
			{
                if(customfunction.f(x, y) == z)      
                    // Check satisfying condition
				{
                    result.push_back({x,y});          
                    // Store the values of x and y
                }
                else if(customfunction.f(x, y) > z)   
                    // Check breaking condition
				{
					break;                            
                    // Stop iterating further for unnecessary values
				}
            }
        }
        return result;                                
        // Return a list of all the values of x and y
    }
};
