
/*
NAME         : KARTHIK C
DATE         : 15/05/2023
DESCRIPTION  : Inverted Search
SAMPLE INPUT : file name.txt file name.txt
SAMPLE OUTPUT: sorting .
*/

#include "main.h"

/* main function */

int main(int argc, char *argv[] )
{
	int a ;
	char ch = 'y';
	int flag = 0;

	main_node *hash_list[27] ;   // declaring hash_list with 27 size;
	assign_null(hash_list);     // assigning null into hash list using function

	f_list *head = NULL;

	if( read_and_validate(argv, argc, &head) == SUCCESS )   // read and validate function prototype 
	{
		display(head);   // displaying files , which is validated.

		printf("\nSuccessfully completed validation part \n\n");
		while ( ch == 'Y' || ch == 'y' )   // loop untill user exit.
		{

			printf("1. Create database\n2. Display database\n3. Search\n4. Save database\n5. Update database\n");
			printf("Enter the Choice : ");
			scanf("%d",&a);

			switch(a)
			{
				case 1 :if ( flag == 0 )
						{	
							create_database(hash_list, head);   // create database function call
							flag = 1;
						}
						else
						{
							printf("\nWarning : Can't able to update because, hash table is full\n");
							printf(" You can proceed with another option. \n\n");
						}
						break;

				case 2 : display_list( hash_list);   // displaying database.
		         		 break;

				case 3 : printf("\nEnter the string which you want to search : ");
						 char str[50];
						 scanf("%s", str);

						 if ( search_database( hash_list, str ) == DATA_NOT_FOUND )   //searching the name inside database
						 {
							 printf ("Entered %s is not found \n\n", str);
						 }
						 else
						 {
							 printf ("\nData found\n\n");
						 }
						 break;

				case 4 : printf ("\nEnter the file name : ");

						 char str1[50];
						 scanf("%s",str1);

						 int ret = save_database( hash_list, str1 ) ;   // saving database list into another file
						
						 if ( ret == NOT_EMPTY_FILE)  // if file is non empty
						 {
							 printf ("\nFile is Non Empty , Please pass the Empty File\n\n ");
						 }
						 else if ( ret == FAILURE)   // if file is not a .txt extension format
						 {
							 printf ("\nError : Please pass the filename with Extension\n");
							 printf("\nUsage : Filename.txt\n\n");
						 }
						 else
						 {
							 printf("\nSuccessfully Data is saved into %s File \n\n", str1);
						 }
						 break;

				case 5 : if ( flag == 0 )
						 {
							 flag = 1;
							 printf(" Enter the file name that u want to update : ");
						 	 char str2[100];
							 scanf("%s", str2);

						 	 int ret1 = update_database( hash_list, str2);    // updating file content into database

							 if ( ret1 == FAILURE )   // if file is not exist.
							 {
								 printf ("Error : Please pass the content file and already exist file \n");
							 	 printf ("Usage : filename.txt\n");
						 	 }
							 else if ( ret1 == EMPTY_FILE )
							 {
								 printf("Error : %s File is empty\n", str2);
								 printf("Usage : please pass the content file\n");
							 }
							 else
							 {
								 printf(" \nSuccessfully data is updated to hash list\n\n");
							 }
						 }
						 else
						 {
							 printf("\nWarning : Can't able to update because, hash table is full\n");
							 printf(" You can proceed with another option. \n\n");
						 }
						 break;

				default: printf ("\nPlease pass the Correct choice\n");
						 break; 
			}

			printf("\nDo you want to continue y/n : ");
			scanf(" %c", &ch);
			printf("\n");
		}
	}
	else
	{
		printf("Read and validation part is not successfull\n ");    // if read and validate is failure, excute this statement'
	}

}

