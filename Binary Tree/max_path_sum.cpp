// find max path sum in any given binary tree
// in a path, a single node will only appear once
// brute force is to try out every possible combination of node, but its high time complexity

// for any given node, the max path sum is (the value of that node + max sum to its left + max sum to its right)
// if we find this value for every node

maxi = 0
int maxPath(node, maxi){
    if(node == null){ return 0};

    leftsum = maxPath(node -> left)
    rightsum = maxPath(node -> right)
    maxi = max(maxi, leftsum + rightsum + node->val)
    return (node-> val + max(leftsum, rightsum)); // we return the max path to return
}

// update maxi whenever a greater value is obtained while calculating maxi