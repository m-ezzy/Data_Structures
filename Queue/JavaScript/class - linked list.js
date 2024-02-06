// implement queue using an not an array but a linked list

// create a node class
class Node {
	constructor(element) {
		this.element = element;
		this.next = null;
	}
}

// create a queue class
class Queue {
	constructor() {
		this.front = null;
		this.rear = null;
	}

	// add element to the queue
	enqueue(element) {
		// create a new node
		var node = new Node(element);

		// if queue is empty
		if (this.rear == null) {
			// both front and rear will point to new node
			this.front = this.rear = node;
		} else {
			// add the new node at the end of queue and change rear
			this.rear.next = node;
			this.rear = node;
		}
	}

	// remove element from the queue
	dequeue() {
		// if queue is empty
		if (this.front == null) {
			return "Underflow";
		}

		// store previous front and move front one node ahead
		var temp = this.front;
		this.front = this.front.next;

		// if front becomes null, then change rear also as null
		if (this.front == null) {
			this.rear = null;
		}
		return temp.element;
	}

	// print queue elements
	printQueue() {
		var temp = this.front;
		var str = "";
		while (temp) {
			str += temp.element + " ";
			temp = temp.next;
		}
		return str;
	}
}

// creating object for queue class
var queue = new Queue();

// testing dequeue and pop on an empty queue
// returns Underflow
console.log(queue.dequeue());

// returns true
console.log(queue.isEmpty());

// adding elements to the queue
// queue contains [10, 20, 30, 40, 50]
queue.enqueue(10);
queue.enqueue(20);
queue.enqueue(30);
queue.enqueue(40);
queue.enqueue(50);

