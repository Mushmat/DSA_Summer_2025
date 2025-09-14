// given a postorder and inorder traversal, we need to generate a binary tree and this will be unique
// postorder: left right root

// say inorder is 40 20 50 10 60 30
// say postorder is 40 50 20 60 30 10

// since postorder is left right root, the last element in the post order is the root of the tree
// here, 10 is the root of the tree since 10 is the last element in postorder
// since 10 is the root, in the inorder traversal, left elements to 10 will constitute the left subtree and right will constitute the right subtree
// therefore 40 20 50 is on the left of 10
// 60 30 is on the right
// now again, for left subtree inorder is 40 20 50, and postorder is 40 50 20, which means 20 is their root now
// smrly 60 30 is inorder and 60 30 is postorder for the right subtree which means 30 is the root
// this question is very similar to the question where preorder and inorder is given, it is just that the root is different here
