// let us find out the right side

// from the right side, only the right most nodes will be visible
// the last node of every level will come in the right view
// therefore last node of every level is the answer
// similarly, the first node of every level is the left view (or you can traverse the levels from right to left, and then say last node is ans)

// let us try a recursive solution also
// the code is very short when we use recursive code
// lets use reverse preorder traversal
// preorder traversal is root left right
// we do root right left
// first node we get in every right is the right view node at that level

// keep a ds empty
// level is 0 initially, and node is root initially
f(node, level){
    if(node == NULL) return;
    if(level == ds.size()) ds.add(node);
    f(node-> right, level+1);
    f(node -> left, level+1);
}
// to get left view, just exchange the last two f calls. call node -> left first
