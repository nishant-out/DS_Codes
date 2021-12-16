#include <stdio.h>
#include <stdlib.h>

typedef struct node {

	int data ;
	struct node *next ;
}	Node ;

void display( Node* head ){

	while( head != NULL ){
		
		printf( "%d ", head-> data ) ;
		head = head-> next ;
	}
	printf( "\n" ) ;
}

Node* create( int val ){

	Node* temp = (Node*) malloc( sizeof( Node ) ) ;
	temp-> next = NULL ;
	temp-> data = val ;

	return temp ;
}

Node* add_End ( Node* head, int val ){

	//	create a new node
	Node* temp = create( val ) ;
	
	//	If List is Empty
	if( head == NULL ){
		return temp ;
	}
	
	//	Saving pointer to 1st node
	Node* ret = head ;
	
	//	point head at last position to add node
	while( head-> next != NULL ){
		head = head-> next ;
	}
	head-> next = temp ;
	
	return ret ;
}

Node* del_Beg( Node* head ){
    if( head == NULL )
        return head ;
        
    Node* tmp = head ;
    head = head-> next ;
    
    free( tmp ) ;
    
    return head ;
}

Node* add_Beg( Node* head, int val ){

	//	create a new node
	Node* temp = create( val ) ;

    if( head == NULL )
        return temp ;

	//	Point new node's next to current head
	temp-> next = head ;
	head = temp ;
	
	//	return new head
	return head ;
}

Node* Insert( Node* head, int val ){
    if( head == NULL ){  //  no node
        head = add_Beg( head, val ) ;
        return head ;
    }
    
    if( head-> data > val ){
        head = add_Beg( head, val ) ;
    }
    else{
        int tmp = head-> data ;
        head = del_Beg( head ) ;
        head = Insert( head, val ) ;
        head = add_Beg( head, tmp ) ;
    }
    return head ;
}

Node* sort( Node* head, Node* nh ){
    
    if( head == NULL ){  //  no node
        return head ;
    }
    nh = sort( head-> next, nh ) ;
    
    nh = Insert( nh, head-> data ) ;
   
    return nh ;
}

int main(){

	Node *list1 = NULL ;
	Node *list2 = NULL ;
	
	printf( "\nList1: " ) ;
	list1 = add_End( list1, 3 ) ;
	list1 = add_End( list1, 13 ) ;
	list1 = add_End( list1, 33 ) ;
	
	display( list1 ) ;
	
	list1 = sort( list1, NULL ) ;
	
// 	printf( "List2: " ) ;
// 	list2 = add_End( list2, 63 ) ;
// 	list2 = add_End( list2, 73 ) ;
// 	list2 = add_End( list2, 83 ) ;
	printf( "\nList1 Sorted: " ) ;
	display( list1 ) ;

	return 0 ;
}
