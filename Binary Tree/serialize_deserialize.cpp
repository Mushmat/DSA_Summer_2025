// serialize and deserialize a binary tree
// function 1: serialize
// function 2: deserialize
// given a root of a binary tree, the serialize function should return a string. 
// give the string to the deserialize function, should return the root of the binary tree

// any logic can be used to solve this problem
// lets solve it using level order traversal

// to serialize:
// do the level order traversal to get the traversal
// put # (indicating NULL) whenever a node is missing
// Nulls (#shes) cannot have children, but leaf nodes do have NULL as children, so have #shes there also
// Eg one level order traversal can be 1,2,13,#,#,4,5,#,#,#,#
// this string is passed to deserialize now

// to deserialize:
// pick the first guy, put it in the queue, and create a root with this guy
// iterate on the queue, get the first guy. its left will be next guy, put it, insert in queue
// its right will be next guy, put it, insert in queue
// whenever hash comes, dont put in the queue and move the position
// queue's element's left and right guys are determined by the string we have passed by iteration

string serialize(TreeNode* root){
    if(!root) return "";

    string s = "";
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        TreeNode* curNode = q.front();
        q.pop();
        if(curNode == NULL) s.append("#,");
        else s.append(to_string(curNode->val)+',');
        if(curNode != NULL){
            q.push(curNode->left);
            q.push(curNode->right);
        }
    }
    return s;
}

TreeNode* deserialize(string data){
    if(data.size() == 0) return NULL;

    stringstream s(data);
    string str;
    getline(s,str,','); // Goes to each object before comma, considers all elements as objects separated by comma
    TreeNode* root = new TreeNode(stoi(str));
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){

        TreeNode *node = q.front();
        q.pop();

        getline(s,str,",");
        if(str == "#"){
            node->left = NULL;
        }
        else{
            TreeNode* leftNode = new TreeNode(stoi(str));
            node->left = leftNode;
            q.push(leftNode);
        }

        getline(s,str,",");
        if(str == "#"){
            node->right = NULL;
        }
        else{
            TreeNode* rightNode = new TreeNode(stoi(str));
            node->left = rightNode;
            q.push(rightNode);
        }
    }
    return root;

}