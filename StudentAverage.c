/*                                                           
*	@@@@@@@@  @@@@@@@@  @@@@@@@    @@@@@@              @@@@@@@  
*	@@@@@@@@  @@@@@@@@  @@@@@@@@  @@@@@@@@             @@@@@@@  
*	     @@!  @@!       @@!  @@@  @@!  @@@               @@!    
*	    !@!   !@!       !@!  @!@  !@!  @!@               !@!    
*	   @!!    @!!!:!    @!@!!@!   @!@  !@!  @!@!@!@!@    @!!    
*	  !!!     !!!!!:    !!@!@!    !@!  !!!  !!!@!@!!!    !!!    
*	 !!:      !!:       !!: :!!   !!:  !!!               !!:    
*	:!:       :!:       :!:  !:!  :!:  !:!               :!:    
*	 :: ::::   :: ::::  ::   :::  ::::: ::                ::    
*	: :: : :  : :: ::    :   : :   : :  :                 :     	                                                            
*
* File: StudentAverage.c
*
* Course:  Course name here
* Project: Project name here
*
* Project Description: Students Grade Average with use Memory Allocation
*
* Author:  Zero-T
* Number:  Your number.
*
* Created on August 31, 2013 | 12:07:04 pm EEST
*/
#include <stdio.h>
#include <string.h> /* for strcmp, */
#include <stdlib.h> /* dynamic memory allocation */

void
usage(void); 

void
version(void);

int
calculateGradeAverage(int *, int);                                            

int 
main(int argc, char const *argv[])
{
	int i;
	int *studentsGrade;

	if (argc == 1)
	{
		/* bad usage */
			usage();
	}
	else if (argc == 2 )
	{
		if(strcmp(argv[1],"-v") == 0)
		{
			/* Print Program version. */
			version();
		}
		else if (strcmp(argv[1],"-d") == 0)
		{
			/* Print Author information. */
			printf("Not supported yet.\n");
			usage();
		}
		else /* bad usage */
		{
			usage();
		}
	}
	else
	{
		if (strcmp(argv[1],"-s") != 0)
		{
			/* bad usage */
			usage();
		}
		else
		{
			studentsGrade = (int *)calloc( (argc-2), sizeof(int) );
			for ( i = 0; i < argc-2; ++i)
			{
				studentsGrade[i] = atoi(argv[i+2]);
			}
		}
	}

	printf("Students grade average is %d.\n",calculateGradeAverage(studentsGrade,argc-2));


	free(studentsGrade);
	return 0;
}
void
usage(void)
{
	printf("Usage: ./StudentAverage [OPTION] [INPUT]\n"
			"\n"
			"\tOPTION: -v --- Show version.\n"
					  "\t\t-d --- Show Author name and sirname.\n"
					  "\t\t-s --- Calculate students average grade.\n"

			"\tINPUT: Only accept when you use [-s] option.\n");
	exit(0);
} 

int
calculateGradeAverage(int *studentsGrade, int numbOfStu)  
{
	int i = 0;
	int sum = 0;


	while(i < numbOfStu)
	{
		sum += studentsGrade[i];
		++i;
	}

	return sum/numbOfStu;
} 

void
version(void)
{
	printf("\n\n\t\t\tStudents Grade Average Program\n"
			"\t\t\t\tVersion: 1.000\n"
			"\t\t\t      Copyright (c) 2013\n"

		);
	exit(0);
}          