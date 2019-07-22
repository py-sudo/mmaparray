/***********************************************************************/
/**      Author: Minas Spetsakis                                      **/
/**        Date: Jul. 2019                                            **/
/** Description: Assgn. III                                           **/
/***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

#include "array.h"
#include "functions.h"

//#include <libexplain/mmap.h>

/**********************************************************************/
/********************       O P E N  A R R A Y     ********************/
/**********************************************************************/

void open_array(char *filename, array_t *arrayp, int *sizep)
{ /* Opens array from file filename and */
  /* returns its pointer and size */
  /* size is the size of the file divided by the size of the array struct */
  /* pointer array is obtained with mmap */

  struct stat st;
  int status = stat(filename, &st);
  if (status != 0)
  {
    fatalerr(filename, 0, "no such file in current directory");
  }

  // open file to fd
  int fd = open(filename, O_RDWR, 00700);
  if (fd == -1)
  {
    fatalerr(filename, 0, "open file fail");
  }

  *arrayp = mmap(NULL, st.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  *sizep = st.st_size / sizeof(array_t);

  printf("size of array is %d\n", *sizep);
}

/**********************************************************************/
/********************     C L O S E  A R R A Y     ********************/
/**********************************************************************/
void close_array(array_t *arrayp, int size)
{ /* Unmaps array and sets it to NULL */
  munmap(arrayp, size);
}

/**********************************************************************/
/********************    C R E A T E  A R R A Y    ********************/
/**********************************************************************/
void create_array(char *filename, int index, array_t *arrayp)
{ /* Creates a file with an array with index */
  /* elements, all with the valid member false. */
  /* It is fatal error if file exists */
  /* size is the size of the file divided by the size of the array struct */
  /* pointer array is obtained with mmap */
  // file exists
  if (access(filename, F_OK) != -1)
  {
    fatalerr(filename, 0, "file already exits");
  }

  // open file to fd
  int size = index + 1;
  int fd = open(filename, O_CREAT | O_RDWR, 00700);
  if (fd == -1)
  {
    fatalerr(filename, 0, "create file fail");
  }

  ftruncate(fd, sizeof(array_t) * size);

  *arrayp = mmap(NULL, size * sizeof(array_t), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (arrayp == MAP_FAILED)
  {
    close(fd);
    fatalerr(filename, 0, "mmap failed");
    exit(EXIT_FAILURE);
  }
}

/**********************************************************************/
/********************       S E T  E N T R Y       ********************/
/**********************************************************************/
void set_entry(array_t array, char *name, int index, float age)
{ /* Sets the elements of the index'ed */
  /* entry to name and age and the valid */
  /* member to true */
  array[index].age = age;
  strcpy(array[index].name, name);
  array[index].valid = 1;
  printf("inside set entry for index %d\n", index);
  printf("inside set entry for age %f\n", array[index].age);
  printf("inside set entry for name %s\n", array[index].name);
}

/**********************************************************************/
/********************       G E T  E N T R Y       ********************/
/**********************************************************************/
void get_entry(array_t array, char **name, int index, float *age)
{ /* Returns the index'ed entry's name and age */
  /* if valid, fatal error o/w */

  if(array[index].valid==0){
    fatalerr(*name, 0, "this index is not valid");
    exit(EXIT_FAILURE);
  }


  printf("inside get entry in main\n");
  printf("valid is %d\n",array[index].valid);
  printf("age is %f\n",array[index].age);

      *name = array[index].name;
      *age = array[index].age;
}

/**********************************************************************/
/********************   D E L E T E   E N T R Y    ********************/
/**********************************************************************/
void delete_entry(array_t array, int index)
{ /* Sets the valid element of the index'ed */
  /* entry to false */
  array[index].valid = 0;
}

/**********************************************************************/
/********************     P R I N T   A R R A Y    ********************/
/**********************************************************************/
void print_array(array_t array, int size)
{ /* Prints all entries with valid member true */
  /* using the same format as in the main */
  int i;

  for (i = 0; i < size+1; i++)
  {
    if (array[i].valid == 1)
      printf("index: %d, name: %s, age: %f\n", i, array[i].name, array[i].age);
  }
}
