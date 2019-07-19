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

/**********************************************************************/
/********************       O P E N  A R R A Y     ********************/
/**********************************************************************/
void open_array(char *filename, array_t *arrayp, int *sizep)
{				/* Opens array from file filename and */
                                /* returns its pointer and size */
  /* size is the size of the file divided by the size of the array struct */
  /* pointer array is obtained with mmap */
}

/**********************************************************************/
/********************     C L O S E  A R R A Y     ********************/
/**********************************************************************/
void close_array(array_t *arrayp, int size)
{				/* Unmaps array and sets it to NULL */
  
}

/**********************************************************************/
/********************    C R E A T E  A R R A Y    ********************/
/**********************************************************************/
void create_array(char *filename, int index, array_t *arrayp)
{				/* Creates a file with an array with index */
                                /* elements, all with the valid member false. */
                                /* It is fatal error if file exists */
  /* size is the size of the file divided by the size of the array struct */
  /* pointer array is obtained with mmap */
  
}


/**********************************************************************/
/********************       S E T  E N T R Y       ********************/
/**********************************************************************/
void set_entry(array_t array, char *name, int index, float age)
{				/* Sets the elements of the index'ed */
                                /* entry to name and age and the valid */
                                /* member to true */
 
}

/**********************************************************************/
/********************       G E T  E N T R Y       ********************/
/**********************************************************************/
void get_entry(array_t array, char **name, int index, float *age)
{				/* Returns the index'ed entry's name and age */
                                /* if valid, fatal error o/w */
  
}

/**********************************************************************/
/********************   D E L E T E   E N T R Y    ********************/
/**********************************************************************/
void delete_entry(array_t array, int index)
{				/* Sets the valid element of the index'ed */
                                /* entry to false */
  
}

/**********************************************************************/
/********************     P R I N T   A R R A Y    ********************/
/**********************************************************************/
void print_array(array_t array, int size)
{				/* Prints all entries with valid member true */
                                /* using the same format as in the main */
 
}
