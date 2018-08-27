#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
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
    void** auxpElements;
    this = (ArrayList *)malloc(sizeof(ArrayList));

    if(this != NULL)
    {
        auxpElements = (void**) malloc(sizeof(void *)*AL_INITIAL_VALUE);
        if(auxpElements != NULL)
        {
            this->size=0;
            this->pElements=auxpElements;
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
            this->filter = al_filter;
            returnAux = this;
        }
        else
        {
            free(this);
        }
    }

    return returnAux;
}


/** \brief  Agregue un elemento a arrayList y si es
 *          necesario cambia el tamaño de la matriz
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* this, void* pElement)
{
    int returnAux = -1;
    void** pAux;
    int flag = 0;

    if(this != NULL && pElement != NULL)
    {
        if(this->size == this->reservedSize)
        {
            pAux = (void **) realloc(this->pElements,sizeof(void*) * (this->reservedSize+AL_INCREMENT));
            if(pAux != NULL)
            {
                this->pElements = pAux;
                this->reservedSize = this->reservedSize + AL_INCREMENT;
            }
            else
            {
                flag = 1;
            }
        }
        if(flag == 0)
        {
            this->pElements[this->size] = pElement;
            this->size ++;
            returnAux = 0;
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
    int returnAux = -1;

    if(this != NULL)
    {
        if(this->pElements != NULL)
        {
            free(this->pElements);
        }
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* this){

    int returnAux = -1;

    if(this != NULL)
    {
        if((this->size)==0)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = this->size;
        }
    }
    return returnAux;
}


/** \brief  Obtener un elemento por índice
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* this, int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index <= this->len(this))
    {
        returnAux = *(this->pElements+index);
    }
    return returnAux;
}


/** \brief  Encuentre si pList contiene al menos un elemento pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* this, void* pElement)
{
    int returnAux = -1,i;

    if(this != NULL && pElement != NULL)
    {
        for(i=0;i<this->size;i++)
        {
            if(*(this->pElements+i) == pElement)
            {
                returnAux = 1;
                break;
            }
            else
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}


/** \brief  Establecer un elemento en pList en posición de índice
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* this, int index,void* pElement)
{
    int returnAux = -1;

    if(this != NULL && pElement != NULL)
    {
        if(index >= 0 && index <= this->len(this))
        {
            if(index < this->len(this))
            {
                *(this->pElements+index) = pElement;
            }
            else
            {
                al_add(this,pElement);
            }
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief  Eliminar un elemento por índice
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* this,int index)
{
    int returnAux = -1;

    if (this != NULL && (index <= this->len(this) && index >-1))
    {
        returnAux = contract(this, index);
    }
    return returnAux;
}



/** \brief Elimina todos los elementos de esta lista
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* this)
{
    int returnAux = -1;

    if (this != NULL)
    {
        this->pElements = (void**)realloc(this->pElements, sizeof(void*)*AL_INITIAL_VALUE);
        if (this != NULL)
        {
            this->size = 0;
            this->reservedSize = AL_INITIAL_VALUE;
        }
        returnAux = 0;
    }
    return returnAux;
}



/** \brief Devuelve una matriz que contiene todos los elementos de esta lista en la secuencia correcta
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* this)
{
    ArrayList* returnAux = NULL;

    if (this != NULL)
    {
        returnAux = (ArrayList*)malloc(sizeof(ArrayList)*this->len(this));
        if (returnAux != NULL)
        {
            returnAux = this;
        }
    }
    return returnAux;
}




/** \brief Inserta el elemento en la posición especificada
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* this, int index, void* pElement)
{
    int returnAux = -1, i;

    if(this != NULL && pElement != NULL)
    {
        if(index >= 0 && index <= this->len(this))
        {
            al_add(this,pElement);
            if(index != this->len(this))
            {
                for(i=this->size-1;i>=index;i--)
                {
                    *(this->pElements+i) = *(this->pElements+(i-1));
                }
                al_set(this,index,pElement);
            }
            returnAux = 0;
        }
    }
    return returnAux;
}



/** \brief Devuelve el índice de la primera aparición del elemento especificado
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* this, void* pElement)
{
    int returnAux = -1, i;
    if(this != NULL && pElement != NULL)
    {
        for(i=0;i<this->size;i++)
        {
            if(*(this->pElements+i) == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }
    return returnAux;
}



/** \brief Devuelve verdadero si esta lista no contiene elementos.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(this->len(this) == 0)
        {
            returnAux = 1;
        }
        else
        {
            returnAux = 0;
        }
    }
    return returnAux;
}




/** \brief Retire el artículo en la posición dada en la lista y devuélvalo.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) si Error [pList es puntero NULL o índice no válido]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && (index > -1 && index < this->len(this)))
    {
       returnAux = *(this->pElements+index);
       contract(this,index);
    }
    return returnAux;
}


/** \brief Devuelve una nueva lista de arreglos con una porción de pList entre los especificados
 *         fromIndex, inclusive y toIndex, exclusivo.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* this,int from,int to)
{
    int i;
    void* returnAux = NULL;
    ArrayList* pAux;

    if(this != NULL)
    {
        pAux = al_newArrayList();
        if(pAux != NULL && from >= 0 && from < to && to >= 0 && to <= this->len(this))
        {
            for(i=from;i<to;i++)
            {
                al_add(pAux,*(this->pElements+i));
            }
            returnAux = pAux;
        }
    }
    return returnAux ;
}





/** \brief Devuelve true si la lista pList contiene todos los elementos de pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* this,ArrayList* this2)
{
    int returnAux = -1,i;
    if(this !=  NULL && this2 != NULL)
    {
        for(i=0;i<this->size;i++)
        {
            if(this->len(this) == al_len(this2))
            {
                if(*(this->pElements+i) == *(this2->pElements+i))
                {
                    returnAux = 1;
                }
                else
                {
                    returnAux = 0;
                }
            }
            else
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Ordena los objetos de la lista, use comparar pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    int i;
    int j;
    void* auxElements;

    if ((this != NULL && pFunc != NULL) && (order == 1 || order == 0))
    {
        returnAux = 0;
        for (i=0 ; i<this->len(this)-1 ; i++)
        {
            for (j=i+1 ; j<this->len(this) ; j++)
            {
                if (order == 1)
                {
                    if (pFunc(*(this->pElements+i), *(this->pElements+j)) > 0)
                    {
                        auxElements = *(this->pElements+i);
                        *(this->pElements+i) = *(this->pElements+j);
                        *(this->pElements+j) = auxElements;
                    }
                }
                else
                {
                    if (pFunc(*(this->pElements+i), *(this->pElements+j)) < 0)
                    {
                        auxElements = *(this->pElements+j);
                        *(this->pElements+j) = *(this->pElements+i);
                        *(this->pElements+i) = auxElements;
                    }
                }
            }
        }
    }
    return returnAux;
}

ArrayList* al_filter(ArrayList* listln, int(*functionFilter)(void*))
{
    ArrayList* aux = NULL;
    void* item;
    int i, len, index;
    if(listln != NULL && (functionFilter) != NULL)
    {
        aux = al_newArrayList();
        len = al_len(listln);
        if(aux != NULL)
        {
            if(listln->isEmpty(listln) == 0)
            {
                for(i=0;i<len;i++)
                {
                    item = al_get(listln,i);
                    index = functionFilter(item);
                    if(index == 1)
                    {
                        aux->add(aux,item);
                    }
                }
            }
        }
    }
    return aux;
}

/** \brief Incremente la cantidad de elementos en pList en elementos AL_INCREMENT.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* this)
{
    int returnAux = -1;
    void** aux;

    if(this != NULL)
    {
        aux = (void**) realloc(this->pElements, sizeof(void*)*(this->reservedSize + AL_INCREMENT));
        if(aux != NULL)
        {
            this->pElements = aux;
            this->reservedSize = this->reservedSize + AL_INCREMENT;
            returnAux = 0;
        }
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
    int returnAux = -1;
    int j, i, ok;

    if(this!=NULL && index >= 0 && index < this->size)
    {
        this->size+=1;
        if((this->reservedSize - this->size) > 10)
        {
            ok = resizeUp(this);
            if(ok != 0)
            {
                return 0;
            }
        }
        for(i=this->len(this); i>index; i--)
        {
            j = i-1;
            *(this->pElements+i) = *(this->pElements+j);
        }
        returnAux = 0;
    }
    return returnAux;
}

/** \brief  Contrae una lista de matriz
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* this,int index)
{
    int returnAux = -1;
    int i;

    if (this != NULL && (index < al_len(this) && index >-1))
    {
        for (i=index; i<this->size ; i++)
        {
            *(this->pElements+i) = *(this->pElements+(i+1));
        }
        returnAux = 0;
        this->size--;
    }
    return returnAux;
}
