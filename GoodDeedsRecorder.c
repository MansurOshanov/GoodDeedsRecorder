/*
 ============================================================================
 Name        : Assignment2.c
 Author      : Mansur Oshanov
 Version     :			C
 Copyright   : Your copyright notice
 Description : Good deeds
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {				//using this struct type to store information
    int deed_id;				//for the individual deed
    char deed_name[55];
    int points_for_deed;
    int total_times_done;
    int total_points_earned;
} deed;

//Prints to the console after sorting by total times done
//if total times done for some deeds is zero, it will not be displayed
void printArray1(deed **x, int size) {
	printf("Task1: After sort by deeds total_times_done:\n");
	printf("No |                      ---------deed_name---------                  |deed    |total     |total\n");
	printf("   |                                                                   |point   |times     |points\n");
	int i;
		for (i = size-1; i >=0; i--) {
			if ((*(x+i))->total_times_done!=0){
				printf("%3i %3i %55s %10i %10i %10i \n", size-i, (*(x+i))->deed_id, (*(x+i))->deed_name, (*(x+i))->points_for_deed, (*(x+i))->total_times_done, (*(x+i))->total_points_earned);
			} else {break;}
		}
	printf("\n");
}

//Prints to the console after sorting by total points earned
//if total points earned for some deeds is zero, it will not be displayed
void printArray2(deed **x, int size) {
	printf("Task2: After sort by deeds total_points_earned:\n");
	printf("No |                	  ---------deed_name---------                  |deed    |total     |total\n");
	printf("   |                                                                   |point   |times     |points\n");

	int i;
	for (i = size-1; i >=0; i--) {
		if ((*(x+i))->total_points_earned!=0){
			printf("%3i %3i %55s %10i %10i %10i \n", size-i, (*(x+i))->deed_id, (*(x+i))->deed_name, (*(x+i))->points_for_deed, (*(x+i))->total_times_done, (*(x+i))->total_points_earned);
		} else {break;}
	}
	printf("\n");
}

//Prints to the console after sorting alphabetically
void printArray3(deed **x, int size) {
	printf("Task5: After sort alphabetically:\n");
	printf("No |                      ---------deed_name---------                  |deed    |total     |total\n");
	printf("   |                                                                   |point   |times     |points\n");

	int i;
	for (i = 0; i<size; i++) {
		printf("%3i %3i %55s %10i %10i %10i \n", i+1, (*(x+i))->deed_id, (*(x+i))->deed_name, (*(x+i))->points_for_deed, (*(x+i))->total_times_done, (*(x+i))->total_points_earned);
	}
	printf("\n");
}

//function that sorts by total times done using the selection sort
void selectionSortByTimesDone(deed **x, int size) {

     int i;
     for (i = 0; i < size - 1; i++) {

          int j, mindex = i;
          for (j = i + 1; j < size; j++) {
               if ((*(x + j))->total_times_done < (*(x+mindex))->total_times_done) {
                    mindex = j;
			   }
          }

          int *temp = (*(x+i));
          (*(x+i)) =(*(x+mindex));
          (*(x+mindex)) = temp;
     }
}

//function that sorts by total points earned using the selection sort
void selectionSortByPointsEarned(deed **x, int size) {

     int i;
     for (i = 0; i < size - 1; i++) {
          int j, index = i;
          for (j = i + 1; j < size; j++) {
               if ((*(x + j))->total_points_earned < (*(x+index))->total_points_earned) {
                    index = j;
			   }
          }
          int *temp = (*(x+i));
          (*(x+i)) =(*(x+index));
          (*(x+index)) = temp;
     }
}

//function that calculates total deed counts and total deed points, and prints it to the console
void totalNumberOfDeedsAndPoints(deed **x, int size){
	int i, sum1=0, sum2=0;
	for (i=0; i<size; i++){
		sum1=sum1+(*(x+i))->total_times_done;
		sum2=sum2+(*(x+i))->total_points_earned;
	}
	printf("Task3: Total deed_counts:\n");
	printf("  %i deeds\n\n", sum1);
	printf("Task4: Total deed_points:\n");
	printf("  %i points\n\n",sum2);
}

//function that sorts alphabetically using the bubble sort
void BubbleSortByNames(deed **x, int size){
	int i,j;
	for (j = 0; j < size -1; j++) {
		for (i = 0; i < size -1; i++) {
			if (0 < strcmp(x[i]->deed_name, x[i +1]->deed_name)) {
				char* pchTemp = x[i];
				x[i] = x[i +1];
				x[i +1] = pchTemp;
			}
		}
	}
}

//function that finds certain deed using binary search in a alphabetically sorted elements
//if it doesn't find, it prints "no such deed"
void binarySearchOfDeed1(deed **x, int size) {
	char keydeed[60];
	printf("Enter a deed's name\n");
	scanf("%s", keydeed);
	int min = 0;
	int max = size-1;

	while (min <= max) {
		int guess = (min + max) / 2;
		if (strcmp(x[guess]->deed_name, keydeed)==0) {
			printf("Task6: Search case 1:\n");
			printf("%s\n", x[guess]->deed_name);
			printf("%i times, %i points earned\n\n", x[guess]->total_times_done, x[guess]->total_points_earned);
			return;
		} else if (0 < strcmp(x[guess]->deed_name, keydeed)) {
			max = guess - 1;
		} else {
			min = guess + 1;
		}
	}
	printf("Task6: Search case 1:\n");
	printf("No such deed\n\n");
}

//the similar binary search function for search case 2
void binarySearchOfDeed2(deed **x, int size) {
	char keydeed[60];
	printf("Enter a deed's name\n");
	scanf("%s", keydeed);
	int min = 0;
	int max = size-1;

		while (min <= max) {

			int guess = (min + max) / 2;

			if (strcmp(x[guess]->deed_name, keydeed)==0) {
				printf("Task6: Search case 2:\n");
				printf("%s\n", x[guess]->deed_name);
				printf("%i times, %i points earned\n\n", x[guess]->total_times_done, x[guess]->total_points_earned);
				return;
			} else if (0 < strcmp(x[guess]->deed_name, keydeed)) {
				max = guess - 1;
			} else {
				min = guess + 1;
			}
		}
		printf("Task6: Search case 2:\n");
		printf("No such deed\n\n");
}

//main body of the program, where files are being read and memory is being allocated
int main(void) {
    setvbuf(stdout, NULL, _IONBF, 0);
	FILE*DeedList;
	DeedList=fopen("deed_list.txt", "r");
	int NumberOfDeeds, i;
	fscanf(DeedList, "%i", &NumberOfDeeds);

	// first we allocate memory for pointers
	deed **deed_list = (deed**)(malloc(NumberOfDeeds*sizeof(deed)));

	//then we allocate memory for struct, these pointers are pointing to
	for (i=0; i<NumberOfDeeds; i++){
			*(deed_list+i)=(deed*)malloc(sizeof(deed));
			fscanf(DeedList, "%i %s %i", &(*(deed_list + i))->deed_id, &(*(deed_list + i))->deed_name, &(*(deed_list + i))->points_for_deed);
			(*(deed_list + i))->total_times_done=0;
			(*(deed_list + i))->total_points_earned=0;
	}
	fclose(DeedList);

	//reading content of the daylog.txt, and updating the two fields of the deed struct items in the array
	FILE*DayLog;
	DayLog=fopen("daylog.txt", "r");
	int x, y, j;
	while (!feof(DayLog)){
		fscanf(DayLog, "%i %i", &x, &y);
		for (j=0; j<NumberOfDeeds; j++){
			if (x==(*(deed_list + j))->deed_id) {
				(*(deed_list + j))->total_times_done=y+(*(deed_list + j))->total_times_done;
				(*(deed_list + j))->total_points_earned=y*(*(deed_list + j))->points_for_deed+(*(deed_list + j))->total_points_earned;
				break;
			}
		}

	}
	fclose(DayLog);

	//functions are called to perform tasks that are being required
	selectionSortByTimesDone(deed_list, NumberOfDeeds);
	printArray1(deed_list, NumberOfDeeds);
	selectionSortByPointsEarned(deed_list, NumberOfDeeds);
	printArray2(deed_list, NumberOfDeeds);
	totalNumberOfDeedsAndPoints(deed_list, NumberOfDeeds);
	BubbleSortByNames(deed_list, NumberOfDeeds);
	printArray3(deed_list, NumberOfDeeds);
	binarySearchOfDeed1(deed_list, NumberOfDeeds);
	binarySearchOfDeed2(deed_list, NumberOfDeeds);

	//frees dynamically allocated memory
	for (i=0; i<NumberOfDeeds; i++){
		free(deed_list+i);
	}
	free(deed_list);
	return 0;
}

