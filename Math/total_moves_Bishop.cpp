int Solution::solve(int A, int B) {
    
    int up = 8-A, down = A-1, left = B-1, right = 8-B;
    
    return(min(up, left) + min(up, right) + min(left, down) + min(right, down));

    // basically add the length of the diagonals (min of sides) for each diagonal direction
}