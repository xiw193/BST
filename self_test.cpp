#include "BST.hpp"
#include <iostream>
#include <algorithm>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

/**
 * our test driver for the BST class template
 * Author: Sijie Ding & Leidan Chen
 */
int BST_test(vector<int>& v){
  /* Create an instance of BST holding int */
  BST<int> b;
  /* Insert a few data items. */
  vector<int>::iterator vit = v.begin();
  vector<int>::iterator ven = v.end();
  cout << "Performing BST insertion test .... " << endl;
  for(; vit != ven; ++vit) {
    // all these inserts are unique, so should return true
    if(! b.insert(*vit) ) {
      cout << "Incorrect return value when inserting " << *vit << endl;
      return -1;
    }
  }

  vit = v.begin();
  for(; vit != ven; ++vit) {
    // all these inserts are duplicates, so should return false
    if( b.insert(*vit) ) {
      cout << "Incorrect return value when re-inserting " << *vit << endl;
      return -1;
    }
  }
  cout << "Insertion test passed!" << endl;

  /* Test size. */
  cout << "Performing get size test ...." << endl;
  cout << "Size is: " << b.size() << endl;
  if(b.size() != v.size()) {
    cout << "... which is incorrect." << endl;
    return -1;
  }
  cout << "Get size test passed!" << endl;
  /* Test inorder function */
  cout <<"Performing inorder traverse BST" <<endl;
  b.inorder();
  cout << "Inorder test passed" <<endl;


  /* Test find return value.*/ 
  cout << "Performing find item test ...." << endl;
  vit = v.begin();
  for(; vit != ven; ++vit) {
    if(*(b.find(*vit)) != *vit) {

      cout << "Incorrect return value when finding " << *vit << endl;
      return -1;
    }
  }
  cout << "Find item test passed!" << endl;


  /*Sort the vector, to compare with inorder iteration on the BST */
  sort(v.begin(),v.end());


  /* Test BST iterator; should iterate inorder */
  cout << "Performing iterator test ...." << endl;
  cout << "traversal using iterator:" << endl;
  vit = v.begin();
  BST<int>::iterator it = b.begin();
  for(; vit != ven; ++vit) {
   // cout << *vit <<endl;
    cout << *it << endl;

    if(*it != *vit) {
     cout << *it << "," << *vit << ": Incorrect inorder iteration of BST." << endl;
      return -1;
   }
    it++;
  }
  cout << "Iterator test passed!" << endl;
  return 0;
}

int main(){

	/* Creat STL vectors of som ints*/
	vector<int> v_1;  //for a normal tree
	v_1.push_back(3);
	v_1.push_back(4);
	v_1.push_back(1);
	v_1.push_back(100);
	v_1.push_back(-33);
	v_1.push_back(6);
	v_1.push_back(78);
	v_1.push_back(98);
	v_1.push_back(79);
	v_1.push_back(5);
	
	vector<int> v_2; //all right children
	for (int i = 0; i < 10; i ++){
		v_2.push_back(i);
	}

	vector<int> v_3; //all left children
	for (int i = 10; i > 0; i --){
		v_3.push_back(i);
	}

	vector<int> v_4; //single node
	v_4.push_back(0);


	vector<int> v_5;//empty tree

	/*testing a normal tree*/
	cout << "*************************************************************" <<endl;
	cout << "testing an nomal tree..." <<endl;
	BST_test(v_1);
	cout <<"passed!" <<endl;
	cout << "*************************************************************" <<endl <<endl;
	
	cout << "*************************************************************" <<endl;
	cout << "testing 'all-right-children' tree..." <<endl;
	BST_test(v_2);
	cout <<"passed!" <<endl;
	cout << "*************************************************************" <<endl <<endl;

	cout << "*************************************************************" <<endl;
	cout << "testing 'all-left-children' tree..." <<endl;
	BST_test(v_3);
	cout <<"passed!" <<endl;
	cout << "*************************************************************" <<endl <<endl;

	cout << "*************************************************************" <<endl;
	cout << "testing 'single-node' tree..." <<endl;
	BST_test(v_4);
	cout <<"passed!" <<endl;
	cout << "*************************************************************" <<endl <<endl;

	cout << "*************************************************************" <<endl;
	cout << "testing empty tree..." <<endl;
	BST_test(v_5);
	cout <<"passed!" <<endl;
	cout << "*************************************************************" <<endl <<endl;
	
	cout <<"testing 'empty()' function...." <<endl;
	BST<int> b;
	BST<int> b_1;
	b_1.insert(0);
	if( b.empty() && !b_1.empty())
		cout <<"empth() test passed!" <<endl;

	cout <<"self_test All Passed!" <<endl;

	return 0;
}
