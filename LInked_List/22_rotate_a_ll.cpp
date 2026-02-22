// given a LL and a value k
// rotate the LL by k times
// eg if LL is 1 2 3 4 5
// 1 rotate it to give 5 1 2 3 4
// 1 rotate more to give 4 5 1 2 3
// k can be anything

// recognize the tail node
// if total length is n, and given k, then n-k gives the node that will be the last node in the updated LL
// before pointing n-kth node to null, point n-kth node -> next as head, and then this to null
// then the LL that you have is the exactly that we need
// but what if K > more than the length 
// if k is a multiple of the length of the LL, it is nothing but the original LL, so return head
// if k is any other number, it is nothing but modulo
// if length is 5, k is 13, then 13 is 5 + 5 + 3, on first 10 rotations it gives same LL, so only do 3 rotations

findNthNode(temp, k){
    int cnt = 1;
    while(temp != NULL){
        if(cnt == k) return temp;
        cnt++;
        temp = temp -> next;
    }
    return temp;
}

len = 1; tail = head;
while(tail->next != nullptr){
    len++;
    tail = tail->next;
}
if( k % len == 0) return head;
k = k % len;

tail-> next = head;
newLastNode = findNthNode(head, len - k);
head = newLastNode -> next;
newLastNode -> next = nullptr;
return head;