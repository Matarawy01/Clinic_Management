#include "user.h"
#include "admin.h"
#include <string.h>
extern u8 arr[5];

/*This Function Print the data of patient */
/*The parameter of this function is pointer contain the address of node which the head of list point to it to move to all node */
void print_patient_record(node *head)
{
	u32 ID;
	/*check if there are any node in the list or not*/
	if(head == '\0')
	{
		printf("The linked list is empty\n");
	}
	/*if there a nodes in list*/
	else
	{
		/*search by user ID if there are user to print its data or not */
		printf("Please Enter your ID: ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&ID);
		/*this condition return that there are user by this ID in the list*/
		if(search_ID(head, ID) != NULL)
		{
			/*make the pointer 'head' point to this node*/
			head = search_ID(head, ID);
			/*print the user data*/
			printf("The name of patient: %s\n",head->name);
			printf("The age of patient: %d\n",head->age);
			printf("The gender of patient: %c\n",head->gender);
			printf("The ID of patient: %d\n\n",head->ID);
		}
		/*this condition return that there are no user by this ID in list*/
		else
		{
			printf("This ID is not exist\n\n");
		}
	}
}
/********************************************************************************************************************************************/

/*This function print the available slots and the reserved slots*/
void view_reserved()
{
	printf("The available slots : \n");
	/*this function return the available slots*/
	available_slot();
	printf("\n");
	/*To return the reserved slots*/
	printf("The reserved slots : \n");
/*If the array having a data in its list these mean that there are user reserve this slots*/
	if(arr[0] != NULL)
		printf("The Slot From 2pm to 2:30pm is Reserved From ID : %d\n",arr[0]);
	if(arr[1] != NULL)
		printf("The Slot From 2:30pm to 3pm is Reserved From ID : %d\n",arr[1]);
	if(arr[2] != NULL)
		printf("The Slot From 3pm to 3:30pm is Reserved From ID : %d\n",arr[2]);
	if(arr[3] != NULL)
		printf("The Slot From 4pm to 4:30pm is Reserved From ID : %d\n",arr[3]);
	if(arr[4] != NULL)
		printf("The Slot From 4:30pm to 5pm is Reserved From ID : %d\n",arr[4]);
}
