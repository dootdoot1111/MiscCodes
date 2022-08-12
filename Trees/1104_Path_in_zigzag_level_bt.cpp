  #include<bits/stdc++.h>
  using namespace std;
  vector<int> pathInZigZagTree(int label) {
     vector<int>result;
        
        // depth of the given label
        int depth = log10(label)/log10(2);
        
        // Insert labels in the front of the vector from bottom to top
        while(depth>=0)
        {
            // insert current label in the front of vector 
            result.insert(result.begin(),label);
            
            // next label (parent label of current label) in non zizag tree: label/2
            // in zigzag tree we get label as: 
            // previous depth first element + (previous depth last element - next label in non zigzag tree)
            // previous depth first element : 2^ (depth-1)
            // previous depth last element : 2^ (depth) -1
            // next label in non zigzag tree : label/2
            label = (int)pow(2,depth-1) + (int)pow(2,depth) - 1 - label/2;
            depth--;
        }
        
        return result;
    }