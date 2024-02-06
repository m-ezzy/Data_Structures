
class Node {
	constructor(value) {
			this.value = value
			this.left = null
			this.right = null
	}
}
export default class BinaryTree {
	//methods to insert, delete and search for nodes
	constructor() {
		this.root = null
	}
	// The insert method takes a value as parameter and inserts the value in its corresponding place within the tree
	insert(value) {
		const newNode = new Node(value)
		if(this.root === null){
			this.root = newNode
			return this
		}
		let current = this.root
		while(true) {
			if(value === current.value) return undefined
			
			if(value < current.value){
				if(current.left === null){
					current.left = newNode
					return this
				}
				current = current.left
			} else {
				if(current.right === null){
					current.right = newNode
					return this
				} 
				current = current.right
			}
		}
	}
	// The find method takes a value as parameter and iterates through the tree looking for that value
	// If the value is found, it returns the corresponding node and if it's not, it returns undefined
	find(value){
		if(this.root === null) return false
		let current = this.root,
			found = false
		while(current && !found){
			if(value < current.value){
				current = current.left
			} else if(value > current.value){
				current = current.right
			} else {
				found = true
			}
		}
		if(!found) return undefined
		return current
	}
}
