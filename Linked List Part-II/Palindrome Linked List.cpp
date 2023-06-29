#include <bits/stdc++.h> 
/****************************************************************

    Following is the class structure of the LinkedListNode class:

    template <typename T>
    class LinkedListNode
    {
    public:
        T data;
        LinkedListNode<T> *next;
        LinkedListNode(T data)
        {
            this->data = data;
            this->next = NULL;
        }
    };

*****************************************************************/

LinkedListNode<int> * reverseSecondHalf(LinkedListNode<int> *currNode){
    LinkedListNode<int> *prevNode = NULL;
    LinkedListNode<int> *nextNode = NULL;

    while(currNode != NULL){
        nextNode = currNode->next;
        currNode->next = prevNode;
        prevNode = currNode;
        currNode = nextNode;
    }
    return prevNode;
}

bool isPalindrome(LinkedListNode<int> *head) {
    // Write your code here.
    if(head == NULL || head->next == NULL){
        return true;
    }
    
    LinkedListNode<int> *slow = head;
    LinkedListNode<int> *fast = head;
    
    while(fast->next != NULL && (fast->next)->next != NULL){
        slow = slow->next;
        fast = (fast->next)->next;
    }

    slow->next = reverseSecondHalf(slow->next);
    slow = slow->next;
    fast = head;

    while(slow != NULL){
        if(fast->data != slow->data){
            return false;
        }
        slow = slow->next;
        fast = fast->next;
    }
    return true;
}
