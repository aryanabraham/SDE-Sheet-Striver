/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
            int data;
            Node *next;
            Node()
            {
                this->data = 0;
                next = NULL;
            }
            Node(int data)
            {
                this->data = data;
                this->next = NULL;
            }
            Node(int data, Node* next)
            {
                this->data = data;
                this->next = next;
            }
        };

*****************************************************************/

Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if(firstHead == NULL || secondHead == NULL){
        return NULL;
    }

    Node *firstPtr = firstHead;
    Node *secondPtr = secondHead;

    while(firstPtr != secondPtr){
        firstPtr = (firstPtr == NULL) ? secondHead : (firstPtr->next);
        secondPtr = (secondPtr == NULL) ? firstHead : (secondPtr->next);
    }

    return firstPtr;
}
