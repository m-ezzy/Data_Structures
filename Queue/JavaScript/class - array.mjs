// program to implement a queue using an array
export default class Queue {
	constructor() {
		this.items = [];
	}
	// add element to the queue
	enqueue(element) { //push
		this.items.push(element);
		return {success: true};
	}
	// remove element from the queue
	dequeue() { //pop
		if (this.isEmpty()) {
			return { success: false, message: "Underflow" };
		}
		const element = this.items.shift();
		return { success: true, element: element };
	}
	// view the last element
	peek() {
		if (this.isEmpty()) {
			return { success: false, message: "Underflow" };
		}
		return { success: true, element: this.items[this.items.length - 1] };
	}
	// check if the queue is empty
	isEmpty() {
		return this.items.length == 0;
	}
	// the size of the queue
	size() {
		return this.items.length;
	}
	// empty the queue
	clear() {
		this.items = [];
	}
	// print the queue items
	printQueue() {
		var str = "";
		for (var i = 0; i < this.items.length; i++) {
			str += this.items[i] + " ";
		}
		return str;
	}
	print() {
		this.items.forEach((item) =>{
			console.log(item);
		})
	}
}
