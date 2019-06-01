#ifndef _FILE_H_
#define _FILE_H_

#include "list.h"



FILE * file_open(char * filename);
void file_add(FILE *fp,void *data,int size);
void file_updata(FILE *fp,void *data,int size,int index);

void list_to_file(FILE *fp ,LIST *head,int size);
LIST *  file_to_list(FILE *fp,int size);


#endif