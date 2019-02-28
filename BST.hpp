#ifndef BST_HPP
#define BST_HPP
#include "BSTNode.hpp"
#include "BSTIterator.hpp"
#include <iostream>

template<typename Data>
class BST {

  protected:

  /** Pointer to the root of this BST, or 0 if the BST is empty */
  BSTNode<Data>* root;

  /** Number of Data items stored in this BST. */
  unsigned int isize;

  public:

  /** define iterator as an aliased typename for BSTIterator<Data>. */
  typedef BSTIterator<Data> iterator;

  /** Default constructor.
      Initialize an empty BST.
   */
  BST() : root(0), isize(0) {  }


  /** Default destructor.
      Delete every node in this BST.
   */ // TODO
  virtual ~BST() {
	  deleteAll(root);	
  }

  /** Given a reference to a Data item, insert a copy of it in this BST.
   *  Return  true if the item was added to this BST
   *  as a result of this call to insert,
   *  false if an item equal to this one was already in this BST.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use >, <=, >=)
   */ // TODO
  virtual bool insert(const Data& item) {
	  BSTNode<Data>* p = new BSTNode<Data>( item);
	  if( root == NULL){ //if the BST is empty, insert as rood NODE
		  root = p;
		  isize += 1;
		  return 1;
	  }
	  else{
		  BSTNode<Data>* cur = root;
		  while(cur != NULL){
			  if(p->data < cur->data){         //smaller then current node, go left
				  if(cur->left == NULL){   //left is empty, insert
					  cur->left = p;
					  p->parent = cur;
					  cur = NULL;
					  isize += 1;
					  return 1;
				  }
				  else{
					  cur = cur->left;
				  }
			  }
			  else if(cur->data < p->data){   //larger then the current node, go right
				  if(cur->right == NULL){ //right is empty, insert
					  cur->right = p;
					  p->parent = cur;
					  cur = NULL;
					  isize += 1;
					  return 1;
				  }
			  	  else{
					  cur = cur->right;
				  }
			  
			  }
			  else{ //neither smaller nor larger, then, it's duplicate insert.
				  delete p; //free memery if insert failure
				  return 0;
			  }
		  }
	  }
  }


  /** Find a Data item in the BST.
   *  Return an iterator pointing to the item, or pointing past
   *  the last node in the BST if not found.
   *  Note: This function should use only the '<' operator when comparing
   *  Data items. (should not use >, <=, >=)
   */ // TODO
  iterator find(const Data& item) const {
	  BSTNode<Data>* p = root;
	  while(p){
		  if(item < p->data)//smaller than the current node, go left
			  p = p->left;
		  else if(p->data < item)
			  p = p->right;//larger than the current node, go right
		  else
			  return BST<Data>::iterator(p);//find!!!
	  }
	  return this->end();//no more children, return Null.

  }

  
  /** Return the number of items currently in the BST.
   */ // TODO
  unsigned int size() const {
	  return isize;
	
  }

  /** Return true if the BST is empty, else false.
   */ // TODO
  bool empty() const {
	  if (root == NULL)
		  return true;
	  else
		  return false;

  }

  /** Return an iterator pointing to the first item in the BST (not the root).
   */ // TODO
  iterator begin() const {
	return typename BST<Data>::iterator(first(root));
  }

  /** Return an iterator pointing past the last item in the BST.
   */
  iterator end() const {
    return typename BST<Data>::iterator(0);
  }

  /** Perform an inorder traversal of this BST.
   */
  void inorder() const {
    inorder(root);
  }


private:

  /** Recursive inorder traversal 'helper' function */

  /** Inorder traverse BST, print out the data of each node in ascending order.
      Implementing inorder and deleteAll base on the pseudo code is an easy way to get started.
	  retutypename BST
   */ // TODO
  void inorder(BSTNode<Data>* n) const {
    /* Pseudo Code:
      if current node is null: return;
      recursively traverse left sub-tree
      print current node data
      recursively traverse right sub-tree
    */
	  if (n == 0){
		  return;
	  }
	  inorder (n->left);
	  std::cout  << (*n) << std::endl;
	  inorder (n->right);

  }

  /** Find the first element of the BST
   */ 
  static BSTNode<Data>* first(BSTNode<Data>* root) {
    if(root == 0) return 0;
    while(root->left != 0) root = root->left;
    return root;
  }

  /** do a postorder traversal, deleting nodes
   */ // TODO
  static void deleteAll(BSTNode<Data>* n) {
    /* Pseudo Code:
      if current node is null: return;
      recursively delete left sub-tree
      recursively delete right sub-tree
      delete current node
    */
	  if (n == NULL){
		  return;
	  }
	  deleteAll(n->left);
	  deleteAll(n->right);
	  delete n;

  }


 };


#endif //BST_HPP
