#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

template<typename Data>
class BSTGrading : public BST<Data> {
public:
  BSTGrading(BSTNode<Data> * root, unsigned int isize) {
    this->root = root;
    this->isize = isize;
  }
}; 

int main() {
  int grade = 16;
  // test bst node (only successor)
  cout << "checking BSTNode: " << endl;;
  BSTNode<int> * node1 = new BSTNode<int>(13);
  
  // handle no child case
  if(!(NULL == node1->successor())) {
    cout << "x successor"; 
    grade--;
  }
  cout << "p " << endl;
  
  // has left child, no parent
  BSTNode<int> * node2 = new BSTNode<int>(19);
  node1->left = node2;
  node2->parent = node1;
  if(!(NULL == node1->successor())) {
    cout << "x successor"; 
    grade--;
  }
  cout << "p " << endl;

  // has only one right child
  node1->left = 0;
  node1->right = node2;
  
  if(!(node2 == node1->successor())) {
    cout << "x successor"; 
    // grade--; no one may miss it
  }

  // has more than one right child
  BSTNode<int> * node3 = new BSTNode<int>(17);
  BSTNode<int> * node5 = new BSTNode<int>(21);
  BSTNode<int> * node6 = new BSTNode<int>(14);
  node2->left = node3;
  node2->right = node5;
  node3->left = node6;
  node3->parent = node2;
  node5->parent = node2;
  node6->parent = node3;
  
  if(!(node6 == node1->successor())) {
    cout << "x successor";
    grade--;
  }
  cout << "p " << endl;

  // is left child
  if(!(node2 == node3->successor())) {
    cout << "x successor";
    grade--;
  }
  cout << "p " << endl;
  
  // is right child
  BSTNode<int> * node4 = new BSTNode<int>(18);
  node3->right = node4;
  node4->parent = node3;
  if(!(node2 == node4->successor())) {
    cout << "x successor";
    grade--;
  }
  cout << "p " << endl;
  delete node1;
  delete node2;
  delete node3;
  delete node4;
  delete node5;
  delete node6;

  // test bst
  cout << endl;
  cout << endl;
  cout << "checking BST: " << endl;
  BST<int> emptyBST;
  BST<int> b1; // insert
  vector<int> v;
  
  // manually construct tree
  v.push_back(0);
  v.push_back(2);
  v.push_back(1);
  v.push_back(8);
 
  BSTNode<int> *n1 = new BSTNode<int>(0);
  BSTNode<int> *n2 = new BSTNode<int>(2);
  BSTNode<int> *n3 = new BSTNode<int>(1);
  BSTNode<int> *n4 = new BSTNode<int>(8);
  n1->right = n2;
  n2->parent = n1;
  n2->left = n3;
  n2->right = n4;
  n3->parent = n2;
  n4->parent = n2;
  BSTGrading<int> b2(n1, 4);
 
  
  // test empty BST
  if(!emptyBST.empty()) {
    cout << "x empty";
    grade--;
  }
  cout << "p " << endl;
  if(!(emptyBST.end() == emptyBST.find(0))) {
    grade--;
    cout << "x find empty";
  }
  cout << "p" << endl;
  
  // test insert
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  int toggle = 0;
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return true
    if(! b1.insert(*vit) ) {
      cout << " x insert " << *vit << endl;
      toggle = 1;
    }
  }
  if(toggle) {
      grade--;
  }

  // insert duplicate item
  toggle = 0;
  vit = v.begin();
  for(; vit != ven; ++vit) {
    // all these inserts are duplicates, so should return false
    if( b1.insert(*vit) ) {
      cout << "x insert duplicate " << *vit << endl;
      toggle = 1;
    }
  }
  if(toggle) {
    grade--;
  }
  cout << "p " << endl;
  
  // test size
  if(b1.size() != v.size()) {
    cout << "x size" << endl;
    grade--;
  }
  cout << "p " << endl;
  
  // check b1 insertion
  cout << endl;
  cout << "if inorder is correct: (please read inorder code)" << endl;
  cout << "the following two trees should be the same" << endl;
  cout << "otherwise insertion is wrong" << endl;
  cout << "========= BST b1 =========" << endl;
  b1.inorder();
  cout << "========= BST b2 =========" << endl;
  b2.inorder();
  cout << "=========== end ==========" << endl;

  // test bst iterator first 
  cout << endl;
  cout << "checking BSTIterator: "<< endl;
  
  // test == & !=
  if((BSTIterator<int>(0) != BSTIterator<int>(0)) || !(BSTIterator<int>(0) == BSTIterator<int>(0))) {
    cout << "x == or != ";
    grade--;
  }

  BSTNode<int> * n5 = new BSTNode<int>(0);
  if((BSTIterator<int>(n1) == BSTIterator<int>(n5)) || (BSTIterator<int>(n2) != BSTIterator<int>(n2))) {
    cout << "x == or != ";
    grade--;
  }
  delete n5;
  cout << "p" << endl;
 
  // test find only (do not insert)
  toggle = 0;
  vit = v.begin();
  for(; vit != ven; ++vit) {
    if(*(b2.find(*vit)) != *vit) {
      cout << "x find " << *vit << endl;
      toggle = 1;
    }
  }
  if(toggle) {
    grade--;
  }
  
  cout << "p" << endl;
  // test find sth does not exist...
  if(!(b2.find(999) == BSTIterator<int>(0))) {
    grade--;
    cout << "x find ";
  }
  cout << "p " << endl;
  
  // test begin()
  if(b2.begin() != BSTIterator<int>(n1)) {
    cout << "x begin ";
    grade--;
  }
  cout << "p " << endl;
  
  cout << "here" << endl;
  // test end()
  if(b2.end() != BSTIterator<int>(0)) {
    cout << "x end";
  }

  // put it all together
  toggle = 0;
  sort(v.begin(),v.end());
  cout << endl;
  vit = v.begin();
  BST<int>::iterator it = b1.begin();
  for(; vit != ven; ++vit) {
    cout << *it << endl;
    if(*it != *vit) {
      cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
      toggle = 1;
    }
    ++it;
  }
  if(toggle) {
    grade--;
  }
  cout << endl;
  cout << "the following grade is not accurate if the code has segfault." << endl;
  cout << "====== Grade " << grade << " / 16 ======" << endl;
}
