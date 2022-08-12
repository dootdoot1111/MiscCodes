int Solution::isPalindrome(int A) {
    
    if(A < 0)
    {
        return 0;
    }
    
    if(A < 10)
    {
        return 1;
    }
    
    int n = A;
    int rev = 0;
    
    while(n > 0)
    {
        int dig = n % 10;
        n /= 10;
        rev *= 10;
        rev += dig;
    }
    
    return rev == A;
    
}
