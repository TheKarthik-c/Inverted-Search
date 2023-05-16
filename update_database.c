#include"main.h"

int update_database( main_node **arr, char *str2 )
{
	char ch[100];

	if ( strcmp ( strstr(str2, ".") , ".txt" ) != 0 )  // check file is .txt or not
	{
		return FAILURE;
	}

	FILE *fptr = fopen(str2,"r");  // open the file

	if ( fptr == NULL )
	{
		return FAILURE;
	}

	fseek(fptr,0,SEEK_END);

	if ( ftell(fptr) == 0 )  // check file is empty or not
	{
		return EMPTY_FILE;
	}
	
	fseek(fptr,0,SEEK_SET);
	
	char buffer[1000], buffer1[1000];

	while ( fscanf(fptr, "%s", buffer ) != EOF )  // take one line string into buffer
	{
		if ( buffer[0] == '#') // check first character is # or not;
		{
			int j =0;

			for(int i=1; buffer[i]!='#'; i++)
			{
				buffer1[j] = buffer[i]; // accept first character remaining character update into buffer1.
				j++;
			}

			int index = atoi(strtok(buffer1, ";")); // take first sring upto ;, and convert to number,

			if ( arr[index] == NULL )
			{

				main_node *main_new = malloc(sizeof(main_node)); // create memory
				sub_node *sub_new1 = malloc(sizeof(sub_node));

				arr[index] = main_new;

				strcpy( main_new->word	, strtok(NULL, ";") );  // assign word to main node word;
				main_new->file_count = atoi(strtok(NULL, ";")); // assign file count ;
				main_new->nextmainlink = NULL;
				main_new->sublink = sub_new1;

				strcpy( sub_new1->filename, strtok(NULL, ";"));
				sub_new1->wordcount = atoi( strtok(NULL, ";"));
				sub_new1->nextsublink = NULL;
				sub_node *subprev = sub_new1;

				for( int i = 1; i < main_new->file_count; i++ )  // if two or more sublink, is present
				{

					sub_node *sub_new1 = malloc(sizeof(sub_node));  // create sub_new data type

					subprev->nextsublink = sub_new1;   // assign prev to new memory address.

					strcpy( sub_new1->filename, strtok(NULL, ";"));

					sub_new1->wordcount = atoi( strtok(NULL, ";"));

					sub_new1->nextsublink = NULL;

					subprev = sub_new1;
				}
			}
			else
			{
				main_node *temp1 = arr[index] , *mainprev;  // alraedy content is present, take temp1 variable.

				main_node *main_new = malloc(sizeof(main_node));
				sub_node *sub_new1 = malloc(sizeof(sub_node));

				strcpy( main_new->word	, strtok(NULL, ";") );
				main_new->file_count = atoi(strtok(NULL, ";"));
				main_new->nextmainlink = NULL;
				main_new->sublink = sub_new1;

				strcpy( sub_new1->filename, strtok(NULL, ";"));
				sub_new1->wordcount = atoi( strtok(NULL, ";"));
				sub_new1->nextsublink = NULL;

				sub_node *subprev = sub_new1;

				for( int i = 1; i < main_new->file_count; i++ )
				{

					sub_node *sub_new1 = malloc(sizeof(sub_node));

					subprev->nextsublink = sub_new1;

					strcpy( sub_new1->filename, strtok(NULL, ";"));

					sub_new1->wordcount = atoi( strtok(NULL, ";"));

					sub_new1->nextsublink = NULL;

					subprev = sub_new1;
				}

				while ( temp1 )  // traverse temp1 reaches null;
				{
					mainprev = temp1;
					temp1 = temp1->nextmainlink;
				}
				mainprev->nextmainlink = main_new;  // assign address to prev->mainlink;
			}
		}
		else
		{
			printf ("\nStarting charcter is not started with # so cant update into hash_list\n\n"); // if file content is not start with #.
		}
	}
	return SUCCESS;
}
