// program to implement a stack using an array

export default class Stack {
	constructor() {
		this.elements = [];
	}
	// add element to the stack
	push(element) {
		this.elements.push(element);
		return {success: true};
	}
	// remove element from the stack
	pop() {
		if (this.isEmpty()) {
			return { success: false, message: "Underflow" };
		}
		const element = this.elements.pop();
		return { success: true, element: element };
	}
	// view the last element
	peek() {
		if (this.isEmpty()) {
			return { success: false, message: "Underflow" };
		}
		return { success: true, element: this.elements[this.elements.length - 1] };
	}
	// check if the stack is empty
	isEmpty() {
		return this.elements.length == 0;
	}
	// the size of the stack
	size() {
		return this.elements.length;
	}
	// empty the stack
	clear() {
		this.elements = [];
	}
	// print the stack elements
	print() {
		this.elements.forEach((item) =>{
			console.log(item);
		})
	}
}
