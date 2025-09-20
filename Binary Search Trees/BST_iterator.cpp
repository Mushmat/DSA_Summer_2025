// design a bst iterator
// given some steps, perform it
// first step will give us the root of the BST
// next steps can be: next, hasnext
// keep the inorder traversal 
// keep a pointer to the start of the inorder traversal (start as in, before the first element)
// when 'next' comes, it means move the pointer to the next element and return that
// when 'hasnext' comes, it means is there a next element present or not

// we need a constructor that will be given the BSTIerator with the root
// take a stack DS
// put the root in it
// go to the left, put it
// go to the left, put it
// repeat till you reach the left most node

// if the step is 'next', take the first node out and then go to the node's right, and put everything into the stack
// when at node's right, now again go to left left left and keep pushing in stack
// if node's right is null, take the next node out
// if stack empty and 'hasnext' comes, return false

// SC: O(H) and TC on average is O(1)

stack <TreeNode*> myStack;

BSTIterator(TreeNode* root){
    pushAll(root); //pushes all lefts to the stack
}

bool hasNext(){
    return !myStack.empty(); //returns false if stack is empty
} 

int next(){
    TreeNode *tmpNode = myStack.top(); // the first guy in the stack is the next guy
    myStack.pop();
    pushAll(tmpNode->right); //if there is a right, push all the left again in stack
    return tmpNode->val;
}

void pushAll(TreeNode * node){
    for(; node!= NULL; myStack.push(node), node = node->left);
}