#include"main.h"

/* create_database function defination */

int create_database(main_node **arr, f_list *head)
{
	f_list *temp = head;

	while ( temp )
	{
		FILE *fptr = fopen(temp->file_name , "r"); // opening the first file, which is passed in command line. 

		char buffer[25];

		while ( fscanf(fptr, "%s", buffer ) != EOF )  // storing word into buffer, one by one
		{
			int flag = 0;
			int index = (tolower(buffer[0]) % 97);   // we converting first letter in word into ascii value, based on this we are allocating index in hash_list;

			main_node *new = malloc( sizeof(main_node)); // creating memory allocation for main_node
			sub_node *new1 = malloc ( sizeof(sub_node)); // creating memory allocation for sub node;

			if ( new == NULL || new1 == NULL )   // if memory is not allocated ,  return failure
			{
				return FAILURE;
			}

			strcpy(new->word,buffer);  // assign word into main_node word space
			new->file_count = 1;       // assign file count as 1 at initial stage
			new->nextmainlink = NULL;  // assign null into main node -> next main_node link

			new1->wordcount = 1;       // assign word count as 1 in sub node, at initial stage
			strcpy(new1->filename, temp->file_name);  // assign file name into sub_node file name space;
			new1->nextsublink = NULL;

			new->sublink = new1;

			if ( index >= 0 && index <= 25 )  // if index is 0 to 25, entering
			{
				if ( arr[index] == NULL )   // if hash_list [ index ] is not conataing any data means;
				{
					arr[index] = new;    // assign address into the hash_list {index].
				}		
				else   // if hash_list [ index] is not a null; means
				{
					main_node *temp1 = arr[index], *mainprev;  // create temp and previous variable for main_node.
					sub_node *subtemp, *subprev;   // create temp and previous for sub_node

					while ( temp1 )   // traverse untill temp reaches null;
					{
						if ( strcmp ( temp1->word, buffer ) == 0 )  //check if word is present or not
						{
							subtemp = temp1->sublink;  // if it is present, assign sublink address into temp varibale;

							while ( subtemp )  // traverse subtemp untill reaches null
							{
								if ( strcmp( subtemp->filename, temp->file_name ) == 0 )  // check filename is same or not
								{
									flag = 1;
									subtemp->wordcount ++;   // if same increment wordcount;
								}
								subprev = subtemp;  
								subtemp = subtemp->nextsublink;
							}

							if ( flag == 0 )  // if file name is not same, word is same means,
							{
								flag = 1;
								subprev->nextsublink = new1;  // create subnode, and assign link prev subnode.
								temp1->file_count ++;  // increment the filecount in mainnode.
							}
						}

						mainprev = temp1;  
						temp1 = temp1->nextmainlink;
					}

					if ( flag == 0 )
					{
						mainprev->nextmainlink = new;   // if word is not same, create main and sub node , and assign addresss into prev main node link
					}
				}
			}
			else
			{
				index = 26;  // if not a alphbet means.
				if ( arr[index] == NULL )
				{
					arr[index] = new;  // create index as 26;
				}		
				else
				{
					main_node *temp1 = arr[index], *mainprev;  // and procceed the same procedure for this also
					sub_node *subtemp, *subprev;

					while ( temp1 )
					{
						if ( strcmp ( temp1->word, buffer ) == 0 )
						{
							subtemp = temp1->sublink;

							while ( subtemp )
							{
								if ( strcmp( subtemp->filename, temp->file_name ) == 0 )
								{
									flag = 1;
									subtemp->wordcount ++;
								}
								subprev = subtemp;
								subtemp = subtemp->nextsublink;
							}

							if ( flag == 0 )
							{
								flag = 1;
								subprev->nextsublink = new1;
								temp1->file_count ++;
							}
						}
						mainprev = temp1;
						temp1 = temp1->nextmainlink;
					}

					if ( flag == 0 )
					{
						mainprev->nextmainlink = new;
					}
				}
			}

		}

		temp = temp->link;
	}
}
