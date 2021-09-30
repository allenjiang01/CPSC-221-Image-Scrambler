#include "chain.h"
#include <cmath>
#include <iostream>


// PA1 functions

/**
 * Destroys the current Chain. This function should ensure that
 * memory does not leak on destruction of a chain.
 */
Chain::~Chain() {
  clear();
}

/**
 * Inserts a new node after the node pointed to by p in the
 * chain (so p->next is the new node) and returns a pointer to
 * the newly created node.
 * If p is NULL, inserts a new head node to the chain.
 * This function **SHOULD** create a new Node and increase length_.
 *
 * @param p = The new node should be pointed to by p->next.
 *            If p is NULL, the new node becomes the head of the chain.
 * @param ndata = The data to be inserted.
 */
Chain::Node * Chain::insertAfter(Node * p, const Block &ndata) {
  
  
    Node* newNode = new Node(ndata);
    
    if (p == NULL) {
      newNode->next = head_;
      if (head_ != NULL) {
        head_->prev = newNode;
      }
      head_ = newNode;
    } else {
      if (p->next != NULL) {
        newNode->next = p->next;
        p->next->prev = newNode;
        newNode->prev = p;
        p->next = newNode;
      } else {
        newNode->prev = p;
        p->next = newNode;
        newNode->next = NULL;
      }
    }
    length_++;
    return newNode;
}



/**
 * Swaps the position in the chain of the two nodes pointed to
 * by p and q.
 * If p or q is NULL or p==q, do nothing.
 * Change the chain's head pointer if necessary.
 */
void Chain::swap(Node *p, Node *q) {
  if (p == NULL || q == NULL || p == q) {
    return;
  }

  cout << "67 swap" << endl;
  
  bool headIsQ = false;
  if (q == head_) {
    headIsQ = true; 
  }
  cout << "73 swap" << endl;
  bool headisP = false;
  if (p == head_) {
    headisP = true; 
  }
  cout << "78 swap" << endl;
  
  if (p->next != q && q->next != p) {
    Node *pprev = p->prev;
    Node *pnext = p->next;
    Node *qprev = q->prev;
    Node *qnext = q->next;
  
    
    cout << "85 swap" << endl;

    if (pprev == NULL) {
      cout << "88 swap" << endl;
      q->prev = NULL;
      cout << "89 swap" << endl;
      head_ = q;
      cout << "92 swap" << endl;
    } else {
      pprev->next = q;
      q->prev = pprev;
    }
    if (pnext == NULL) {
      q->next = NULL;
    } else {
      pnext->prev = q;
      q->next = pnext;
    }
    if (qprev == NULL) {
      p->prev = NULL;
      head_ = p;
    } else {
      qprev->next = p;
      p->prev = qprev;
    }
    if (qnext == NULL) {
      p->next = NULL;
    } else {
      qnext->prev = p;
      p->next = qnext;
    }
  } else {
    if (q->next == p) {
      Node* node1 = p;
      p = q;
      q = node1;
    }
    Node *pprev = p->prev;
    Node *qnext = q->next;
    p->prev = q;
    q->next = p;
    if (pprev == NULL) {
      q->prev = NULL;
      cout << "130" << endl;
       head_ = q;
    } else {
      cout << "133" << endl;
      pprev->next = q;
      q->prev = pprev;
    }
    if (qnext == NULL) {
      p->next = NULL;
      cout << "137" << endl;
    } else {
      cout << "139" << endl;
      qnext->prev = p;
      p->next = qnext;
    }
  }
    if (headIsQ) {
    head_ = p;
  }

  if (headisP) {
    head_ = q;
  }
}





//   if (p == NULL || q == NULL || p == q) {
//     return;
//   }

//   Node *nextNode = NULL;
//   Node *prevNode = NULL;




//     // p q _ _ _ 
//   if (p->prev == NULL && p->next == q && q->next != NULL) {
//     p->next = q->next;
//     q->next->prev = p;
//     q->next = p;
//     q->prev = NULL;
//     p->prev = q;

//     head_ = q;
//     return;
//   }

//   // q p _ _ _
//   if (q->prev == NULL && q->next == p && p->next != NULL) {
//     q->next = p->next;
//     p->next->prev = q;
//     p->next = q;
//     p->prev = NULL;
//     q->prev = p;

//     head_ = p;
//     return;
//   }

//     // _ p q _ _
//   if (p->next == q && q->prev == p && p->prev != NULL && q->next != NULL) {
//     p->prev->next = q;
//     q->next->prev = p;
//     Node *node1 = q->next;
//     Node *node2 = p->prev;
//     q->next = p;
//     p->prev = q;
//     p->next = node1;
//     q->prev = node2;
//     return;
//   }

//   // _ q p _ _
//   if (q->next == p && p->prev == q && q->prev != NULL && p->next != NULL) {
//     q->prev->next = p;
//     p->next->prev = q;
//     Node *node1 = p->next;
//     Node *node2 = q->prev;
//     p->next = q;
//     q->prev = p;
//     q->next = node1;
//     p->prev = node2;
//     return;
//   }

//     // _ _ _ p q
//   if (q->next == NULL && p->next == q && p->prev != NULL) {
//     p->prev->next = q;
//     q->prev = p->prev;
//     p->next = NULL;
//     q->next = p;
//     p->prev = q;

//     return;
//   }
//   // _ _ _ q p
//   if (p->next == NULL && q->next == p && q->prev != NULL) {
//     q->prev->next = p;
//     p->prev = q->prev;
//     q->next = NULL;
//     p->next = q;
//     q->prev = p;
//     return;
//   }

//   // p _ _ q _
//   if (p->prev == NULL && p->next != q && q->prev != p && q->next != NULL) {
//     Node *pnext = p->next;
//     Node *qprev = q->prev;
//     Node *qnext = q->next;

//     q->prev = NULL;
//     q->next = pnext;
//     pnext->prev = q;
//     p->next = qnext;
//     qnext->prev = p;
//     qprev->next = p;
//     p->prev = qprev;

//     head_ = q;
//     return;
//   }

//   // q _ _ p _
//   if (q->prev == NULL && q->next != p && p->prev != q && p->next != NULL) {
//     Node *pnext = p->next;
//     Node *pprev = p->prev;
//     Node *qnext = q->next;

//     p->prev = NULL;
//     p->next = qnext;
//     qnext->prev = p;
//     q->next = pnext;
//     pnext->prev = q;
//     pprev->next = q;
//     q->prev = pprev;

//     head_ = p;
//     return;
//   }

//   // _ p _ _ q
//   if (q->next == NULL && p->next != NULL && p->next != q && p->prev != NULL) {
//     Node *qprev = q->prev;
//     Node *pprev = p->prev;
//     Node *pnext = p->next;

//     p->next = NULL;
//     p->prev = qprev;
//     pnext->prev = q;
//     q->next = pnext;
//     qprev->next = p;
//     pprev->next = q;
//     q->prev = pprev;

//     return;
//   }

//   // _ q _ _ p
//   if (p->next == NULL && q->next != NULL && q->next != p && q->prev != NULL) {
//     Node *pprev = p->prev;
//     Node *qprev = q->prev;
//     Node *qnext = q->next;

//     q->next = NULL;
//     q->prev = pprev;
//     qnext->prev = p;
//     p->next = qnext;
//     pprev->next = q;
//     qprev->next = p;
//     p->prev = qprev;

//     return;
//   }

//   // p _ q _ _
//   if (p->prev == NULL && p->next!= NULL && p->next != q && q->next != NULL) {
//     nextNode = p->next;
//     q->next->prev = p;
//     p->prev = q->prev;
//     q->prev = NULL;
//     nextNode->next = p;
//     nextNode->prev = q;
//     p->next = q->next; 
//     q->next = nextNode;
//     head_ = q;
//     return;
//   }

//     // q _ p _ _
//   if (q->prev == NULL && q->next!= NULL && q->next != p && p->next != NULL) {
//     nextNode = q->next;
//     p->next->prev = q;
//     q->prev = p->prev;
//     p->prev = NULL;
//     nextNode->next = q;
//     nextNode->prev = p;
//     q->next = p->next; 
//     p->next = nextNode;
//     head_ = p;
//     return;
//   }

//   // _ _ p _ q
//   if (q->next == NULL && p->next != NULL && p->prev != NULL && q->prev != NULL) {
//     nextNode = p->next;
//     p->prev->next = q;
//     q->prev = p->prev;
//     nextNode->prev = q;
//     nextNode->next = p;
//     p->next = NULL;
//     q->next = nextNode;
//     p->prev = nextNode;

//     return;
//   }
//   // _ _ q _ p
//   if (p->next == NULL && q->next != NULL && q->prev != NULL && p->prev != NULL) {
//     nextNode = q->next;
//     q->prev->next = p;
//     p->prev = q->prev;
//     nextNode->prev = p;
//     nextNode->next = q;
//     q->next = NULL;
//     p->next = nextNode;
//     q->prev = nextNode;
//     return;
//   }
//   // p _ _ _ q
//   if (q->next == NULL && p->prev == NULL && q->prev != NULL && p->next != NULL) {
//     p->next->prev = q;
//     q->prev->next = p;
//     p->prev = q->prev;
//     q->next = p->next;
//     p->next = NULL;
//     q->prev = NULL;
//     head_ = q;
//     return;
//   }

//   // q _ _ _ p
//   if (p->next == NULL && q->prev == NULL && p->prev != NULL && q->next != NULL) {
//     q->next->prev = p;
//     p->prev->next = q;
//     q->prev = p->prev;
//     p->next = q->next;
//     q->next = NULL;
//     p->prev = NULL;
//     head_ = p;
//     return;
//   }

//   // _ p _ q _
//   if (p->next->next == q && p->prev != NULL && q->next != NULL) {
//     Node *node1 = p->prev;
//     Node *node2 = q->prev;
//     Node *node3 = q->next;
//     node1->next = q;
//     node3->prev = p;
//     p->next = node3;
//     q->prev = node1;
//     p->prev = node2;
//     q->next = node2;
//     node2->prev = q;
//     node2->next = p;
//     return;
//   }

//   // _ p _ _ q _
  
//     Node *pprev = p->prev;
//     Node *pnext = p->next;
//     Node *qprev = q->prev;
//     Node *qnext = q->next;

//     pprev->next = q;
//     q->prev = pprev;
//     pnext->prev = q;
//     q->next = pnext;
//     qnext->prev = p;
//     p->next = qnext;
//     qprev->next = p;
//     p->prev = qprev;
//     cout << "322 swap" << endl;
//     return;
  
// }

/**
 * Destroys all dynamically allocated memory associated with the
 * current Chain class.
 */
void Chain::clear() {
  if (head_ == NULL) {
    delete head_;
    return;
  }
  if (head_->next == NULL) {
    delete head_;
    head_ = NULL;
    
    return;
  }
  Node *curr = head_;
  while (curr != NULL) {
    Node *tmp = curr->next;
    delete curr;
    curr = tmp;
  }
  head_ = NULL;
  length_ = 0;
}


/**
 * Makes the current object into a copy of the parameter:
 * All member variables should have the same value as
 * those of other, but the memory should be completely
 * independent. This function is used in both the copy
 * constructor and the assignment operator for Chains.
 */
void Chain::copy(Chain const &other) {
   clear();
   if (other.empty()) {
     return;
   }

   Node *curr = NULL;
   for (Node *p = other.head_; p != NULL; p = p->next) {
     curr = insertAfter (curr, p->data);
   }
   
}

/* Modifies the current chain: 
 * 1) Find the node with the first (leftmost) block in the unscrambled
 *    image and move it to the head of the chain.
 *	This block is the one whose closest match (to the left) is the
 *	largest.  That is, the distance (using distanceTo) to this block 
 *	is big for all other blocks.
 *	For each block B, find the distanceTo B from every other block
 *	and take the minimum of these distances as B's "value".
 *	Choose the block B with the maximum value over all blocks and
 *	swap its node to the head of the chain.
 *
 * 2) Starting with the (just found) first block B, find the node with
 *    the block that is the closest match to follow B (to the right)
 *    among the remaining blocks, move (swap) it to follow B's node,
 *    then repeat to unscramble the chain/image.
 */
 void Chain::unscramble() {
  Node *currNode = head_;
  Node *largestNode;
  double highScore;
cout << "482 unscramble" << endl;
  for (int i = 1; i<=length_; i++) {
    cout << "484 unscramble" << endl;
    double lowScore = score(currNode);
    if (lowScore >= highScore) {
      cout << "487 unscramble" << endl;
      highScore = lowScore;
      largestNode = currNode;
    }
      currNode = currNode->next;
  }
  cout << "493 unscramble" << endl;
  swap(head_,largestNode);
  cout << "496 unscramble" << endl;
  currNode = head_;
  while (currNode->next != NULL) {
    cout << "497 unscramble" << endl;
    makeNextBlock(currNode);
    cout << "499 unscramble" << endl;
    currNode = currNode->next;
  }
}

void Chain::makeNextBlock(Node *current) {
  Node *node1 = current->next;
  double lowScore = 1.0;
  Node *node2;
  while (node1 != NULL) {
    double score = current->data.distanceTo(node1->data);
    if (score < lowScore) {
      lowScore = score;
      node2 = node1;
    }
    node1 = node1->next;
  }
  swap(current->next, node2);
}

double Chain::score(Node *current) {
  Node *node1 = head_;
  double lowScore = 1.0;
  while (node1 != NULL) {
    if (node1 != current) {
      double score = node1->data.distanceTo(current->data);
      if (score < lowScore) {
        lowScore = score;
      }
    }
    node1 = node1->next;

  }
  return lowScore;
 }
