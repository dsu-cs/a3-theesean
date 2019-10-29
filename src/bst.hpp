#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
	
	Node<T> *new_node = new Node<T>(new_data);//create node

	if(root == NULL)//make node root if tree is empty
	{
		root = new_node;
		node_count = node_count + 1;//incement count
	}
	else
	{
		Node<T> *cur = root;
		if (cur->get_data() == new_node->get_data())//make sure number is not already in tree
		{
			delete(new_node);
			return;
		}
		while(cur != NULL)//find designation location in the list
		{
				if(new_node->get_data() < cur->get_data())
				{
			                if (cur->get_data() == new_node->get_data())//make sure number is not already in tree
			                {
                        			return;
                			}

					if(cur->get_left() == NULL)//place node
					{
						cur->set_left(new_node);
						node_count = node_count + 1;
						return;
					}
					else
						cur = cur->get_left();
				}
				else
				{
                			if (cur->get_data() == new_node->get_data())//make sure number is not already in tree
                			{
                        			return;
			                }
			
					if(cur->get_right() == NULL)//place node
					{
						cur->set_right(new_node);
						node_count = node_count + 1;
						return;
					}
					else
					{
						cur = cur->get_right();
					}
				}
		}
		return;
	}

}


template<class T>
Node<T> *BST<T>::search(T val)
{
	Node<T> *cur = root;
	while(cur != NULL)
	{
		if(val == cur->get_data())
		{
			return(cur);
		}
		else if(val < cur->get_data())
		{
			cur = cur->get_left();
		}
		else
		{
			cur = cur->get_right();
		}
	}
	delete(cur);
	return NULL;
}



template<class T>
void BST<T>::remove(T val)
{
	Node<T> *par = NULL;
	Node<T> *cur = root;
	Node<T> *suc = NULL;
	int sucData;
	while(cur != NULL)//search for node
	{
		if(cur->get_data() == val)
		{
			if(cur->get_left() == NULL  &&	cur->get_right() == NULL)//remove leaf
			{
				node_count = node_count - 1;
				if(par == NULL)
				{	
					root = NULL;
					return;
				}
				else if(par->get_left() == cur)
				{
					par->set_left(NULL);
					return;
				}	
				else
				{
					par->set_right(NULL);
					return;
				}
			}
			
		
			else if (cur->get_left() != NULL && cur->get_right() == NULL)//remove node with only left child
			{
				node_count = node_count - 1;
				if(par == NULL)//Node is root
				{
					root = cur->get_left();
					return;
				}
				else if(par->get_left() == cur)
				{
					par->set_left(cur->get_left());
					return;
				}	
				else
				{
					par->set_right(cur->get_left());
					return;
				}
			}
			else if (cur->get_left() == NULL && cur->get_right() != NULL)//remove node with only right child
			{
				node_count = node_count - 1;
				if(par == NULL)//Node is root
				{
					root = cur->get_right();
					return;
				}	
				else if(par->get_left() == cur)
				{
					par->set_left(cur->get_right());
					return;
				}
				else 
				{
					par->set_right(cur->get_right());	
					return;
				}
			}
			else//remove node with two children
			{
				suc = cur->get_right();
				while(suc->get_left() != NULL)
				{
					suc = suc->get_left();
				}
				sucData = suc->get_data();
				remove(sucData);
				cur->set_data(sucData); 
				return;
			}
			return;
		}
		else if(cur->get_data() < val)
		{
			par = cur;
			cur = cur->get_right();
		}
		else
		{
			par = cur;
			cur = cur->get_left();
		}
		
	}
	return;//node not found
}



template<class T>
int BST<T>::get_size()
{
	return(node_count);
}
