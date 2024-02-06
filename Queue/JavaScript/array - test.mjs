import Queue from './class - array.mjs';

// creating object for queue class
var queue = new Queue();

// testing isEmpty and clear on an empty queue
// returns true

console.log(queue.isEmpty());

// returns Underflow
console.log(queue.dequeue());

// adding elements to the queue
queue.enqueue(10);

// returns 10
console.log(queue.peek());

// adding elements to the queue
queue.enqueue(20);
queue.enqueue(30);

// returns 10
console.log(queue.peek());

// returns 10 and remove it from the queue
console.log(queue.dequeue());

