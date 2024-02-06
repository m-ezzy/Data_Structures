// create data structure for tree node using array of objects

class Node {
	constructor(data) {
		this.data = data;
		this.children = [];
	}
}
class Tree {
	constructor() {
		this.root = null;
	}
	// add node to the tree
	addNode(data, toNodeData) {
		const node = new Node(data);
		const parent = toNodeData ? this.findBFS(toNodeData) : null;
		if (parent) {
			parent.children.push(node);
		} else {
			if (!this.root) {
				this.root = node;
			} else {
				return "Root node is already assigned";
			}
		}
	}
	addSubtree(data, toNodeData) {
		const node = new Node(data);
		const parent = toNodeData ? this.findBFS(toNodeData) : null;
		if (parent) {
			parent.children.push(node);
		} else {
			if (!this.root) {
				this.root = node;
			} else {
				return "Root node is already assigned";
			}
		}
	}
	// find node using breadth first search
	findBFS(data) {
		const queue = [this.root];
		let _node = null;
		this.traverseBFS((node) => {
			if (node.data == data) {
				_node = node;
			}
		});
		return _node;
	}
	// traverse through the tree using breadth first search
	traverseBFS(cb) {
		const queue = [this.root];
		// if (cb) {
			while (queue.length) {
				const node = queue.shift();
				cb(node);
				if (node.children) {
					for (const child of node.children) {
						queue.push(child);
					}
				}
			}
		// }
	}
	// traverse through the tree using depth first search
	traverseDFS(cb) {
		(function recurse(currentNode) {
			for (const child of currentNode.children) {
				recurse(child);
			}
			cb(currentNode);
		})(this.root);
	}
	// remove node from the tree
	remove(data) {
		if (this.root.data == data) {
			this.root = null;
		}
		this.traverseBFS((node) => {
			node.children.forEach((childNode, index) => {
				if (childNode.data == data) {
					node.children.splice(index, 1);
				}
			});
		});
	}
}
