// rotateLinkedList
// take linkedlist head and place to tail and move all nodes forward
// startList (head) 1 -> 2 -> 3 -> 4
// returnList (head) 2 -> 3 -> 4 -> 1

int main(void)
{
	new LinkedList myList = new LinkedList(); // represents e

	Node* newTail = myList -> head; // save first element address
	Node* x = myList -> next; // transverse pointer

	myList -> head = x; // set x second node as head

	while(x -> next != NULL)  // transverse through list
	{
		x = x -> next; 
	}

	x -> next = newTail; // set oldHead as newTail
}