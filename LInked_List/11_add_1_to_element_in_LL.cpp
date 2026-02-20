// given a Linked list
// every node represents a digit
// the whole list represents a number
// say 1 -> 5 -> 9 represents 159
// if we add here, result is 160
// ll becomes 1 -> 6 -> 0
// if we have 9999, then if we add 1 then it becomes 10000 that means we will have to add a new node as the new head of the linked list

// so, we will start with the last node, then traverse back ward adding 1 and carrying the carry
// but since there is no backward link, we cannot traverse directly
// hence, we can simply reverse the linked list
// after reversing, start from the head
// and start with the carry as 1
// now keep moving and adding 1 the carry
// if carry becomes 0, break out then n there
// again reverse the list and return the head

// if a number is like 9999, then
// reverse it
// start the same process
// if temp has reached NULL but there is still a carry = 1 left, then we have to make a new node
// but not yet,
// first call the reverse function
// and then create a new node with the carry, and point this node to the head of the linked list
// and then return the new head

fun(head){
    
}