/***********************************************************************/
/**      Author: Minas Spetsakis                                      **/
/**        Date: Jul. 2019                                            **/
/** Description: Assgn. III                                           **/
/***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "array.h"
#include "functions.h"

///
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/mman.h>
 #include <sys/types.h>
#include <fcntl.h>

///


// void open_array_inmain(char *filename, array_t *arrayp, int *sizep){

//     struct stat st;
//     int status = stat(filename, &st);
//     if(status !=0){
//       fatalerr(filename,0,"no such file in current directory");
//     }

//     // open file to fd
//     int fd = open(filename, O_RDWR, 00700);  
//     if(fd==-1){
//       fatalerr(filename,0,"open file fail");
//     }
//     *sizep = st.st_size / sizeof(array_t);

//     *arrayp = mmap(NULL,st.st_size,PROT_READ, MAP_SHARED, fd, 0);
    
// }


// void create_array_inmain(char *filename, int index, array_t *arrayp){
 
//       if( access( filename, F_OK ) != -1 ) {
//     // file exists
//     fatalerr(filename,0,"file already exits");
//     } 

//      // open file to fd
//       int size = index + 1;
//      int fd = open(filename, O_CREAT | O_RDWR, 00700);  
//      if(fd == -1){
//        fatalerr(filename,0,"create file fail");
//      }

//     ftruncate(fd,sizeof(array_t)*size);
  
//     *arrayp = mmap(NULL,size*sizeof(array_t),PROT_READ | PROT_WRITE,MAP_SHARED, fd, 0);
//     if (arrayp == MAP_FAILED) {
//     close(fd);
//     fatalerr(filename,0,"mmap failed");
//     exit(EXIT_FAILURE);
//     }

// // int i = 0;
// // for(i=0;i<size;i++){
// // 	arrayp[i] = malloc(sizeof(array_t));
// //       arrayp[i]->index = i;
// //       arrayp[i]->valid = 0;
// //       arrayp[i]->age = 0.0;
// //        printf("i is %d\n",i);

// //     }
    

// }

void set_array_inmain(array_t array, char *name, int index, float age){

  array[index].age = age;


}


void print_array_inmain(array_t array, int size)
{				/* Prints all entries with valid member true */
                                /* using the same format as in the main */
  int i;
  

  for(i=0;i<size;i++){
    array_t a = (array_t)&array[i];
  //  printf("index: %d, name: %s, age: %f\n",&array[i].index,&array[i].name,&array[i].age);
  }
}



/***********************************************************************
                               M A I N
************************************************************************/
int main(int argc, char **argv)
{
  char *filename = "namedb";
  //char *filename = "test";
  int size=-1;
  char *name=NULL;
  array_t array=NULL;
  int index=-1;
  float age=-1.0;
  int i;
  int argv_i_len;


//create_array_inmain(filename,20,&array);
//  open_array_inmain(filename,&array,&size);
//  set_array_inmain(array,"kevin",0, 16.0);
//   print_array_inmain(array, 20);

  i=1;
  while (i<argc) {
    argv_i_len = strlen(argv[i]);
    if (argv_i_len<3) argv_i_len=3;
    if (strncmp("--filename",argv[i],argv_i_len)==0) {
      if (i==argc)
	fatalerr(argv[0],0,"Insufficient arguments");
      filename = argv[++i];
      if (array!=NULL)
	close_array(&array, size);
    }
    else if (strncmp("--index",argv[i],argv_i_len)==0) {
      if (i==argc)
	fatalerr(argv[0],0,"Insufficient arguments");
      index = atoi(argv[++i]);
    }
    else if (strncmp("--name",argv[i],argv_i_len)==0) {
      if (i==argc)
	fatalerr(argv[0],0,"Insufficient arguments");
      if (strlen(name = argv[++i])>=MAXNAME)
	fatalerr(argv[0],0,"Name too long");
    }
    else if (strncmp("--age",argv[i],argv_i_len)==0) {
      if (i==argc)
	fatalerr(argv[0],0,"Insufficient arguments");
      age   = atof(argv[++i]);
    }
    else if (strncmp("--set",argv[i],argv_i_len)==0) {
      if (index<0 || age<0.0 || name==NULL)
	fatalerr(argv[0],0,"index, name or age undefined");
      if (array==NULL)
	open_array(filename,&array, &size);
      if (index>=size)
	fatalerr(argv[0],0,"index out of bounds");
      set_entry(array, name, index, age);
      name = NULL;
      index = -1;
      age = -1.0;
    }
    else if (strncmp("--get",argv[i],argv_i_len)==0) {
      if (index<0)
	fatalerr(argv[0],0,"index undefined");
      if (array==NULL)
	open_array(filename,&array, &size);
      if (index>=size)
	fatalerr(argv[0],0,"index out of bounds");
      get_entry(array, &name, index, &age);
      printf("index: %d, name: %s, age: %f\n", index, name, age);
    }
    else if (strncmp("--create",argv[i],argv_i_len)==0) {
      if (array!=NULL)
	close_array(&array, size);
      printf("index is %d\n",index);
      if (index<0)
	fatalerr(argv[0],0,"index undefined");
      size = index;
      create_array(filename, size, &array);
    }
    else if (strncmp("--print",argv[i],argv_i_len)==0) {
      if (array==NULL)
	open_array(filename,&array, &size);
      print_array(array, size-1);
    }
    else if (strncmp("--maxindex",argv[i],argv_i_len)==0) {
      if (array==NULL)
	open_array(filename,&array, &size);
      printf("Maximum index for array %s: %d\n",filename, size);
    }
    else if (strncmp("--delete",argv[i],argv_i_len)==0) {
      if (array==NULL)
	open_array(filename,&array, &size);
      if (index<0)
	fatalerr(argv[0],0,"index undefined");
      delete_entry(array,index);
    }
    else fatalerr(argv[i],0,"Invalid option");
    i++;
  }

}
