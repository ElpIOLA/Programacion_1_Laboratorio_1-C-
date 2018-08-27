#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"

// funciones privadas
int resizeUp(ArrayList* this);
int expand(ArrayList* this,int index);
int contract(ArrayList* this,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* this;
    ArrayList* returnAux = NULL;
    void* pElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            this->size=0;
            this->pElements=pElements;
            this->reservedSize=AL_INITIAL_VALUE;
            this->add=al_add;
            this->len=al_len;
            this->set=al_set;
            this->remove=al_remove;
            this->clear=al_clear;
            this->clone=al_clone;
            this->get=al_get;
            this->contains=al_contains;
            this->push=al_push;
            this->indexOf=al_indexOf;
            this->isEmpty=al_isEmpty;
            this->pop=al_pop;
            this->subList=al_subList;
            this->containsAll=al_containsAll;
            this->deleteArrayList = al_deleteArrayList;
            this->sort = al_sort;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this,void* pElement)
{
    int flag = 0;
    int returnAux = -1;
    if(this != NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
            flag = resizeUp(this);

        if(flag == 0)
        {
            *(this->pElements + al_len(this)) = pElement;
            returnAux = 0;
            this->size++;
        }

    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        free(this->pElements);
        free(this);
        retorno = 0;
    }

    return retorno;
}


/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->size;
    }
    return retorno;
}



/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this , int index)
{
    void* retorno = NULL;
    if(this != NULL && this->len(this) > index)
        retorno = *(this->pElements + index);
    return retorno;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int i;
    int retorno = -1;
    if(this != NULL && pElement != NULL)
    {
        retorno = 0;
        for(i = 0; i < this->len(this); i++)
        {
            if(pElement == *(this->pElements + i))
            {
                retorno = 1;
                break;
            }
        }
    }

    return retorno;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int retorno = -1;
    if(this != NULL && pElement != NULL && this->len(this) > index && index >= 0)
    {
        *(this->pElements + index) = pElement;
        retorno = 0;
    }

    return retorno;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int retorno = -1;
    if(this != NULL && this->len(this) > index)
    {
        contract(this, index);
        retorno = 0;
    }

    return retorno;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int retorno = -1;
    if(this != NULL)
    {
        this->size = 0;
        retorno = 0;
    }

    return retorno;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    int i;
    ArrayList* retorno = NULL;
    ArrayList* new = al_newArrayList();
    if(new != NULL && this != NULL)
    {
        for(i = 0; i < this->len(this); i++)
        {
            al_add(new, *(this->pElements + i));
        }
        retorno = new;
    }

    return retorno;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this != NULL && pElement != NULL && this->len(this) > index && index >= 0)
    {
        expand(this, index);
        *(this->pElements + index) = pElement;
        returnAux = 0;
    }
    if(index == this->len(this))
    {
        al_add(this, pElement);
        returnAux = 0;
    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int i;
    int retorno = -1;
    if(this != NULL && pElement != NULL)
    {
        for(i = 0; i < this->len(this); i++)
        {
            if(pElement == *(this->pElements + i))
            {
                retorno =  i;
                break;
            }
        }
    }

    return retorno;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int retorno = -1;
    if(this != NULL)
        retorno = (this->len(this) == 0) ? 1 : 0;
    return retorno;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index < this->len(this))
    {
        returnAux = al_get(this, index);
        al_remove(this, index);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    ArrayList* retorno = NULL;
    int i;
    ArrayList* new = al_newArrayList();
    if(this != NULL && new != NULL && from >= 0 && from < to && to <= this->len(this))
    {
        for(i = from; i < to; i++)
        {
            al_add(new, *(this->pElements + i));
        }
        retorno = new;
    }

    return retorno;
}




/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int retorno = -1;
    int i;
    if(this != NULL && this2 != NULL)
    {
        retorno = 1;
        for(i = 0; i < this2->len(this2); i++)
        {
            if(al_contains(this, *(this2->pElements + i)) == 0)
            {
                retorno = 0;
                break;
            }
        }
    }
    return retorno;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int retorno = -1;
    int i;
    int j;
    void* aux;
    if(this != NULL && pFunc != NULL && (order == 1 || order == 0))
    {
        for(i = 0; i < (this->len(this) - 1); i++)
        {
            for(j = i + 1; j < this->len(this); j++)
            {
                switch(order)
                {
                case 1:
                    if(pFunc(*(this->pElements + i), *(this->pElements + j)) == 1)
                    {
                        aux = *(this->pElements + i);
                        *(this->pElements + i) = *(this->pElements + j);
                        *(this->pElements + j) = aux;
                    }
                    break;

                case 0:
                    if(pFunc(*(this->pElements + i), *(this->pElements + j)) == -1)
                    {
                        aux = *(this->pElements + j);
                        *(this->pElements + j) = *(this->pElements + i);
                        *(this->pElements + i) = aux;
                    }
                    break;
                }
            }
        }
        retorno = 0;
    }

    return retorno;
}

/** \brief  Genera una nueva lista sin los elementos filtrados
 * \param listIn ArrayList* Pointer to arrayList
 * \param functionFilter funcion de filtrado
 * \return ArrayList* retorno NULL pointer if Error [listIn is NULL pointer or functionFilter is NULL pointer]
 *                  - pointer to new list if Ok
 */
ArrayList* al_filter(ArrayList* listIn, int(*functionFilter)(void*))
{
    void* aux;
    int i;
    ArrayList* retorno = NULL;
    if(listIn != NULL && functionFilter != NULL)
    {
        retorno = al_newArrayList();
        if(retorno != NULL)
        {
            for(i = 0; i < listIn->len(listIn); i++)
            {
                aux = listIn->get(listIn, i);
                if(functionFilter(aux) == 1)
                {
                    retorno->add(retorno, aux);
                }
            }
        }
    }
    return retorno;
}

/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** aux;
    aux = (void**) realloc(this->pElements, sizeof(void*) * (this->reservedSize + AL_INCREMENT));
    if(aux != NULL)
    {
        this->pElements = aux;
        this->reservedSize = this->reservedSize + AL_INCREMENT;
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* this,int index)
{
    int i;
    int returnAux = -1;
    if(this != NULL && index < this->len(this) && index >= 0)
    {
        this->add(this, &returnAux); // NO LE PUEDO PASAR NULL
        for(i = this->len(this) -1; i > index; i--)
        {
            *(this->pElements + i) = *(this->pElements + (i - 1));
        }
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;
    if(this != NULL && index < this->len(this) && index >= 0)
    {
        for(i = index; i < (this->len(this) -1); i++)
        {
            *(this->pElements + i) = *(this->pElements + i + 1);
        }
        this->size--;
        returnAux = 0;
    }
    return returnAux;
}
