// two sum problem in a bst
// given a bst and a K (integer)

// does there exist couple of integers (2 different integers) that sum up to give the K
// if there does not exist two integers that sum to give K, return falsew

// brute:
// if we write the inorder traversal, it will be sorted
// then we can keep two pointers (one at the start), (one at the end)
// and we can compare whether the two sum is 9 or not
// move pointers accordingly

// optimal:
// we know the BST Iterator where we know how to find the next element
// if we do inorder traversal in the order of right node left, then we will get a sorted traversal in descending order
// if we do the opposite of what we did in 'next' element, we will get 'before' element
// therefore now we have an iterator to give 'next' and 'before'

// put first pointer (ith pointer) at next
// put second pointer (jth pointer) at before
// the first pointer stands at the left most element 
// the second pointer stands at the rightmost element 
// compare both, if the sum < needed, move the first pointer to next
// if sum > needed, move second pointer to before

class BSTIterator{
    stack<TreeNode*> myStack;
    bool reverse = true;

public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }

    bool hasNext(){
        return !myStack.empty();
    }

    int next(){
        TreeNode *tmpNode = myStack.top();
        myStack.pop();
        if(!reverse) pushAll(tmpNode -> right);
        else pushAll(tmpNode -> left);
        return tmpNode -> val;
    }

private:
    void pushAll(TreeNode *node){
        for(; node!= NULL; ){
            myStack.push(node);
            if(reverse == true){
                node = node->right;
            }
            else node= node->left;
        }
    }
};

class Solution{
public:
bool findTarget(TreeNode root, int k){
    if(!root) return false;
    BSTIterator l(root, false);
    BSTIterator r(root, true);

    int i = l.next();
    int j = r.next(); // for before
    while(i < j){
        if(i + j == k) return true;
        else if( i + j < k) i = l.next();
        else j = r.next();
    }
    return false;
}
};