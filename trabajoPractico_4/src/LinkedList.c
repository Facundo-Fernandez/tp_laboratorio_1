#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../inc/LinkedList.h"


static Node* getNode(LinkedList* this, int nodeIndex);
static int addNode(LinkedList* this, int nodeIndex,void* pElement);

/** \brief Crea un nuevo LinkedList en memoria de manera dinamica
 *
 *  \param void
 *  \return LinkedList* Retorna (NULL) en el caso de no conseguir espacio en memoria
 *                      o el puntero al espacio reservado
 */
LinkedList* ll_newLinkedList(void)
{
    LinkedList* this;
    this = (LinkedList *)malloc(sizeof(LinkedList));
    if(this != NULL)
    {
        this->size = 0;
        this->pFirstNode = NULL;
    }
    return this;
}

/** \brief Retorna la cantidad de elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna (-1) si el puntero es NULL o la cantidad de elementos de la lista
 *
 */
int ll_len(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        returnAux = this->size;
    }

    return returnAux;
}


/** \brief  Obtiene un nodo de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
static Node* getNode(LinkedList* this, int nodeIndex)
{
    Node* pNode = NULL;
    int listLength = ll_len(this);
    int i;
    if(this != NULL && nodeIndex >= 0 && nodeIndex < listLength)
    {
        pNode = this -> pFirstNode;
            for(i=0; i < nodeIndex; i++)
            {
                pNode = pNode->pNextNode;
            }
    }
    return pNode;
}

/** \brief  Permite realizar el test de la funcion getNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param index int Indice del nodo a obtener
 * \return Node* Retorna  (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        (pElement) Si funciono correctamente
 *
 */
Node* test_getNode(LinkedList* this, int nodeIndex)
{
    return getNode(this, nodeIndex);
}


/** \brief Agrega y enlaza un nuevo nodo a la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
static int addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    int returnAux = -1;
    Node* pNewNode = malloc(sizeof(Node));
    Node* pNode = NULL;
    pNewNode->pElement = pElement;

    if(this != NULL && nodeIndex >= 0 && nodeIndex <= this->size && pNewNode != NULL)
    {
        if(nodeIndex==0)
        {
            pNewNode->pNextNode = this->pFirstNode;
            this->pFirstNode = pNewNode;
            this->size++;
            returnAux = 0;
        }
        else
        {
            pNode = getNode(this, nodeIndex-1);
            pNewNode->pNextNode = pNode->pNextNode;
            pNode->pNextNode = pNewNode;
            this->size++;
            returnAux = 0;
        }
    }
    return returnAux;
}


/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo nodo
 * \param pElement void* Puntero al elemento a ser contenido por el nuevo nodo
  * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int test_addNode(LinkedList* this, int nodeIndex,void* pElement)
{
    return addNode(this,nodeIndex,pElement);
}


/** \brief  Agrega un elemento a la lista
 * \param pList LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento a ser agregado
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_add(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this!=NULL && addNode(this, this->size, pElement) == 0)
    {
        returnAux = 0;
    }

    return returnAux;
}

/** \brief Permite realizar el test de la funcion addNode la cual es privada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a obtener
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_get(LinkedList* this, int index)
{
    void* returnAux = NULL;
    Node* pNode;
    if(this != NULL && index >= 0 && index < this->size)
    {
        pNode = getNode(this, index);
        if(pNode != NULL)
        {
            returnAux = pNode->pElement;
        }
    }

    return returnAux;
}


/** \brief Modifica un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a modificar
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_set(LinkedList* this, int index,void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    if(this!= NULL && index >= 0 && index < this->size)
    {
        returnAux = 0;
        pNode = getNode(this,index);
        if(pNode != NULL)
        {
            pNode->pElement = pElement;
        }
    }

    return returnAux;
}


/** \brief Elimina un elemento de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento a eliminar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_remove(LinkedList* this,int index)
{
    int returnAux = -1;
    Node* pNodeA;
    Node* pNodeB;
    if(this != NULL && index >= 0 && index < this->size)
    {
        returnAux = 0;
        if(this -> size == 1)
        {
            this->pFirstNode = NULL;
            this->size--;
            pNodeA = getNode(this,index);
            free(pNodeA);
        }
        else
        {
        pNodeA = getNode(this,index);
            if(pNodeA != NULL)
            {
                pNodeB = getNode(this,index-1);
                pNodeB->pNextNode = pNodeA->pNextNode;
                this -> size--;
                free(pNodeA);
            }
        }
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_clear(LinkedList* this)
{
    int returnAux = -1;
    Node* pNodeA;
    Node* pNodeB;
    int i;
    if(this!= NULL)
    {
        if(!this->size)
        {
            returnAux = 0;
        }
        else
        {
            for(i=0; i < this->size; i++)
            {
                pNodeA = getNode(this,i);
                if(pNodeA != NULL)
                {
                    pNodeB = pNodeA -> pNextNode;
                    free(pNodeA);
                }
            }
            free(pNodeB);
            returnAux = 0;
        }
        this->size = 0;
    }
    return returnAux;
}


/** \brief Elimina todos los elementos de la lista y la lista
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si funciono correctamente
 *
 */
int ll_deleteLinkedList(LinkedList* this)
{
    int returnAux = -1;
    if(this != NULL)
    {
        ll_clear(this);
        free(this);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Busca el indice de la primer ocurrencia del elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero al elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        (indice del elemento) Si funciono correctamente
 *
 */
int ll_indexOf(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    Node* pNode;
    int i;
    if(this != NULL)
    {
        for(i=0; i < this->size; i++)
        {
            pNode = getNode(this,i);
            if(pNode != NULL && pNode->pElement == pElement)
            {
                returnAux=i;
            }
        }
    }

    return returnAux;
}

/** \brief Indica si la lista esta o no vacia
 *
 * \param this LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 0) Si la lista NO esta vacia
                        ( 1) Si la lista esta vacia
 *
 */
int ll_isEmpty(LinkedList* this)
{
    int returnAux = -1;
    if(this!=NULL)
    {
       if(this->size == 0)
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

/** \brief Inserta un nuevo elemento en la lista en la posicion indicada
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion donde se agregara el nuevo elemento
 * \param pElement void* Puntero al nuevo elemento
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                        ( 0) Si funciono correctamente
 *
 */
int ll_push(LinkedList* this, int index, void* pElement)
{
    int returnAux = -1;
    if(this!= NULL && index >= 0 && index <= this->size && addNode(this,index,pElement) == 0)
    {
        returnAux=0;
    }
    return returnAux;
}


/** \brief Elimina el elemento de la posicion indicada y retorna su puntero
 *
 * \param this LinkedList* Puntero a la lista
 * \param nodeIndex int Ubicacion del elemento eliminar
 * \return void* Retorna    (NULL) Error: si el puntero a la lista es NULL o (si el indice es menor a 0 o mayor al len de la lista)
                            (pElement) Si funciono correctamente
 *
 */
void* ll_pop(LinkedList* this,int index)
{
    void* returnAux = NULL;
    if(this != NULL && index >= 0 && index < this->size)
    {
        returnAux = ll_get(this, index);
        ll_remove(this, index);
    }
    return returnAux;
}


/** \brief  Determina si la lista contiene o no el elemento pasado como parametro
 *
 * \param this LinkedList* Puntero a la lista
 * \param pElement void* Puntero del elemento a verificar
 * \return int Retorna  (-1) Error: si el puntero a la lista es NULL
                        ( 1) Si contiene el elemento
                        ( 0) si No contiene el elemento
*/
int ll_contains(LinkedList* this, void* pElement)
{
    int returnAux = -1;
    if(this != NULL)
    {
        if(ll_indexOf(this, pElement) == -1)
        {
            returnAux = 0;
        }
        else
        {
            returnAux = 1;
        }
    }
    return returnAux;
}

/** \brief  Determina si todos los elementos de la lista (this2)
            estan contenidos en la lista (this)
 *
 * \param this LinkedList* Puntero a la lista
 * \param this2 LinkedList* Puntero a la lista
 * \return int Retorna  (-1) Error: si alguno de los punteros a las listas son NULL
                        ( 1) Si los elementos de (this2) estan contenidos en la lista (this)
                        ( 0) si los elementos de (this2) NO estan contenidos en la lista (this)
*/
int ll_containsAll(LinkedList* this,LinkedList* this2)
{
    int returnAux = -1;
    int i;
    void* auxLL;

    if(this != NULL && this2 != NULL)
    {
        returnAux = 1;
        for(i=0; i < ll_len(this2); i++)
        {
            auxLL = ll_get(this2, i);

            if(ll_contains(this, auxLL) == 0)
            {
                returnAux = 0;
            }
        }
    }
    return returnAux;
}

/** \brief Crea y retorna una nueva lista con los elementos indicados
 *
 * \param pList LinkedList* Puntero a la lista
 * \param from int Indice desde el cual se copian los elementos en la nueva lista
 * \param to int Indice hasta el cual se copian los elementos en la nueva lista (no incluido)
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                o (si el indice from es menor a 0 o mayor al len de la lista)
                                o (si el indice to es menor o igual a from o mayor al len de la lista)
                         (puntero a la nueva lista) Si ok
*/
LinkedList* ll_subList(LinkedList* this,int from,int to)
{
    LinkedList* subList = NULL;
    void* auxElement;
    int i;

    if(this != NULL && from >= 0 && to <= ll_len(this) && to > from)
    {
        subList = ll_newLinkedList();

        for(i=from;i < to;i++)
        {
            auxElement = ll_get(this,i);
            ll_add(subList,auxElement);
        }
    }
    return subList;
}

/** \brief Crea y retorna una nueva lista con los elementos de la lista pasada como parametro
 *
 * \param pList LinkedList* Puntero a la lista
 * \return LinkedList* Retorna  (NULL) Error: si el puntero a la listas es NULL
                                (puntero a la nueva lista) Si ok
*/
LinkedList* ll_clone(LinkedList* this)
{
    LinkedList* cloneArray = NULL;
    int i;
    void* auxElement;

    if(this != NULL)
    {
        cloneArray = ll_newLinkedList();
        for(i=0;i<ll_len(this);i++)
        {
            auxElement = ll_get(this,i);
            ll_add(cloneArray,auxElement);
        }
    }
    return cloneArray;
}


/** \brief Ordena los elementos de la lista utilizando la funcion criterio recibida como parametro
 * \param pList LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \param order int  [1] Indica orden ascendente - [0] Indica orden descendente
 * \return int Retorna  (-1) Error: si el puntero a la listas es NULL
                                ( 0) Si ok
 */
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order)
{
    int returnAux =-1;
    int i;
    Node* pNode;
    Node* pNextNode;
    int length;
    void* auxElement;
    int swapFlag;

    if(this != NULL && pFunc != 0 && (order == 1 || order == 0) && this->size > 0)
    {
        length = this->size;
        do{
            swapFlag = 0;
            pNode = this->pFirstNode;
            if(pNode != NULL)
            {
                pNextNode = pNode->pNextNode;
                for(i=0; i<length; i++)
                {
                    if((pFunc(pNode->pElement, pNextNode->pElement) == 1 && order == 1) || (pFunc(pNode->pElement, pNextNode->pElement) == -1 && order == 0))
                    {
                        auxElement = pNode->pElement;
                        pNode->pElement = pNextNode->pElement;
                        pNextNode->pElement = auxElement;
                        swapFlag = 1;
                    }
                    if(pNextNode->pNextNode!=NULL)
                    {
                        pNode=pNextNode;
                    }
                    else
                    {
                        break;
                    }
                    pNextNode = pNode->pNextNode;
                }
            }
        }
        while(swapFlag == 1);
        returnAux = 0;
    }
    return returnAux;
}

/** \brief Filtra la lista usando como criterio la función pFunc
 * \param this LinkedList* Puntero a la lista
 * \param pFunc (*pFunc) Puntero a la funcion criterio
 * \return Si pudo llevar a cabo la operación, denota 0; caso contrario denota -1.
 */

LinkedList* ll_filter(LinkedList* this, int (*pFunc)(void*))
{
    LinkedList* llAux = NULL;
    llAux = ll_newLinkedList();
    int returnAux = -1;
    int i;
    int length;
    void* pElementAux = NULL;
    int auxFunc;
    if (this != NULL && pFunc != NULL)
    {
        length = ll_len(this);
        for(i=0; i<length; i++)
        {
            pElementAux = ll_get(this,i);
            auxFunc = pFunc(pElementAux);
            if(auxFunc == 1 && pElementAux != NULL)
            {
                ll_add(llAux,pElementAux);
            }
        }
        returnAux = 0;
    }
    return returnAux;
}
