// given a doubly linked list (the head of it)
// reverse the DLL and return the new head

// brute force is to reverse the data itself, instead of changing the nodes. 
// take a stack data structure and push the data in it from head to tail
// after that, come back to the head, and change the value of the nodes with the value in the stack
// This solution takes O(2N) time, and it will take O(N) space

// better solution?
// we need to swap the links between the nodes in a single traversal
// we have two pointers next and back
// if for a node, its next pointed to 3 and back to 4, after reversal, its next will point to 4 and back to 3
// so we just need to swap the next and back
// a swap function can swap it
// like we swap two variables

// so, just keep the last node for any current node, last = current -> back
// current->back = current->next (swapped)
// current->next = last (swapped)
// these lines will swap the links,
// now we need to do this on every node
// to move current to next node, do not go to current = current -> next as pointers are swapped. go to current -> back
// after finishing, the current is at nullptr. so just loop our conditions over while(current != NULL)
// return last->back, because last will be at second last element, and its back will be at the head since swaps have happened

Node* reverseDLL(Node* head){
    if(head == NULL || head->next == NULL) return head;

    Node* prev = NULL;
    Node* curr = head;
    while(curr != NULL){
        prev = curr -> prev;
        curr -> prev = curr -> next;
        curr -> next = prev;
        curr = curr -> prev;
    }
    return prev -> prev;
}
// O(N) and space O(1)
