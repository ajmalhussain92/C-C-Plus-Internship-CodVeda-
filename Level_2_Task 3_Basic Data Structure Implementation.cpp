#include <iostream>
#include <limits>
#define SIZE_S 5
#define SIZE_Q 5
using namespace std;

struct Node {
	int data;
	Node* next;
};

// Implement DS --------------------using both Array & Linked List-------------------------------------

// Stack using array
int stack_arr[SIZE_S], top = -1;

// Stack using list
Node* stack_head = nullptr;
int list_top = -1;


// Queue using array
int queue_arr[SIZE_Q];
int front = -1, rear = -1;

// Queue using list
Node* queue_head = nullptr;
int list_front, list_rear = -1;

void sanitizeInput (int& choice) {      // pass by reference
	if (!cin >> choice) {
		cin.clear ();
		cin.ignore (numeric_limits<streamsize> :: max (), '\n');
	}
};

// DS Functions -------------------------------------------------------------------------

// Stack using Array
void array_push ();
void array_pop ();
void array_stack ();
// Stack using List
void list_push ();
void list_pop ();
void list_stack ();

// Queue using Array
void array_enqueue ();
void array_dequeue ();
void array_queue ();
// Queue using List
void list_enqueue ();
void list_dequeue ();
void list_queue ();

int main () {
	cout << "-------------------------------------------------------------\n";
	cout << "\t Basic Data Structure Implementation";
	cout << "\n-------------------------------------------------------------\n";


	int choice = 0;
	while (choice != 3) {
		cout << "\n\t1. Stack\n\t2. Queue\n\t3. Exit program\n\n";

		cout << "Enter your choice: ";
		cin >> choice;
		sanitizeInput (choice);

		if (choice == 1) {
			cout << "Implement the Stack using:\n\n\t1. Array\n\t2. Linked List\n\n";

			cout << "Enter your choice: ";
			cin >> choice;

			if (choice == 1) {
				cout << "Stack implemented using Array.\n";

				choice = 0;
				while (choice != 4) {
					cout << "\n-------------------------Stack Operations-------------------\n";
					cout << "\n\t1. Push\n\t2. Pop\n\t3. Display Stack\n\t4. Exit\n\n";
					cout << "Enter your choice: ";
					cin >> choice;
					sanitizeInput (choice);

					switch (choice) {
					case 1:
						cout << "Push operation:\n";
						array_push ();
						break;

					case 2:
						cout << "Pop operation:\n";
						array_pop ();
						break;

					case 3:
						cout << "Display Stack:\n";
						array_stack ();
						break;

					case 4:
						cout << "Stack program exit.\n";
						break;

					default:
						cout << "Invalid choice! Please enter a number between 1 and 4.\n";
					}
				}
			}
			else if (choice == 2) {
				cout << "Stack implemented using Linked List.\n";

				choice = 0;
				while (choice != 4) {
					cout << "\n-------------------------Stack Operations-------------------\n";
					cout << "\n\t1. Push\n\t2. Pop\n\t3. Display Stack\n\t4. Exit\n\n";
					cout << "Enter your choice: ";
					cin >> choice;
					sanitizeInput (choice);

					switch (choice) {
					case 1:
						cout << "Push operation:\n";
						list_push ();
						break;

					case 2:
						cout << "Pop operation:\n";
						list_pop ();
						break;

					case 3:
						cout << "Display Stack:\n";
						list_stack ();
						break;

					case 4:
						cout << "Stack program exit.\n";
						break;

					default:
						cout << "Invalid choice! Please enter a number between 1 and 4.\n";
					}
				}
			}
			else {
				cout << "Invalid choice! Please enter a number between 1 and 2\n";
			}
		}

		else if (choice == 2) {
			cout << "Implement the Queue using:\n\n\t1. Array\n\t2. Linked List\n\n";

			cout << "Enter your choice: ";
			cin >> choice;
			sanitizeInput (choice);

			if (choice == 1) {
				cout << "Queue implemented using Array.\n";

				choice = 0;
				while (choice != 4) {
					cout << "\n-------------------------Queue Operations-------------------\n";
					cout << "\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display Queue\n\t4. Exit\n\n";
					cout << "Enter your choice: ";
					cin >> choice;
					sanitizeInput (choice);

					switch (choice) {
					case 1:
						cout << "Enqueue operation:\n";
						array_enqueue ();
						break;

					case 2:
						cout << "Dequeue operation:\n";
						array_dequeue ();
						break;

					case 3:
						cout << "Display Queue:\n";
						array_queue ();
						break;

					case 4:
						cout << "Queue program exit.\n";
						break;

					default:
						cout << "Invalid choice! Please enter a number between 1 and 4.\n";
					}
				}
			}
			else if (choice == 2) {
				cout << "Queue implemented using Linked List.\n";

				choice = 0;
				while (choice != 4) {
					cout << "\n-------------------------Queue Operations-------------------\n";
					cout << "\n\t1. Enqueue\n\t2. Dequeue\n\t3. Display Queue\n\t4. Exit\n\n";
					cout << "Enter your choice: ";
					cin >> choice;
					sanitizeInput (choice);

					switch (choice) {
					case 1:
						cout << "Enqueue operation:\n";
						list_enqueue ();
						break;

					case 2:
						cout << "Dequeue operation:\n";
						list_dequeue ();
						break;

					case 3:
						cout << "Display Queue:\n";
						list_queue ();
						break;

					case 4:
						cout << "Queue program exit.\n";
						break;

					default:
						cout << "Invalid choice! Please enter a number between 1 and 4.\n";
					}
				}
			}
		}

		else if (choice == 3) {
			cout << "Program exited successfully. Thanks a lot! I love C++ programming!\n";
		}

		else {
			cout << "Invalid choice! Please enter a number between 1 and 3\n";
		}
	}

	return 0;
}

// ---------------Function Definitions----------------------------------------------

// Stack using array ---------------------------------------------------------------

void array_push () {
	if (top == SIZE_S - 1) {
		cout << "\nStack overflow! Can't insert.\n";
		return;
	}

	int x;
	cout << "Enter element to be pushed: ";
	cin >> x;

	stack_arr[++top] = x;
	cout << "Element " << x << " inserted.\n";
}

void array_pop () {
	if (top == - 1) {
		cout << "\nStack underflow! Can't delete.\n";
		return;
	}

	cout << "Element " << stack_arr[top] << " deleted.\n";

	top--;
}

void array_stack () {
	if (top == - 1) {
		cout << "\nStack is empty.\n";
		return;
	}

	for (int i = 0; i < top + 1; i++) {
		cout << stack_arr[i] << " ";
	}
	cout << "\n";
}

// Stack using list---------------------------------------------------------------

void list_push () {
	if (list_top == 4) {
		cout << "\nStack overflow! Can't insert.\n";
		return;
	}

	int x;
	cout << "Enter element to be pushed: ";
	cin >> x;

	Node* ptr = new Node ();

	ptr -> data = x;
	ptr -> next = nullptr;

	if (stack_head == nullptr) {
		stack_head = ptr;
		list_top++;
		cout << "Element " << x << " inserted.\n";
		return;
	}

	Node* temp = stack_head;
	while (temp -> next != nullptr) {
		temp = temp -> next;
	}
	// Insert at the end
	temp -> next = ptr;

	cout << "Element " << x << " inserted.\n";
	list_top++;
}

void list_pop () {
	if (list_top == -1) {
		cout << "\nStack underflow! Can't delete.\n";
		return;
	}


	if (stack_head -> next == nullptr) {
		// List has only one node
		cout << "Element " << stack_head -> data << " deleted.\n";
		delete stack_head;
		stack_head = nullptr;
		list_top--;
		return;
	}

	Node* temp = stack_head;
	// Traverse to second last node
	while (temp -> next -> next != nullptr) {
		temp = temp -> next;
	}

	cout << "Element " << temp -> next -> data << " deleted.\n";

	delete temp -> next;      // Delete last node
	temp -> next = nullptr;
	list_top--;
}

void list_stack () {
	if (stack_head == nullptr) {
		cout << "\nStack is empty.\n";
		return;
	}

	Node* temp = stack_head;
	while (temp != nullptr) {
		cout << temp -> data << " ";
		temp = temp -> next;
	}
	cout << "\n";
}

// Queue using array ---------------------------------------------------------------

void array_enqueue () {
	if (rear == SIZE_Q - 1) {
	    cout << "\nQueue is full! Can't insert.\n";
		return;
	}
	
	if (front == -1) front++;
	
	int x;
	cout << "Enter element to be pushed: ";
	cin >> x;
	
	queue_arr[++rear] = x;
	cout << "Element " << x << " inserted.\n";
}

void array_dequeue () {
    if (front == -1) {
	    cout << "\nQueue is empty! Can't delete.\n";
		return;
	}
	
	cout << "Element " << queue_arr[front] << " deleted.\n";
	front++;
	
	if (front > rear) front = -1, rear = -1;
}

void array_queue () {
    if (front == -1) {
	    cout << "\nQueue is empty! \n";
		return;
	}
	
	for (int i = front; i < rear + 1; i++) {
	    cout << queue_arr[i] << " ";
	}
	cout << "\n";
}

// Queue using list ---------------------------------------------------------------

void list_enqueue () {
    if (list_rear == 4) {
	    cout << "\nQueue is full! Can't insert.\n";
		return;
	}
	
	if (list_front == -1) list_front++;
	
	int x;
	cout << "Enter element to be pushed: ";
	cin >> x;
	
	Node* ptr = new Node ();
	ptr -> data = x;
	ptr -> next = nullptr;
	
	if (queue_head == nullptr) {
	    queue_head = ptr;
	    list_rear++;
	    cout << "Element " << x << " inserted.\n";
	    return;
	}
	
	Node* temp = queue_head;
	while (temp -> next != nullptr) {
		temp = temp -> next;
	}
	
	// Insert at the end
	temp -> next = ptr;

	cout << "Element " << x << " inserted.\n";
	list_rear++;
}

void list_dequeue () {
    if (queue_head == nullptr) {
        cout << "\nQueue is empty! Can't delete.\n";
        return;
    }
    
    if (queue_head == nullptr) {
	    cout << "\nQueue is empty! Can't delete.\n";
	    return;
	}
	
	if (queue_head -> next == nullptr) {
	    // List has only one node
	    cout << "Element " << queue_head -> data << " deleted.\n";
	    delete queue_head;
	    queue_head = nullptr;
	    list_front = -1;
        list_rear = -1;
	    return;
	}
	
	Node* temp = queue_head;
	
	// Delete the first node
	temp = temp -> next;
	cout << "Element " << queue_head -> data << " deleted.\n";
	delete queue_head;
	queue_head = temp;
	list_front++;
	
	
	// If queue becomes empty after deletion
    if (queue_head == nullptr) {
        list_front = -1;
        list_rear = -1;
    }
}

void list_queue () {
    if (queue_head == nullptr) {
        cout << "\nQueue is empty! \n";
        return;
    }
    
    Node* temp = queue_head;
    while (temp != nullptr) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
    cout << "\n";
}