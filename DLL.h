
#ifndef  DLL_INC
#define  DLL_INC

#include <stdlib.h>   // Para malloc, calloc, etc y size_t
#include <stdbool.h>  // Para bool, etc
#include <assert.h>

typedef int Item;


typedef struct Node_t
{
	Item datos;
	struct Node_t* next;
	struct Node_t* prev;
} Node;


typedef Node* NodePtr;  // Node* = NodePtr

typedef struct
{
	NodePtr first;
	NodePtr last;
	NodePtr cursor;
	size_t len;
} DLL;


/**
 * @brief Crea una lista doblemente enlazada
 *
 * @return Una referencia a la nueva lista
 * @post Una lista existente en el heap
 */
DLL* DLL_New();

void DLL_Delete( DLL** this );

bool Insert_front( DLL* this, Item x );
bool Insert_back( DLL* this, Item x );

/**
 * @brief Inserta un elemento a la derecha del cursor.
 *
 * @param lista Una referencia a la lista de trabajo
 * @param x El elemento a insertar
 *
 * @return true si el valor se insertó en la lista; false en caso
 * contrario. Esto podría suceder si la memoria se agotó.
 */
bool DLL_Insert( DLL* this, Item x );


/**
 * @brief Remueve el elemento al frente de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void DLL_Remove_front( DLL* this );


/**
 * @brief Remueve el elemento al fondo de la lista.
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mantiene en la posición en la que estaba cuando entró la
 * función.
 */
void DLL_Remove_back( DLL* this );


/**
 * @brief Remueve el elemento apuntado por el cursor
 *
 * @param this Referencia a una lista.
 *
 * @post El cursor se mueve al elemento a la derecha del nodo borrado.
 */
void DLL_Remove( DLL* this );


/**
 * @brief Devuelve una copia del valor apuntado por el cursor.
 *
 * @param this Una referencia a la lista de trabajo
 *
 * @return El valor apuntado por el cursor
 */
int DLL_Get( DLL* this );

/**
 * @brief Manda al cursor al inicio de la lista
 *
 * @param lista Una referencia a la lista de trabajo
 */
void DLL_Cursor_front( DLL* this );

void DLL_Cursor_back( DLL* this );
void DLL_Cursor_next( DLL* this );
void DLL_Cursor_prev( DLL* this );

bool DLL_IsEmpty( DLL* this );
size_t DLL_Len( DLL* this );

/**
 * @brief Elimina todos los elementos de la lista sin eliminar la lista.
 *
 * @param this Referencia a una lista.
 */
void DLL_MakeEmpty( DLL* this );

/**
 * @brief Recorre la lista y hace algo en cada uno de sus elementos
 *
 * @param lista Una referencia a la lista de trabajo
 * @param fn Esta función hace algo con el campo de datos
 */
void DLL_Traverse( DLL* this, void (*fn)( int item ) );


#endif   /* ----- #ifndef DLL_INC  ----- */
