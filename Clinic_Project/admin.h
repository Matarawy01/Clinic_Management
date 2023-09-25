#ifndef __ADMIN_H__
#define __ADMIN_H__
#include "STD_TYPE.h"
#include "stdio.h"
#include "stdlib.h"

/*Data of every patient*/
typedef struct patient{
	u8 ID;
	u8 name[50];
	u8 age;
	u8 gender;
	struct patient *next;
}node;

/*this function return that if there is user by this ID or not*/
/*the argument of this function is pointer that loop to all nodes and the ID that you want to search about*/
node *search_ID(node *head,u8 ID);

/*this function to add anew node to our list*/
/*the argument is pointer to pointer to change the value or address of list that the head of the list point to it*/
void add_new_patient(node **head_ptr);

/*this function for edit the data of the user*/
void edit_patient(node *head);

/*this function thats for all available slots to this clinic*/
void available_slot();

/*this function to allow admin to reserve a slots*/
void reserve_slot(node *head);

/*this function to cancel the reservation */
void cancel_resevation();

#endif __ADMIN_H__
