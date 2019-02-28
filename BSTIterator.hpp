#ifndef BSTITERATOR_HPP
#define BSTITERATOR_HPP
#include "BSTNode.hpp"
#include <list>
#include <iterator>

template<typename Data>
class BSTIterator : public std::iterator<std::input_iterator_tag,Data> {

private:

  BSTNode<Data>* curr;

public:

  /** Constructor.  Use the argument to initialize the current BSTNode
   *  in this BSTIterator.
   */ // TODO
  BSTIterator(BSTNode<Data>* curr): curr(curr){
  }



  Data operator*() const {
    return curr->data;
  }
  
  /** Pre-increment operator. */
  BSTIterator<Data>& operator++() {
    curr = curr->successor();
    return *this;
  }

  /** Post-increment operator. */
  BSTIterator<Data> operator++(int) {
    BSTIterator before = BSTIterator(curr);
    ++(*this);
    return before;
  }

  /* answer */
    /** Equality test operator. */ 
  bool operator==(BSTIterator<Data> const & other) const {
    if(this->curr == other.curr) {
      return true;
    }
    else {
      return false;
    }
  }

  /** Inequality test operator. */  
  bool operator!=(BSTIterator<Data> const & other) const {
    if(this->curr != other.curr) {
      return true;
    }
    else {
      return false;
    }
  }
  
  /** Equality test operator. */ // TODO     my operator
 /* bool operator==(BSTIterator<Data> const & other) const {
	 if(curr == NULL) {                         //check for the Null pointer and then compare the values
		 if(other.curr == NULL)
			 return true;
		 else
			 return false;
	 }
	 else{
		 if(other.curr == NULL)
			 return false;
		 else{
			 if(*other == curr->data)
				 return true;
			 else
				 return false;
		 }
	 }

  }     */

  /** Inequality test operator. */ // TODO
/*  bool operator!=(BSTIterator<Data> const & other) const {
	if(curr == NULL){                                    //check for the Null pointer and then compare the values
		if(other.curr == NULL)
			return false;
		else
			return true;
	}
	else{
		if(other.curr == NULL)
			return true;
		else{
			if(*other == curr->data)
				return false;
			else
				return true;
			
		}
	}

  }*/

};  

#endif //BSTITERATOR_HPP
