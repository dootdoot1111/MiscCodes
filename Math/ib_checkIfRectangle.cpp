int Solution::solve(int A, int B, int C, int D) {
    
    if(A <= 0 || B <= 0 || C <= 0 || D <= 0)
    {
        return 0;
    }
    
    vector<int> sides = {A, B, C, D};
    set<int> uniq;
    
    for(int i = 0; i < 4; i++)
    {
        if(uniq.count(sides[i]) > 0)
        {
            uniq.erase(sides[i]);
        }
        
        else
        {
            uniq.insert(sides[i]);
        }
    }
    
    return uniq.size() == 0;
    
}