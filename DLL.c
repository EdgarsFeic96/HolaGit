// Alumno: Gonzalez Romero Daniel Vicente

#include "DLL.h"

static NodePtr newNode( Item dato )
{
    NodePtr n = malloc( sizeof(Node) );
    if( NULL != n ){
        n->datos = dato;
        n->next = NULL;
        n->prev = NULL;
    } else{
        printf("\nError de asignación de memoria\n");
        n = NULL;
        exit(1);
    }
    return n;
}

DLL* DLL_New()
{
    DLL* lst = malloc( sizeof(DLL) );
    if( lst == NULL ){
        printf("\nError de asignación de memoria\n");
        lst = NULL;
        exit(1);
    } else{
        lst->first = lst->last = lst->cursor = NULL;
        lst->len = 0;
    }
    return lst;
}

void DLL_Delete( DLL** this )
{
    assert( *this );

    // Primero borramos todos los nodos
    DLL_Cursor_front( *this );
    for( size_t i=0; i< (*this)->len; ++i ){   //OJO, si se hace <= (*this)->len, cuando len sea igual que cero ingresara nuevamente al ciclo y genera un ERROR

        NodePtr tmp = (*this)->first->next;
        free( (*this)->first );
        (*this)->first = tmp;
        --(*this)->len;
    }

    // Despues borramos al objeto (lista) en si mismo
    free( *this );

    // Hacemos que this sea NULL
    *this = NULL;
}


bool DLL_Insert( DLL* this, Item dato )
{
    assert( this );
    assert( this->cursor );

    bool res = false;
    NodePtr n = newNode(dato);

    if( this->len == 0 ){
        this->first = this->cursor = this->last = n;
        res = true;
    } else{
        NodePtr tmp = this->cursor->next;
        this->cursor->next = n;
        n->prev = this->cursor;
        n->next = tmp;

        if( this->cursor == this->last ){
            this->last = n;
            res = true;
        } else{
            tmp->prev = n;
            this->cursor = n; //Movemos el cursor a la derecha
            res = true;
        }

    }

    ++this->len;
    return res;

}


bool DLL_Insert_front( DLL* this, Item dato )
{
    bool cond = false;

    NodePtr n = newNode( dato );
    if( DLL_IsEmpty( this ) ){
        this->first = this-> last = this->cursor = n;
        cond = true;
    } else{
        n->next = this->first;
        this->first->prev = n;
        this->first = n;
        cond = true;
    }
    ++this->len;

    return cond;
}

bool DLL_Insert_back( DLL* this, Item dato )
{
    bool cond = false;

    NodePtr n = newNode( dato );
    if( DLL_IsEmpty( this ) ){
        this->first = this-> last = this->cursor = n;
        cond = true;
    } else{
        n->prev = this->last;
        this->last->next = n;
        this->last = n;
        cond = true;
    }
    ++this->len;

    return cond;
}

void DLL_Remove( DLL* this )
{
    assert( this->first );
    assert( this->cursor );

    if( this->len == 1 ){
        free( this->first );
        this->cursor = this->first = this->last = NULL;

    } else if( this->cursor == this->first ){
        NodePtr tmp = this->first->next;
		free(this->first);
		this->first = tmp;
		tmp->prev = NULL;
        this->cursor = this->first->next;

    } else if( this->cursor == this->last ){
        NodePtr tmp = this->last->prev;
		free(this->last);
		this->last = tmp;
		tmp->next = NULL;
        this->cursor = this->first;

    } else{
        NodePtr tmp1 = this->cursor->prev;
        NodePtr tmp2 = this->cursor->next;

        free( this->cursor );
        tmp1->next = tmp2;
        tmp2->prev = tmp1;
        this->cursor = tmp2;
    }
    --this->len;
}

void DLL_Remove_front( DLL* this )
{
    assert( this->first );

    if( this->len == 1 ){
        free( this->first );
        this->first = this->last = this->cursor = NULL;
    } else{
        NodePtr tmp = this->first->next;
        free( this->first );
        this->first = tmp;
        tmp->prev = NULL;
    }
    --this->len;
}

void DLL_Remove_back( DLL* this )
{
    assert( this->first );

    if( this->len == 1 ){
        free( this->last );
        this->first = this->last = this->cursor = NULL;
    } else{
        NodePtr tmp = this->last->prev;
        free( this->last );
        this->last = tmp;
        tmp->next = NULL;
    }
    --this->len;
}

Item DLL_Get( DLL* this )
{
    assert( this );
    assert( this->cursor );

    return this->cursor->datos;
}

void DLL_Cursor_front( DLL* this )
{
    //assert( this->first );

    this->cursor = this->first;
}

void DLL_Cursor_back( DLL* this )
{
    assert( this->first );

    this->cursor = this->last;
}

void DLL_Cursor_next( DLL* this )
{
    assert( this->first );

    if( this->cursor != NULL ){
        this->cursor = this->cursor->next;
    }
}

void DLL_Cursor_prev( DLL* this )
{
    assert( this->first );

    if( this->cursor != NULL ){
        this->cursor = this->cursor->prev;
    }
}

bool DLL_IsEmpty( DLL* this )
{
    return ( this->len == 0 );
}

size_t DLL_Len( DLL* this )
{
    return this->len;
}

void DLL_MakeEmpty( DLL* this )
{
    assert( this->first );

    while( this->len > 0 ){
        DLL_Remove_front( this );
    }
}

// recorre la this y ejecuta la función fn en la parte de datos de cada
// elemento de la misma
void DLL_Traverse( DLL* this, void (*fn)( int item ) )
{
	if( NULL == this ){ return; }

	Node* t = this->first;
   // ¡NO PODEMOS PERDER A FIRST!

   while( t != NULL ){

		fn( t->datos );

		t = t->next;
   }
}
