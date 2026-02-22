// merge k sorted lists
// given k sorted lists, take all the integers together and sort and put them into a new LL

// brute:
// take all the elements from all the lists, and put them into an arrray
// sort the array
// make a linkedlist out of it

// better: 
// we can merge first 2 lists
// then merge that with 3rd list
// that with 4th and so on
// return the head at the end

f(list<node> lists){
    head = lists[0];
    for(i = 1 to lists.size()){
        head = merge2lists(head, lists[i]);
    }
    
    return head;
}

// the time complexity of this if there are lists with length N1 N2 N3 N4... is:
// N x (k x k + 1)/2 where N = N1+N2+N3...
// space is nothing extra
// this TC is near about N^3 

// optimal:
// using a min heap
// -> which is a DS that returns minimum value
// PQ is the DS that implements min heap in C++

// so define a Pritority Queue PQ, storing two values int,Node
// take all the heads and store it in the priority queue initially
// now initialize a dummy node -1
// now the first node in the answer will be one amongst all heads that we have stored
// so take the first value from the priority queue and point dummyNode to it
// when we take out a node from the PQ, simply insert the next value in the list to the PQ
// by this way we will have all values in the PQ, keep picking out from PQ and inserting it in the list
// keep on doing this until PQ exhausts and then dummyNode -> next is the new head yayayyaya

func(list<Node> lists){
    pq; // define the priority queue
    for(i = 0 to lists.size()){
        pq.add({lists[i].val, lists[i]}); // inserting all heads
    }
    dNode = new Node(-1);
    temp = dNode;
    while(!pq.empty()){
        pair<int,Node> p = pq.top();
        temp->next = p.second;
        pq.pop();
        if(p.second->next){
            pq.add({p.second->next->val, p.second->next});
        }
        temp = temp->next;
    }

    return dNode->next;
}

// now what is the tc of this
// K*logK + N*K*logK
// Space is O(K)