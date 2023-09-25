#include "admin.h"
#include <string.h>

/*this is an array contain the available and reserved slot*/
u8 arr[5]={0};

/*this function return that if there is user by this ID or not*/
/*the argument of this function is pointer that loop to all nodes and the ID that you want to search about*/
node *search_ID(node *head,u8 ID)
{
	/*this loop mean that the pointer search from the first node until it reach to the null of the last node point to it*/
	while(head != NULL){
		/*if found this ID return the node that this ID in it*/
		if(head->ID == ID)
		{
			return head;
		}
		/*make the pointer 'head' move to next node*/
		head = head->next;
	}
	/*if not found this ID return null to the node */
	return NULL;
}
/********************************************************************************************************************************************/

/*this function to add anew node to our list*/
/*the argument is pointer to pointer to change the value or address of list that the head of the list point to it*/
void add_new_patient(node **head_ptr)
{
	/*make a pointer that carry the address of the new node*/
	node *temp;
	/*creation of new node and save the address of it in the pointer 'temp'*/
	temp = (node*) malloc(sizeof(node));
	/*** asking user to enter the ID to check if there any user having this ID or not ***/
	printf("\nPlease Enter Your ID: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&(temp->ID));
	/***If there are not any user having this ID make the user able to enter his data***/
	if(search_ID(*head_ptr, (temp->ID)) == NULL)
	{
/********** scanning from the user the data to save it in the node **********/
		/**making the new node point to the next node as the head of list point to it*/
		temp->next = *head_ptr;
		printf("Please Enter Your Name: ");
		fflush(stdin);fflush(stdout);
		scanf("%s",&(temp->name));
		printf("Please Enter Your Age: ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&(temp->age));
		printf("Please Enter Your Gender if you are male send 'M' or female 'F': ");
		fflush(stdin);fflush(stdout);
		scanf("%c",&(temp->gender));
		/*make the head of list point to the new node to complete the addetional operation*/
		*head_ptr = temp;
	}
	/*If the ID is already used*/
	else
	{
		printf("This ID is exist\n");
	}
}
/********************************************************************************************************************************************/

/*this function for edit the data of the user*/
void edit_patient(node *head)
{
	/*search that there are any user having this ID or not*/
	u32 ID;
	printf("Please enter your ID: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&ID);
	/*this to make the pointer point to this node*/
	head = search_ID(head,ID);
	/*this if the ID is not find*/
	if(head == NULL)
	{
		printf("Incorrect ID\n");
	}
	/*this if the ID is exist in the list*/
	else
	{
/*** Access for the admin to edit his data and save the new data in list ***/
		printf("Please Enter Your Name: ");
		fflush(stdin);fflush(stdout);
		scanf("%s",&(head->name));
		printf("Please Enter Your Age: ");
		fflush(stdin);fflush(stdout);
		scanf("%d",&(head->age));
		printf("Please Enter Your Gender if you are male send 'M' or female 'F': ");
     	fflush(stdin);fflush(stdout);
		scanf("%c",&(head->gender));
	}
}
/********************************************************************************************************************************************/

/*this function thats for all available slots to this clinic*/
void available_slot()
{
/*** The default that the array index is equal to zero ***/
	if(arr[0] == NULL)
		printf("From 2pm to 2:30pm enter '1'\n");
	if(arr[1] == NULL)
		printf("From 2:30pm to 3pm enter '2'\n");
	if(arr[2] == NULL)
		printf("From 3pm to 3:30pm enter '3'\n");
	if(arr[3] == NULL)
		printf("From 4pm to 4:30pm enter '4'\n");
	if(arr[4] == NULL)
		printf("From 4:30pm to 5pm enter '5'\n");
}
/********************************************************************************************************************************************/

/*this function to allow admin to reserve a slots*/
void reserve_slot(node *head)
{
	u32 time,ID;
	/*check if this ID is in list or not*/
	printf("Enter your ID: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&ID);
	head = search_ID(head,ID);
	/*this if the ID is exist*/
	if(head != NULL)
	{
		/*allow to the admin all slot available*/
		printf("Enter the slot that you want to reserve\n\n");
		available_slot();
		fflush(stdin);fflush(stdout);
		scanf("%d",&time);
		/*when the admin choose the slot it change the array to saved by his ID*/
		if(time == 1)
		{
			arr[0]=ID;
		}
		else if(time == 2)
		{
			arr[1]=ID;
		}
		else if(time == 3)
		{
			arr[2]=ID;
		}
		else if(time == 4)
		{
			arr[3]=ID;
		}
		else if(time == 5)
		{
			arr[4]=ID;
		}
		printf("Thank you for reservation\n");
	}
	/*IF the ID is not exist*/
	else
	{
		printf("This ID is't Exist\n\n");
	}
}
/********************************************************************************************************************************************/

/*this function to cancel the reservation */
void cancel_resevation(node *head)
{
	u32 ID,i,flag=0;
	/*check if this ID is in list or not*/
	printf("Enter your ID: ");
	fflush(stdout);fflush(stdin);
	scanf("%d",&ID);
	/*this if the ID is exist*/
	if(search_ID(head,ID) != NULL)
	{
		/*looping to the array */
		for(i=0;i<5;i++)
		{
			/*If found that this slot is reserved from ID of user*/
			if(arr[i] == ID)
			{
				/*return it into zero as default*/
				flag=1;
				arr[i] = 0;
				printf("The cancellation is success\n");
			}
		}
		/*if found the ID but this user hasn't reserve any slots yet*/
		if(flag == 0)
		{
			printf("This ID Has not reserve any slot yet\n\n");
		}
	}
	/*IF the ID is not exist*/
	else
	{
		printf("Wrong ID\n\n");
	}
}
