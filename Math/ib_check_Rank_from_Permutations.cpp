int Solution::findRank(string A) {
    
    int n = A.size();
    long rank = 1;

    vector<int> factorial(n);
    factorial[0] = 1;
    vector<int> letters(256);
    letters[A[0]] = 1;
    
    for(int i = 1; i < n; i++)
    {
        factorial[i] = factorial[i-1]*i;
        letters[A[i]] = 1;
    }
    
    for(int i = 0; i < n; i++)
    {
        int numSmaller = 0;
        for(int j = 0; j < A[i]; j++)
        {
            if(letters[j])
            {
                numSmaller++;
            }
        }
        letters[A[i]] = 0;
        rank += numSmaller*factorial[n-i-1];
    }
    
    return (rank % 1000003);
    
}
