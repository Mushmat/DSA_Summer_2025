// root to node path

// a node value is given, tell the path to the node from the root
// we will use the inorder traversal (left root right)

// keep an empty DS
// when you reach root, since it is not NULL, and not equal to node we want to reach. Store it in the DS
// make the left call, let it come back
// make the right call, let it come back

// first recursion must end before second starts

// go the left, insert that node in the DS now (ds = array)
// return when both left and right return a false (left and right of the left node we are on)
// which means neither on left nor on right we dont have the node
// if both of the left and right say that the node is not there, then on that path we dont have the node
// remove the element from where both left and right said false, because its the wrong path
// only keep those elements in the array who are in the path

// repeat this until we find the node
// return true when the node is found and hence the array is the answer at that moment
// go back to the root and return the array as answer at every time but returning true at every recursion 

// if node found on left recursion, return the ans and dont go to the right recursion

bool getPath(TreeNode * root, vector<int> &arr, int x){
    if(!root) return false;

    arr.push_back(root -> val);

    if(root -> val == x) return true;

    if(getPath(root->left, arr, x) || getPath(root -> right, arr, x)) return true;

    arr.pop_back();
    return false;
}

vector<int> Solution::solve(TreeNode *A, int B){
    vector<int> arr;
    if(A == NULL) return arr;
    getPath(A, arr, B);
    return arr;
}