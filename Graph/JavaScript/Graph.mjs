
// write program to implement graph using adjacency list

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

// create a graph class
class Graph {
	constructor(noOfVertices) {
		this.noOfVertices = noOfVertices;
		this.AdjList = new Map();
		this.visited = [];
		for (var i = 0; i < this.noOfVertices; i++) this.visited[i] = false;
		this.adjMatrix = [];
	}

	// add vertex to the graph
	addVertex(v) {
		// initialize the adjacent list with a null array
		this.AdjList.set(v, []);
	}

	// add edge to the graph
	addEdge(v, w) {
		// get the list for vertex v and put the vertex w denoting edge between v and w
		this.AdjList.get(v).push(w);

		// since graph is undirected, add an edge from w to v also
		this.AdjList.get(w).push(v);
	}

	// Prints the vertex and adjacency list
	printGraph() {
		// get all the vertices
		var get_keys = this.AdjList.keys();

		// iterate over the vertices
		for (var i of get_keys) {
			// great the corresponding adjacency list for the vertex
			var get_values = this.AdjList.get(i);
			var conc = "";

			// iterate over the adjacency list
			// concatenate the values into a string
			for (var j of get_values) conc += j + " ";

			// print the vertex and its adjacency list
			console.log(i + " -> " + conc);
		}
	}

	// bfs(v)
	// dfs(v)
	// dfsRecursive(v)
}

export default Graph;
