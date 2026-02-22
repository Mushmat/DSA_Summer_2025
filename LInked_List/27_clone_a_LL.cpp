// copy list with random pointers
// given a LL
// a node in a LL, here, points to next, but there is one more pointer which is a random pointer
// this random pointer can point to any node, even it can point to null. its all random
// task is to create a copy list, with everything similar, all pointers similar etc
// create the replica
// return the head of the replicated linked list

// first step:
// create each node with the values
// take a temp at the head, keep a hash map to remember the address of the created node <original Node, copy Node>
// create the copy of the node, only the node, not the next not the random
// if node is 7, then in map add 7, 7
// move temp and rememebr all the data
// next step is to point next and random to the correct nodes
// again take temp at the head
// point copies to node to whatever they point in original solution

f(head){
    temp = head;
    map<Node, Node> mpp;
    while(temp != NULL){
        Node newNode = new Node(temp->val);
        mpp[temp] = newNode;
        temp = temp.next;
    }

    while(temp != NULL){
        copyNode = mpp[temp];
        copyNode->next = mpp[temp->next];
        copyNode->random = mpp[temp->random];
        temp = temp->next;
    }

    return mpp[head];
}

// better solution:
// we do not want to use hash map here
// instead of storing the copy nodes in a hash map, we will try to insert them in between
// say if ll is 7 13 11 10 1
// we will make a node 7 and insert it between 7 and 13 to make 7 7 13 11 10 1
// and then just point random and next pointers

temp = head;
while(temp != NULL){
    copyNode = new Node(temp->val);
    copyNode->next = temp.next;
    temp->next = copyNode;
    temp = temp->next->next;
}

temp = head;
while(temp != NULL){
    copyNode = temp.next;
    if(temp.random) copyNode->random = temp->random->next;
    else copyNode->random = nullptr;
    temp = temp.next.next;
}

dNode = new Node(-1);
res = dNode;
temp = head;
while(temp != NULL){
    res.next = temp.next;
    temp.next = temp.next.next;
    res = res.next;
    temp = temp.next;
}

return dNode -> next;