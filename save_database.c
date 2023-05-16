#include"main.h"

int save_database( main_node **arr, char *str1 )
{

	if ( !(strstr(str1,"." ) ))  // check . is present or not
	{

		return FAILURE;
	}


	if ( strcmp ( strstr( str1, "." ) , ".txt" ) != 0 )  // check extension is .txt or not
	{

		return FAILURE;
	}

	FILE *fptr = fopen(str1 , "r");  // open the file in read mode
	

	if ( fptr == NULL )  // if file is not present, create that file.
	{

		data_into_file ( arr, str1 );  // call the function

		return SUCCESS;
		
	}

	fseek ( fptr, 0, SEEK_END );

	if ( ftell(fptr) == 0 )  // if file is present but empty
	{
		fclose(fptr);
		
		data_into_file ( arr, str1 ); // call the function

		return SUCCESS;
	}
	else
	{

		fclose(fptr);

		return NOT_EMPTY_FILE;  // if file is present and containing word, return ;
	}
}

int data_into_file ( main_node **arr, char *str )  // function defination
{

	FILE *fptr = fopen ( str , "w" );  // open function in write mode

	for ( int i=0; i<27; i++ )
	{
		if ( arr[i] != NULL )   // check arr[index] is null or not;
		{
			main_node *temp = arr[i];  // assign address  into temp;

			while ( temp )  // traverse temp reaches null
			{

				fprintf ( fptr, "#%d;%s;%d;", i,temp->word, temp->file_count); // assign first # data into file sepearted by semicoloumn.

				sub_node *subtemp = temp->sublink;  // assign sub node address into temp.

				while ( subtemp )  
				{
					fprintf ( fptr , "%s;%d;",subtemp->filename, subtemp->wordcount);  // same line assig data 

					subtemp = subtemp->nextsublink;  // update temp;
				}
				temp = temp->nextmainlink;

				fprintf(fptr,"#\n");  // atlast add #;
			}
		}
	
	}
	fclose(fptr);
}






