#ifndef MAIN_H
#define MAIN_H

/* defininig header file */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

/* Macros */

#define SUCCESS 1
#define FAILURE 0
#define DATA_NOT_FOUND -1
#define NOT_EMPTY_FILE -2
#define EMPTY_FILE -3

/* User defined data type */

typedef struct node
{
	char file_name[20];
	struct node *link;
}f_list;

/* for main node data type */

typedef struct subnode
{
	int wordcount;
	char filename[20];
	struct subnode *nextsublink;
}sub_node;

/* for sub node data type */

typedef struct mainnode
{
	int file_count;
	char word[20];
	sub_node *sublink;
	struct mainnode *nextmainlink;
}main_node;

/* prototype / function defination */

int read_and_validate(char *argv[], int argc, f_list **head);  

int insert_at_last(f_list **head, char str[] );

int display( f_list *head );  // displaying files name

void display_list( main_node **arr);  // displaying hash list 

int create_database(main_node **arr, f_list *head);

void assign_null(main_node **arr);

int search_database( main_node **arr,char *str );

int save_database( main_node **arr, char *str1 );

int data_into_file ( main_node **arr, char *str );

int update_database( main_node **arr, char *str2 );

#endif
