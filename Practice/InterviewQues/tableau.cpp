1--2--2--3--4--3--5

2--2--3--3


LinkedList<Integer> removeUniqueElements (LinkedList<Integer> input)
{
    
    

}



//Psuedo

linkedList newList = new LinkedList();

Node* y = head;

while (y != NULL)
{   
   int count = 0;
   checkValue = y -> value;
   Node* x = head;  // intialize pointer to start of list
   
  while(x != NULL)
 {   
    if(x->value == checkValue)
    {  
        count++;  
    }
   
      x = x.next;
 }

 if(count > 1)
 {
     // count greater than 1 than not unique
     newList.add();
     
 }
 
    y = y -> next;
 
}

 