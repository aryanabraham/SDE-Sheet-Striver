{
    //    Write your code here.
    if(head == NULL || head->next == NULL) return NULL;

    Node *slow = head;
    Node *fast = head;

    while(fast != NULL && fast->next != NULL){
        slow = (slow->next);
        fast = (fast->next)->next;

        if(slow == fast){
            Node *entry = head;

            while(entry != slow){
                slow = (slow->next);
                entry = (entry->next);
            }
            return entry;
        }
    }
    return NULL;
}
