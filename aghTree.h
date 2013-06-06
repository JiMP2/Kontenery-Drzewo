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
          aghTree<T>& operator=(aghContainer<T> const& _right);
          
          //\brief Going through the elements using in-order
          //
          //\param node - node from which we start searching
          //\param _calledIndex - index of an element we are looking for
          //\param _currentIndex - index during searching
          //\return pointer to the searched node 
          aghNode<T> * inOrder(aghNode<T> * node, unsigned int _calledIndex, unsigned int & _currentIndex) const;
          
          //\brief Going through the elements using pre-order
          //
          //\param node - node from which we start searching
          //\param _calledIndex - index of an element we are looking for
          //\param _currentIndex - index during searching
          //\return pointer to the searched node
          aghNode<T> * preOrder(aghNode<T> * node, unsigned int _calledIndex, unsigned int & _currentIndex) const;
          
          //\brief Function finding parent of node
          //
          //\param node - node for which parent we are looking
          //\return pointer to parent of node
          aghNode<T>* findParent(aghNode<T>* node) const;
};
 
template <typename T>
aghTree<T>::aghTree():elementsCount(0), root(NULL)
{
}
 
template <typename T>
aghTree<T>::aghTree(const aghContainer<T>& _source):elementsCount(_source.size()),root(NULL)
{
     for(unsigned int i = 0; i < _source.size(); i++)
	{
		this->append(_source.at(i));
	}
}
 
template <typename T>
aghTree<T>::~aghTree(){
     this->clear();
     elementsCount = 0;
     root = NULL;
}
 
template <typename T>
T& aghTree<T>::at(unsigned int _index) const
{
    if( _index >= size() )
    {
          throw aghException(0, "Index out of range", __FILE__, __LINE__);
    }
    unsigned int i = 0;
    return inOrder(root, _index + 1, i)->getValue();
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
          unsigned int i = 0;
          _index++;
          aghNode<T>* toRemove = inOrder(root, _index, i);
          aghNode<T>* parent = findParent(toRemove);
          aghNode<T>* temp = NULL;
          
          if( toRemove->getPrev() == NULL && toRemove->getNext() == NULL )
          {
               temp = NULL;
          }
          else if( toRemove->getPrev() != NULL && toRemove->getNext() == NULL )
          {
               temp = toRemove->getPrev();
          }
          else if( toRemove->getPrev() == NULL && toRemove->getNext() != NULL )
          {
               temp = toRemove->getNext();              
          }
          else if( toRemove->getPrev() != NULL && toRemove->getNext() != NULL )
          {
               i = 0;
               temp = inOrder(root, _index+1, i);
               temp->setPrev(toRemove->getPrev());
               temp->setNext(toRemove->getNext());
          }
          
          if(parent)
          {
               if(parent->getPrev() == toRemove)
               {
                    parent->setPrev(temp);
               }
               else if(parent->getNext() == toRemove)
               {
                    parent->setNext(temp);
               }
          }
          else
          {
               root = temp;
          }
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
aghTree<T>& aghTree<T>::operator=(aghContainer<T> const& _right)
{
	if(this != &right)
	{
		this->clear();
		for(unsigned int i = 0; i < _right.size(); i++)
		{
			this->append(_right.at(i));
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

template <typename T>
aghNode<T>* aghTree<T>::findParent(aghNode<T>* node) const
{
     aghNode<T>* temp = NULL;
     unsigned int j = 0;
     for(unsigned int i = 0; i < elementsCount; i++)
     {
          temp = preOrder(root, i+1, j);
          j = 0;
          if( temp->getNext() == node || temp->getPrev() == node )
          {
               return temp;
          }
     }
     return NULL;
}
 
#endif
