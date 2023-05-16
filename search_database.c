#include"main.h"

int search_database( main_node **arr, char *str )
{

	printf ("\nIndex   word     filecount  	 filename          wordcount           subfilename       wordcount\n");  
	printf("---------------------------------------------------------------------------------------------------------\n");
	int index = (tolower(str[0]) % 97);   // find out index value using first charcater of word

	if  (index >=0 && index <=25 )  // checking index is present or not
	{
		index = index;  
		
	}
	else
	{
		index = 26;  // else index as 26;
	}


	if ( arr[index] != NULL )
	{
		main_node *temp = arr[index];  // assign address into temp;

		while ( temp != NULL )
		{
			if ( strcmp ( temp->word, str)  == 0 ) // comapre word are same or not;
			{
				printf ( "[%d]	[%s]  	%d file(s)",index, temp->word, temp->file_count);
				sub_node *stemp = temp->sublink;
				while( stemp != NULL )
				{
					printf ("	    %s	    %d time(s)", stemp->filename, stemp->wordcount);
					stemp = stemp->nextsublink;
				}
			}

			temp = temp->nextmainlink;  // traverse untill find the word.
		}
		return SUCCESS;
	}
	else
	{
		return DATA_NOT_FOUND;  // if not matches return not found;
	}
}
