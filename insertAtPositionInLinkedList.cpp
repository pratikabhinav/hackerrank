int getSizeForList(SinglyLinkedListNode* head) {
    int count = 0;
    SinglyLinkedListNode* current = head;

    for (current = head; current != NULL; current = current->next) {
        count++;
    }
    return count;
}

SinglyLinkedListNode* insertNodeAtPosition(SinglyLinkedListNode* head, int data, int position) {
    // create a new node
    SinglyLinkedListNode* newNode = new SinglyLinkedListNode(data);
    newNode->data = data;
    newNode->next = NULL;
    SinglyLinkedListNode* current = head;

    int size = getSizeForList(head);
    if ((position < 0) || (position > size)) {
        return head;
    }

    if (position == 0) {
        newNode->next = head;
        head = newNode;
        return head;
    }

    
    for(int i = 0; i < position - 1; i++) {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;

    return head;
}