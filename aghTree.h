#ifndef AGHTREE_H
#define AGHTREE_H

#include <iostream>
#include "aghContainer.h"
#include "aghNode.h"

template <class T>
class aghTree : public aghContainer<T>{
     private: 
          aghNode<T>* root;
          unsigned int elementsCount;
     
     public:
          //\brief The class constructor.
          //
          //\param _size - number of elements to store
          aghTree();
          
          //\brief The class copying constructor.
          //
          //\param _source - source object
          aghTree(const aghContainer<T>& _source);
          
          //\brief The class destructor.
          virtual ~aghTree();
     
          //\brief Method to return value of given element.
          //
          //\param _index - index of chosen element
          //\return value of the element on given position
          T& at(unsigned int _index) const;
          
          //\brief Method to check ammount of elements in the list.
          //
          //return Ammount of the elements.
          unsigned int size(void) const;
          
          //\brief Method to insert new element to the list.
          //
          //\param _index - position where we want to put new element
          //\param _value - value to set for new element
          //\return TRUE if finished successfully ( FALSE otherwaise )
          bool insert(T const& _value);
          
          bool insert(unsigned int _index, T const& _value);
          
          //\brief Method to remove element from the list.
          //
          //\param _index - position from where we want remove element
          //\return TRUE if finished successfully ( FALSE otherwaise )
          bool remove(unsigned int _index);
          
          //\brief Overload of operator=
          //
          //\param - source aghVector<T> object
          //\return reference to 'this' object
          aghTree<T>& operator=(const aghContainer<T>& _right);
          
          aghNode<T> * findNode(aghNode<T> * node, unsigned int _calledIndex, unsigned int _currentIndex) const;
};

template <typename T>
aghTree<T>::aghTree():elementsCount(0), root(NULL){
}

template <typename T>
aghTree<T>::aghTree(const aghContainer<T>& _source){

}

template <typename T>
aghTree<T>::~aghTree(){
     //this->clear();
     elementsCount = 0;
     root = NULL;
}

template <typename T>
T& aghTree<T>::at(unsigned int _index) const{
     return findNode(root, _index, 0)->getValue();
}

template <typename T>
unsigned int aghTree<T>::size(void) const{
     return elementsCount;
}

template <typename T>
bool aghTree<T>::insert(T const& _value){
     aghNode<T> *newNode = root, *temp = NULL;
     
     while(newNode){
          temp = newNode;
          if(_value > newNode->getValue()) newNode = newNode->getNext();
          else newNode = newNode->getPrev();    
     }
     newNode = new aghNode<T>(_value);
     if(temp){
          if(_value > temp->getValue()) temp->setNext(newNode);
               else temp->setPrev(newNode);
     }else{
          root = newNode;
     }   
     elementsCount++;
     return true; 
}

template <typename T>
bool aghTree<T>::insert(unsigned int _index, const T& _value){
     return insert(_value);
}

template <typename T>
bool aghTree<T>::remove(unsigned int _index){
     //aghNode<T>* toRemove = findNode(_index);
     
}

template <typename T>
aghTree<T>& aghTree<T>::operator=(const aghContainer<T>& _right){


}

template <typename T>
aghNode<T> * aghTree<T>::findNode(aghNode<T> * node, unsigned int _calledIndex, unsigned int _currentIndex) const
{
    if(_calledIndex >  (size() - 1))
    {
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
    }
    
    while(_calledIndex != _currentIndex)
    {
        if(node->getPrev() != NULL)
            return findNode(node->getPrev(), _calledIndex, _currentIndex++);
        else if (node->getNext() != NULL)
            return findNode(node->getNext(), _calledIndex, _currentIndex++);
    }
    
    return node;
 }
#endif
