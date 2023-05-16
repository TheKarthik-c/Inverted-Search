
#include "main.h"


// read and validate part 

int read_and_validate(char *argv[], int argc, f_list **head )
{
	printf("\n");
	FILE *fptr = NULL;
 	int flag = 0;
	if ( argc < 2 )  // command line argument should be greater than 1;
	{
		printf("ERROR : please pass ./a.out file1.txtx.., atleast one file\n");
		return FAILURE;
	}

	for ( int i=1; i<argc; i++)  
	{
		fptr = fopen( argv[i] , "r");  // open file in read mode
		
		if ( fptr == NULL )
		{
			printf("ERROR : %s file is not present \n", argv[i]);
			goto table;
		}

		else if ( strcmp ( strstr(argv[i], ".") , ".txt") != 0 )  // check .txt or not.
		{
			printf("ERROR : Please pass file %s in .txt \n", argv[i]);
			flag = 1;
		}

		fseek ( fptr,0, SEEK_END );

		if ( ftell(fptr) == 0 )   // check inside file content is there or not.
		{
			printf("ERROR : %s is Empty file \n", argv[i]);
			flag = 1;
		}

		if( flag == 0 )
		{

			if ( insert_at_last( head, argv[i] ) == SUCCESS )  // function call;
			{
				printf("%s is successfully inserted\n",argv[i]);
				fclose(fptr);
			}
			else
			{
				printf(" Warning : %s is duplicate file \n", argv[i]);  // if already file is present ;
			}
		}

table : {

		}
	}
	
	return SUCCESS;
}

int insert_at_last(f_list **head, char str[] )  // function defination 
{
	f_list *new = malloc(sizeof(f_list));

	if ( new == NULL )
	{
		return FAILURE;
	}

	strcpy(new->file_name , str);

	new->link = NULL;

	if ( *head == NULL )
	{
		*head = new;
		return SUCCESS;
	}

	f_list *temp = *head;

	while ( temp->link != NULL )
	{
		if( strcmp(temp->file_name, new->file_name) == 0 )  // is same file is present no need to add in linked list
		{
			
			return FAILURE;
		}

		temp = temp->link;
	}
		
	if( strcmp(temp->file_name, new->file_name) == 0 )
	{

		return FAILURE;
	}
		
	temp->link = new; // if no add file name to linked list;
	return SUCCESS;
}

int display( f_list *head )  // display the liked list
{
	printf("\n");
	if( head == NULL )
	{
		return FAILURE;
	}

	f_list *temp = head;
	printf("Head -> ");

	while ( temp )
	{
		printf("%s",temp->file_name);  // which is successfully added inside the linked list.
		temp = temp->link;
		printf(" -> ");
	}
	printf("NUll \n");
}



