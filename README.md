# What is mmaparray
```mmaparray``` is an c application that use mmap to create, inspect and modify arrays that exist on the disk as files.


# How to use it 

Compile the C program use ```make``` command..
Run it as follows:

```./mmaaparray [options]``` 
where ```options``` are as follows:
> ***--filename***: specifies the file name to be used in subsequent commands like ***--create*** or ***--set***. If this option is not give the filename defaults to ***namedb***.

> ***--index***: specifies the index to be used in subsequent commands like ***--set*** or ***--get***.

> ***--name***: specifies the name to be used in subsequent commands like ***--set***.

> ***--age***: specifies the age to be used in subsequent commands like ***--set***.

> ***--set***: modifies the array entry pointed to by index with values name and age. Age,name and index have to be specified by the corresponding command line option earlier.

> ***--get***: prints the array entry pointed to by index. Index hav e to be specified by the corresponding command line option earlier.

> ***--create***: creates a file with name specified by the most recent ***--filename*** command and size specified by the most recent ***--index*** command.

> ***--print***: prints all valid entries in the array.

> ***--maxindex***: returns the maximum index of the cuurent array.

> ***--delete***: deletes the element pointed to by the latest ***--index*** command by invalidating it.

# What I learned

* Better understanding of memory mapping in operating system.
* Familiarity with Linux System calls like ```mmap(2)```, ```stat(2)```, ```open(2)``` and ```ftruncate(2)```.

# License
[MIT](https://choosealicense.com/licenses/mit/)

