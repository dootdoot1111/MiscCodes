int Solution::titleToNumber(string A) {
    
    int n = A.size();
    int column = 0;
    
    for(int i = n-1; i >= 0; i--)
    {
        column += (A[i] - 'A' + 1)*pow(26, n-i-1);
    }
    
    return column;
    
}
