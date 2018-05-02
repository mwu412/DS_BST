#include <iostream>
#include <stack>
using namespace std;

class BST {
private:
	class node {
	public:
		int key;
		node * leftnode;
		node * rightnode;
		node * parant;
		node(int key) {
			this->key = key;
			leftnode = NULL;
			rightnode = NULL;
			parant = NULL;
		}
	};
	node* root = NULL;
public:
	bool Empty() {
		return root == NULL;
	}
	bool Exist(int targetkey) {
		if (Empty()) return false;
		node *search = root;
		while (search) {
			if (targetkey == search->key) return true;
			if (targetkey > search->key) search = search->rightnode;
			else search = search->leftnode;
		}
		return false;
	}
	node* Search(int targetkey) {
		if (Empty()) return NULL;
		node *search = root;
		while (search) {
			if (targetkey == search->key) return search;
			if (targetkey > search->key) search = search->rightnode;
			else search = search->leftnode;
		}
		return NULL;
	}
	void Insert(int key) {
		if (Empty()) {
			root = new node(key);
		}
		if (Exist(key)) return;
//		node *newone = 
		node *search = root;
		while (search) {
			if (key > search->key) {
				if (search->rightnode == NULL) {
					search->rightnode = new node(key);
//					newone->parant = search;
					break;
				}
				search = search->rightnode;
			}
			else {
				if (search->leftnode == NULL) {
					search->leftnode = new node(key);
//					newone->parant = search;
					break;
				}
				search = search->leftnode;
			}
		}

	}
	void Inorder() {		//func. overloading (polymophism)
		Inorder(root);
	}
	void Inorder(node* search) {
		if (search) {
			Inorder(search->leftnode);
			cout<<search->key<<endl;
			Inorder(search->rightnode);
		}
	}
	/*	node* Closest(int targetkey) {
        if(Search(targetkey) == NULL) return NULL;
        node *leftmax = Search(targetkey)->leftnode;
        node *rightmin = Search(targetkey)->rightnode;
        while(leftmax->rightnode){
            leftmax = leftmax->rightnode;
        }
        while(rightmax->leftnode){
            rightmin = rightmin->leftnode;
        }
        if((targetkey - leftmax) >= (rightmin - targetkey)) return leftmax; //define closest with left priority
        else return rightmin;
	}
	void Delete(int targetkey) {
		if (Exist(targetkey)) return;
		node* search = Search(targetkey);
		if (search->leftnode == NULL && search->rightnode == NULL) delete search;
		else if (search->leftnode != NULL && search->rightnode == NULL) {
			search->parant->leftnode = search->leftnode;
			delete search;
		}
		else if (search->leftnode == NULL && search->rightnode != NULL) {
			search->parant->rightnode = search->rightnode;
			delete search;
		}
		else {
            node *closest = Closest(search);
            node *temp = search;
            search = closest;
            closest = temp; //maybe wrong // try copy constructor?
            Delete()
		}
	}
	*/
};

int main() {
	BST bst;
	bst.Insert(5);
	bst.Insert(7);
	bst.Insert(3);
	bst.Insert(4);
	bst.Insert(1);
	bst.Insert(2);
	bst.Insert(6);
	bst.Inorder();
	system("pause");
	return 0;
}
