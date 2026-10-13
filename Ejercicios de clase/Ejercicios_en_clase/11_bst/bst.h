/*
 * bst.h
 *
 *  Created on: 30/10/2015
 *      Author: clase
 */

#ifndef BST_H_
#define BST_H_

#include <string>
#include <sstream>
#include "exception.h"

template <class T> class BST;

template <class T>
class TreeNode {
private:
	T value;
	TreeNode *left, *right;

	TreeNode<T>* succesor();

public:
	TreeNode(T);
	TreeNode(T, TreeNode<T>*, TreeNode<T>*);
	void add(T);
	bool find(T);
	void remove(T);
	void removeChilds();
	void inorder(std::stringstream&) const;
	void preorder(std::stringstream&) const;

	friend class BST<T>;
};

template <class T>
TreeNode<T>::TreeNode(T val) {
	value = val;
	left = NULL;
	right = NULL;
}

template <class T>
TreeNode<T>::TreeNode(T val, TreeNode<T> *le, TreeNode<T> *ri) {
	value = val;
	left = le;
	right = ri;
}

template <class T>
void TreeNode<T>::add(T val) {

	if (val < value) {
		if (left == NULL) {
			TreeNode<T> * nuevo_nodo = new TreeNode<T>(val);
			if (nuevo_nodo == NULL) {
				throw OutOfMemory();
			}
			left = nuevo_nodo;
		} else {
			left->add(val);
		}
		
	} else {
		if (right == NULL) {
			TreeNode<T> * nuevo_nodo = new TreeNode<T>(val);
			if (nuevo_nodo == NULL) {
				throw OutOfMemory();
			}
			right = nuevo_nodo;
		} else {
			right->add(val);
		}
	}
}

template <class T>
bool TreeNode<T>::find(T val) {
	if (val == value) {
		return true;
	} else if (val < value) {
		if (left != NULL) {
			return left->find(val);
		} else {
			return false;
		}
	} else {
		if (right != NULL) {
			return right->find(val);
		} else {
			return false;
		}
	}
}

template <class T>
TreeNode<T>* TreeNode<T>::succesor() {
	if (left != NULL) {
		TreeNode<T>* sucesor = left;
		if (left->right == NULL) {
			left->left = sucesor->left; 
			sucesor->left = NULL;
			std::cout << "sucesor " << sucesor->value << std::endl;
			return sucesor;
		} else {			
			TreeNode<T>* anterior = sucesor;
			while (sucesor->right != NULL) {
				anterior = sucesor;
				sucesor = sucesor->right;
			}
			anterior->right = sucesor->left;
			sucesor->left = NULL;

			std::cout << "sucesor " << sucesor->value << std::endl;
			std::cout << "sucesor->left " << sucesor->left << std::endl;
			std::cout << "sucesor->right " << sucesor->right << std::endl;
			return sucesor;
		}
	} else {
		//TODO Si no hay mayor de los menores, elegir el menor de los mayores
	}
	return 0;
}

template <class T>
void TreeNode<T>::remove(T val) {
	std::cout << "remove " << val << " buscando en " << value << std::endl;
	if (val < value) {
		if (left->value == val) {
			std::cout << " encontrado " << std::endl;
			if (left->left == NULL && left->right == NULL) {
				delete left;
				left = NULL;
			} else {
				TreeNode<T> * sucesor = left->succesor();
				std::cout << "sucesor " << sucesor->value << std::endl;
				sucesor->left = left->left;
				sucesor->right = left->right;
				delete left;
				left = sucesor;
			}
		} else {
			left->remove(val);
		}
	} else {
		if (right->value == val) {
			if (right->left == NULL && right->right == NULL) {
				delete right;
				right = NULL;
			} else {
				TreeNode<T> * sucesor = succesor();
				sucesor->left = right->left;
				sucesor->right = right->right;
				delete right;
				right = sucesor;
			}
		} else {
			right->remove(val);
		}
	}
}

template <class T>
void TreeNode<T>::removeChilds() {
}

template <class T>
void TreeNode<T>::inorder(std::stringstream &aux) const {
	if (left != 0) {
		left->inorder(aux);
	}
	if (aux.tellp() != 1) {
		aux << " ";
	}
	aux << value;
	if (right != 0) {
		right->inorder(aux);
	}
}

template <class T>
void TreeNode<T>::preorder(std::stringstream &aux) const {
	aux << value;
	if (left != 0) {
		aux << " ";
		left->preorder(aux);
	}
	if (right != 0) {
		aux << " ";
		right->preorder(aux);
	}
}

template <class T>
class BST {
private:
	TreeNode<T> *root;

public:
	BST();
	~BST();
	bool empty() const;
	void add(T);
	bool find(T) const;
	void remove(T);
	void removeAll();
	std::string inorder() const;
	std::string preorder() const;
};

template <class T>
BST<T>::BST() : root(0) {}

template <class T>
BST<T>::~BST() {
	removeAll();
}

template <class T>
bool BST<T>::empty() const {
	return (root == 0);
}

template<class T>
void BST<T>::add(T val) {
	if (empty()) {
		TreeNode<T> * nuevo_nodo = new TreeNode<T>(val);
		if (nuevo_nodo == NULL) {
			throw OutOfMemory();
		}
		root = nuevo_nodo;
	} else {
		root->add(val);
	}
}

template <class T>
void BST<T>::remove(T val) {
	if (empty()) {
		throw NoSuchElement();
	}

	if(!find(val)) {
		throw NoSuchElement();
	}

	if(root->value == val) {
		TreeNode<T> * sucesor = root->succesor();
		if (sucesor != NULL) {
			sucesor->right = root->right;
			sucesor->left = root->left;
		}
		root->right = NULL;
		root->left = NULL;
		delete root;
		root = sucesor;
	} else {
		root->remove(val);
	}
}

template <class T>
void BST<T>::removeAll() {
}

template <class T>
bool BST<T>::find(T val) const {
	if (root != NULL) {
		return root->find(val);
	}
	return false;
}

template <class T>
std::string BST<T>::inorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->inorder(aux);
	}
	aux << "]";
	return aux.str();
}

template <class T>
std::string BST<T>::preorder() const {
	std::stringstream aux;

	aux << "[";
	if (!empty()) {
		root->preorder(aux);
	}
	aux << "]";
	return aux.str();
}

#endif /* BST_H_ */
