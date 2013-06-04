#ifndef AGHTREE_H
#define AGHTREE_H

template <class T>
class aghTree : public aghContainer{
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
          
          //\brief Method to remove element from the list.
          //
          //\param _index - position from where we want remove element
          //\return TRUE if finished successfully ( FALSE otherwaise )
          bool remove(unsigned int _index);
          
          //\brief Overload of operator=
          //
          //\param - source aghVector<T> object
          //\return reference to 'this' object
          aghDlist<T>& operator=(const aghContainer<T>& _right);
};

template <typename T>
aghTree<T>::aghTree():elementsCount(0), root(NULL){
}

template <typename T>
aghTree<T>::aghTree(const aghContainer<T>& _source){

}

template <typename T>
aghTree<T>::~aghTree(){
     this->clear();
     elementsCount = 0;
     root = NULL;
}

T& aghTree<T>::at(unsigned int _index) const{

}

unsigned int aghTree<T>::size(void) const{
     return elementsCount;
}

bool aghTree<T>::insert(T const& _value){


}

bool aghTree<T>::remove(unsigned int _index){

}

aghTree<T>& aghTree<T>::operator=(const aghContainer<T>& _right){


}

IN-ORDER(wierzchołek_v, int szukanyIndeks, int obecnyIndeks)
 {
     if (obecnyIndeks == szukanyIndeks)
    {
         return obecnyWierzcholek
    }
    jeżeli wierzchołek_v.lewy_syn != null to IN-ORDER(wierzchołek_v.lewy_syn)
     obecnyIndeks++
    jeżeli wierzchołek_v.prawy_syn != null to IN-ORDER(wierzchołek_v.prawy_syn)
 }
#endif
