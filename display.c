#include"main.h"

void display_list(main_node **arr )
{
	printf ("\n[Index]   [word]   		filecount   		filename            wordcount           subfilename       	 wordcount\n");  
	printf("-------------------------------------------------------------------------------------------------------------------------\n");
	for ( int i=0; i<27; i++ )  // running loop for upto 27
	{
		if ( arr[i] != NULL )   // checking arr is not null;
		{
			main_node *temp = arr[i];  // using temp traverse upto null for every index
			while ( temp != NULL )
			{
				printf ( "[%d]	 [%s]	  		%d files(s)	",i, temp->word, temp->file_count);
				sub_node *stemp = temp->sublink;
				while( stemp != NULL )
				{
					printf ("	%s		%d time(s)", stemp->filename, stemp->wordcount);
					stemp = stemp->nextsublink;
				}
				printf("\n");
				temp = temp->nextmainlink;  // update temp;
			}
		}
	}
}

