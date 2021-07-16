Begin:
sudo apt-get update
sudo apt-get install vim: update environment and install vim for C code

I:Everything is file
	1.expanded-name in Linux is meaningless, Linux distinguishes the file type through its authorities
	2.habitual expanded-name: 
		compressed package: '*.gz' '*.bz2' '*.tar.bz2' '*.tgz'
		binary installation package: '*.rpm'
		website file: '*.html' '*.php'
		script file: '*.sh'
		configuration file: '*.conf'

II:Zone
	1.main zone: 4 at most
	2.extend zone: 1 at most
		(main zone + extend zone <= 4)
		contain logical zone: 23 at most
	3.formatting: 


'cd name':   go to folder called 'name'
	'cd':    go back to home folder
	'cd ..': go back to front folder
'pwd':       show detailed path
'ls':        show documents inclueded
	'ls -l': show documents inclueded and their informations like creation times,  authorities
  	'ls /':  show root content
'clear':     clear current window

'touch name':      create a file called 'name' in current folder
'rm name':         remove file
	'rm -rf name': remove folder
  	'rm *.name':   remove all the file end with '.name'
'mkdir name':      create a folder in current folder
'cd name':         move into a folder
'cp name1 name2':  copy a new file called 'name2', which is similar to fill called 'name1'
'ps -e':           show all running progress 

1.Create and compile a C code file
	1.'touch name.c'
	2.'vi name.c'
	3.'ECS': switch to commander mode
		1.'wq':         save and quit
		  'wqa':        save all and quit
		2.'sp name1.c': create a new program in another window
			Ctrl + W + down/up: change the cursor to another window
		3.'set nu':     show line number
		4.'number + DD': cut lines below
		  'p':           paste lines
	4.'gcc name.c' -o name.out 
	5.'./name.out'
	6.'cat name.c': look over the code

2.Change C code to machine code(develop the compiling efficiency)
	'gcc -c func1.c -o func1.o'
	'gcc -c func2.c -o func2.o'
	'...'
	'gcc -c func1.o func2.o ... main.c -o main.out'

3.Change C code file to header file
	EX: file max.c includes:
		#include<stdoi.h>;
		int max(int a, int b)
		{
			...;	
		}
		then type vi max.h and input 'int max(int a, int b)'
		file max.h can be imported through '#include "max.h"' 

4.Use 'make' to avoid everytime use 'gcc ... -o main.out' to make a program
	1.'make -v': check the version, if not, 'sudo apt-get install make'
	2.'vi Makefile' here is it includes:
		# this is Makefile
		main.out:main.c func1.o func2.o ...
			gcc main.c func1.o func2.o ... -o main.out
		func1.o:func1.c
			gcc -c func1.c
		func2.o:func2.c
			gcc -c func2.c
	3.'make'(directly type)

5.Intact main function:
	int main(int argv, char* argc[])
	{
		...;
		return 0;
	}
	1.use '&&' to connect commands:
		EX1: 'gcc main.c -o main.out && ./main.out' 
		if the first command works, then the followings will go on
		EX2: file max.c includes:
			 #include<stdoi.h>;
			 int main()
			 {
				 ...;
				 return 404;	
			 }	
			 then type './main.out && ls', it will not show files list because main.out not return 0
			 it can be used to avoid severer errors, for example,
			 in file main.c, write a function to detect errors, if find, return a number (not 0)
			 this number can also show the kind of error
			 EX: file max.c includes:
			 	 #include<stdoi.h>;
			 	 int main()
				 {
				 	...;
				 	if(some errors happen){
				 		return 404;
				 	}
				 	return 0;
			 	 }	
	2.after execute a command, type 'echo $?' to check if the program runs correctly (it will return 0)
	3.argv:   number of parameters passed in - 1
	  argc[]: contains parameters passed in

6.stdin, stdout, stderror
	When a program running, these 3 files will be created
	default stdin is keyboard
	default stdout is screen

	#include<stdio.h>
	/*
	stdin
	stdout
	stderr
	*/
	int main()
	{
		int n;
		// printf("input a nunber");
		fprintf(stdout, "positive number:");
		// scanf("%d", &n);
		fscanf(stdin, "%d", &n);
		if(n < 0){
			fprintf(stderr, "negative!");
			return 1;
		}
		return 0;
	}

7.Rdirection:
	1.redirect stdout: 
		1>>: add
		1>:  cover
		EX: ./main.out >> main.txt
		the output will not show on screen but in main.txt
	2.redirect stdin:
		<: add
		EX: ./
	3.redirect stderr:
		2>>: add
		2>:  cover
	EX: file main.c includes:
	#include<stdio.h>
	int main()
	{
		int i, j;
		printf("i:\n");
		scanf("%d", &i);
		printf("j:\n");
		scanf("%d", &j);
		if(0 == j){
			fprintf(stderr, "j cannot be 0");
			return 404;
		}
		printf("i/j is %d", i/j);
		return 0;
	}
	./main.out 1> main.txt 2> error.txt < input.txt

8.Tube 
	'|':transport output of programA to programB as its input
	1.'grep name': search the file whose name includes 'name'
		'ls | grep name': search in current folder


