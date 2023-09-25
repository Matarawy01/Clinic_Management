#include <stdio.h>
#include "STD_TYPE.h"
#include "admin.h"
#include "user.h"
node *head=NULL;
int main()
{
	/*choose 1 for choose between admin and user
	 *choose 2 for choose the options of admin mode
	 *choose 3 for choose the options of user mode
	 *tries refer to numbers of try write the password
	 */
	u32 choose1=0,choose2=0,choose3=0;
	u32 tries=3;
	u32 password;
	/*start of the program*/
	label:printf("**********************************************************************************************************\n");
	printf("************************************** Welcome To The Clinic System **************************************\n");
	printf("**********************************************************************************************************\n");
	/*allow to choose between admin and user*/
	printf("\nPlease choose between Admin mode and User mode\n\n");
	printf("For Admin mode enter '1'\nFor User mode enter '2'\n");
	fflush(stdin);fflush(stdout);
	scanf("%d",&choose1);
	/*if he choose 1 that he want to go to admin mode*/
	if(choose1 == 1)
	{
		/*looping for the 3 tries of entering the password*/
		for(tries =3;tries>0;tries--)
		{
			/*ask user to enter the password*/
			printf("\nPlease Enter the Password: ");
			fflush(stdin);fflush(stdout);
			scanf("%d",&password);
			printf("\n");
			/*as default the password of admin mode 1234 if he enter the correct password enter this condition*/
			if(password == 1234)
			{
				printf("\n*****************************************************************************\n");
				printf("************************** Welcome To Admin Mode ****************************\n");
				printf("*****************************************************************************\n\n");
				while(1)
				{
					/*make user to choose the options from admin mode*/
					printf("\n\nIf you want to add new patient '1'\nIf you want to edit patient data '2'\nIf Reserve a slot '3'\nIf you want to cancel reserved slot '4'\nIf you want to exit from Admin mode '5'\n");
					fflush(stdin);fflush(stdout);
					scanf("%d",&choose2);
					switch(choose2)
					{
					case 1 :
					{
						/*calling this function to add new patient to your list*/
						add_new_patient(&head);
						printf("*****************************************************************************\n");
						break;
					}
					case 2:
					{
						/*calling this function to edit patient data*/
						edit_patient(head);
						printf("*****************************************************************************\n");
						break;
					}
					case 3:
					{
						/*calling this function to reserve slot to patient*/
						reserve_slot(head);
						printf("*****************************************************************************\n");
						break;
					}
					case 4:
					{
						/*calling this function to cancel slot to patient*/
						cancel_resevation(head);
						printf("*****************************************************************************\n");
						break;
					}
					}
					/*for exist from admin mode and return to start of program*/
					if(choose2 ==5)
					{
						goto label;
					}
				}
				break;
			}
		}
		if(tries == 0)
		{
			goto label;
		}
	}
	/*if he choose 2 that he want to go to admin mode*/
	else if(choose1 == 2)
	{
		while(1)
		{
			printf("\n*****************************************************************************\n");
			printf("************************** Welcome To User Mode *****************************\n");
			printf("*****************************************************************************\n\n");

			/*make user to choose the options from user mode*/
			printf("If you want to print patient data '1'\nIf you want to print the reserved data '2'\nIf you want to exist '3'\n");
			fflush(stdin);fflush(stdout);
			scanf("%d",&choose3);
			printf("\n*****************************************************************************\n");
			if(choose3 == 1)
			{
				/*calling this function to print the data of specific patient*/
				print_patient_record(head);
			}
			else if(choose3 ==2)
			{
				/*calling this function to view the information if slots as reserved of available*/
				view_reserved();
			}
			else if(choose3 == 3)
			{
				break;
			}
		}
		goto label;
	}

}
