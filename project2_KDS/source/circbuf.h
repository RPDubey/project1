
/*******************************************************************************
@file:circbuf.h
@brief:An abstraction for circular buffer operations implemented in circbuf.c

This file provides definitions for functions and external variables of file
circbuf.c
@author:Ravi Dubey
@date:10/21/2017
*******************************************************************************/

#include <stdint.h>
#include <stdlib.h>
#ifndef FILE_CIRCBUF
#define FILE_CIRCBUF

#define unsigned_byte uint8_t
#define CB_SIZE 20


typedef struct{
  unsigned_byte* buf_ptr;  //points to begining of buffer in memory
  unsigned_byte* buf_top_ptr; //points to the end of buffer in memory
  unsigned_byte* head;     // where to add item
  unsigned_byte* tail;     //where to pop item
  size_t size;    //buffer size
  size_t count;   //current number of items on the buffer
}CB_t;

typedef enum{
  Success ,
  Buffer_Full,
  Buffer_Empty,
  Null_Error,
  Argument_Error
}CB_enum;


/*******************************************************************************
@brief:Implements adding items to circular buffer
This function takes data to be added to the circular buffer and the poiner to
the circulr buffer and adds the data to this CB.
@param:Pointer to CB, pointer to data to be added to this CB
@return:CB_enum enumaration that specifies success failure etc.
*******************************************************************************/
CB_enum CB_buffer_add_item( CB_t* , unsigned_byte );


/*******************************************************************************
@brief:Implements removing items from circular buffer
This function gives pointer to the circular buffer from which the data has to be
removed and the variable in which the removed data has to be stored.
@param:Pointer to CB, pointer to the variable where popped data has to be saved
@return:CB_enum enumaration that specifies success failure etc.
*******************************************************************************/
CB_enum CB_buffer_remove_item(CB_t* , unsigned_byte*);


/*******************************************************************************
@brief:Implements checking whether circular buffer is full
This function takes poiner tothe circulr buffer and checks for full state.
@param:Pointer to CB
@return:CB_enum enumaration that specifies success failure etc.
*******************************************************************************/
CB_enum CB_is_full(CB_t*);



/*******************************************************************************
@brief:Implements checking whether circular buffer is Empty
This function takes poiner tothe circulr buffer and checks for Empty state.
@param:Pointer to CB
@return:CB_enum enumaration that specifies success failure etc.
*******************************************************************************/
CB_enum CB_is_empty(CB_t*);


/*******************************************************************************
@brief:Implements seeking data in circular buffer at particular location
This function takes pointer to a circular buffer, and position from head to peek
into and  pointer where this data will be stored.
@param:Pointer to CB,position from head to seek into, pointer to adress where
the data has to be stored.
@return:CB_enum enumaration that specifies success failure etc.
*******************************************************************************/
CB_enum CB_peek(CB_t* ,size_t, unsigned_byte* );



/*******************************************************************************
@brief:Implements initiatin a circular buffer
This function poiner to the circulr buffer and size to be reserved for the CB
in Bytes.
@param:Pointer to CB, size of buffer in bytes.
@return:CB_enum enumaration that specifies success failure etc.
*******************************************************************************/
CB_enum CB_init(CB_t* CB_ptr , size_t CB_size);



/*******************************************************************************
@brief:Implements destroying the circular buffer
This function takes pointer to the circular buffer to be destroyed
@param:Pointer to CB
@return:CB_enum enumaration that specifies success failure etc.
*******************************************************************************/
CB_enum CB_destroy(CB_t* CB_ptr);


#endif
