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

          aghTree<T>& operator=(const aghTree<T>& _right);
           
          aghNode<T> * inOrder(aghNode<T> * node, unsigned int _calledIndex, unsigned int & _currentIndex) const;
     
          aghNode<T> * preOrder(aghNode<T> * node, unsigned int _calledIndex, unsigned int & _currentIndex) const;
};
 
template <typename T>
aghTree<T>::aghTree():elementsCount(0), root(NULL)
{
}
 
template <typename T>
aghTree<T>::aghTree(const aghContainer<T>& _source)
{
}
 
template <typename T>
aghTree<T>::~aghTree(){
     //this->clear();
     elementsCount = 0;
     root = NULL;
}
 
template <typename T>
T& aghTree<T>::at(unsigned int _index) const
{
    /*
    if( _index >= size() )
    {
        throw aghException(0, "Index out of range", __FILE__, __LINE__);
    }
     */
    
    unsigned int _currentIndex = 0;
    return inOrder(root, _index + 1, _currentIndex)->getValue();
}
 
 
 
template <typename T>
unsigned int aghTree<T>::size(void) const{
     return elementsCount;
}
 
template <typename T>
bool aghTree<T>::insert(T const& _value)
{
    aghNode<T> *newNode = root, *temp = NULL;
     
    while(newNode)
    {
        temp = newNode;
        if(_value > newNode->getValue())
            newNode = newNode->getNext();
        else
            newNode = newNode->getPrev();
    }
     
    newNode = new aghNode<T>(_value);
     
    if(temp)
    {
        if(_value > temp->getValue())
            temp->setNext(newNode);
        else
            temp->setPrev(newNode);
    }
    else
    {
        root = newNode;
    }
    elementsCount++;
    return true;
}
 
template <typename T>
bool aghTree<T>::insert(unsigned int _index, const T& _value)
{
     return insert(_value);
}
 
template <typename T>
bool aghTree<T>::remove(unsigned int _index)
{
     if(_index < elementsCount)
     {
          aghNode<T>* temp = NULL;
          unsigned int i = 0;
        aghNode<T>* toRemove; //=  NIE MA FIND NODE findNode(root, _index+1, i);
          
          if(toRemove->getNext())
          {
               i = 0;
              temp; // NIE MA FIND NODE = findNode(root, _index+2, i);
          }
          else if(toRemove->getPrev())
          {
               i = 0;
              temp; //= NIE MA findNode(root, _index, i);
          }
          else
          {
               
          }
          
          temp->setNext(toRemove->getNext());
               temp->setPrev(toRemove->getPrev());
         delete toRemove;
          elementsCount--;
          return true;
     }
     else
     {
          return false;
     }
}
template <typename T>
aghTree<T>& aghTree<T>::operator=(const aghTree<T>& _right)
{
	unsigned int _currentIndex = 0;
	if(this != &right)
	{
		this->clear();
		for(unsigned int i = 0; i < _right.size(); i++)
		{
			_currentIndex = 0;
			this->append(_right.preOrder(root, i, _currentIndex));
		}
	}
	return *this;

}
template <typename T>
aghNode<T> * aghTree<T>::inOrder(aghNode<T> * node, unsigned int _calledIndex, unsigned int & _currentIndex) const
{
	aghNode<T> * temp = NULL;
	
    if (node->getPrev() != NULL)
        temp = inOrder(node->getPrev(), _calledIndex, _currentIndex);
	
	_currentIndex++;
	if (_calledIndex == _currentIndex)
		return node;
	
    if (node->getNext() != NULL && (_calledIndex > _currentIndex))
        temp = inOrder(node->getNext(), _calledIndex, _currentIndex);
	
	return temp;
}
 
template <typename T>
aghNode<T> * aghTree<T>::preOrder(aghNode<T> * node, unsigned int _calledIndex, unsigned int & _currentIndex) const
{
    aghNode<T> * temp = NULL;
     
    _currentIndex++;
    if (_calledIndex == _currentIndex)
        return node;
     
    if (node->getPrev() != NULL)
        temp = preOrder(node->getPrev(), _calledIndex, _currentIndex);
     
    if (node->getNext() != NULL && (_calledIndex > _currentIndex))
        temp = preOrder(node->getNext(), _calledIndex, _currentIndex);
     
    return temp;
}
 
#endif
