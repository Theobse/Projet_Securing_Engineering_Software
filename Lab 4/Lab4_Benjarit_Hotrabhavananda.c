/*
 ============================================================================
 Name        : Lab4_Benjarit_Hotrabhavananda.c
 Author      : Benjarit Hotrabhavananda
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
//library//
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//function prototype//
int storeData(char*,FILE* ,int**);
double* offsetting(double,int*,int);
double* scaling(double,int*,int);
double find_average(int*,int);
int find_max(int*,int);

int main(int argc, char **argv){
	 	setbuf(stdout, NULL);
	 	//viable declaration
		char name_of_file[20],name_of_offset[20], name_of_scaling[20];
		int value , max_sample, size_of_sample;
		FILE *fp = NULL, *fp2 = NULL, *fp3 = NULL, *fp4 = NULL, *fp5 = NULL,*fp6 = NULL, *target = NULL;
		int *samples = NULL;
		double *transform, *transform_scaling, *transform_center, *transform_normal;
		char *ptr = NULL;
		int counter, sample_size = 0, counter2 = 0, check = 0;
		char new_name[20], source_file[100], name_of_statistic[20],name_of_center[20],name_of_normal[20];
	/*check if argrument are more than 2*/
	if(argc > 2){
		// First get the -n from command
		// need a file to modified
		//(isdigit(argv[counter+1][0]) && argv[counter+1][1] == '\0') || (isdigit(argv[counter+1][0]) && isdigit(argv[counter+1][1]) && argv[counter+1][2] == '\0')
		for(counter = 1; counter < argc; counter++){
			if(strcmp(argv[counter],"-n") == 0){
				if(argv[counter+1] != NULL){
					value = atoi(argv[counter+1]);
					sprintf(name_of_file, "Raw_data_%02d.txt", value);
					if((sample_size = storeData(name_of_file,fp,&samples)) != 0){
						printf("Load successful..\n\n");
						check = 1;
					}
					else{
						printf(" Unable to store..\n\n");
						return 0;
					}
				}
				else{
					printf("Error! Number of file was not given...\n\n");
					return 0;
				}
		 		fclose(fp);
			}
	    }
		if(check == 0){
				printf("Error! Could not find '-n' command .....");
				return 0;
	    }
		// run through each command one by one and process them
		// call function
		// increment counter each time switch statment complete
			for(counter = 1; counter < argc; counter++){
			if(argv[counter][0] == '-'){
			switch(argv[counter][1]){
				case 'n':
					counter++;
				break;
				case 'o':
					if(argv[counter+1] != NULL){
						transform = offsetting(strtod(argv[counter+1], &ptr),samples,sample_size);
						//printf("floating is %.2f\n\n",transform[0]);
						sprintf(name_of_offset, "Offset_data_%02d.txt", value);
						fp2 = fopen(name_of_offset, "w");
						fprintf(fp2,"%d  %.4f\n", sample_size, strtod(argv[counter+1], &ptr));
						while(counter2 < sample_size){
							fprintf(fp2,"%.4f\n", transform[counter2]);
							counter2++;
						}

					}
					else{
						printf("Wrong format2\n");
						return 0;
					}
				fclose(fp2);
				counter++;
				break;
				case 's':
					counter2 = 0;
					if(argv[counter+1] != NULL && (isalpha(argv[counter+1][0]) != 1)){
						transform_scaling = scaling(strtod(argv[counter+1], &ptr),samples,sample_size);
						sprintf(name_of_scaling, "Scaled_data_%02d.txt", value);
						fp3 = fopen(name_of_scaling, "w");
						fprintf(fp3,"%d  %.4f\n", sample_size, strtod(argv[counter+1], &ptr));
							while(counter2 < sample_size){
							fprintf(fp3,"%.4f\n", transform_scaling[counter2]);
							counter2++;
						}
					}
					else{
						printf("Wrong format3\n");
						return 0;
					}
				fclose(fp3);
				counter++;
				break;
				case 'r':
					sprintf(new_name, "%s%s", argv[counter+1],".txt");
					if(argv[counter+1] != NULL){
							fp = fopen(name_of_file,"r");
							target = fopen(new_name,"w");
							while(!feof(fp)){
								fgets(source_file,100,fp);
								fputs(source_file,target);
							}
							printf("File renamed successfully");

					}
					else{
						printf("Error: Name needed");
					}
				fclose(fp);
				fclose(target);
				counter++;
				break;
				case 'S':
					sprintf(name_of_statistic, "Statistics_data_%02d.txt", value);
					fp4 = fopen(name_of_statistic,"w");
					fprintf(fp4, "%.4f %d",find_average(samples,sample_size),find_max(samples,sample_size));
				fclose(fp4);
				break;
				case 'C':
					transform_center = offsetting(-find_average(samples,sample_size),samples,sample_size);
					sprintf(name_of_center, "Centered_data_%02d.txt", value);
					fp5 = fopen(name_of_center,"w");
					fprintf(fp5,"%d  %.4f\n", sample_size, -find_average(samples,sample_size));
					counter2 = 0;
					 while(counter2 < sample_size){
						fprintf(fp5,"%.4f\n", transform_center[counter2]);
						counter2++;
					}
				fclose(fp5);
				break;
				case 'N':
					fp = fopen(name_of_file,"r");
					fscanf(fp, "%d %d", &size_of_sample ,&max_sample);
					transform_normal = scaling((1.0/(double)max_sample),samples,sample_size);
					sprintf(name_of_normal, "Normalized_data_%02d.txt", value);
					fp6 = fopen(name_of_normal,"w");
					counter2 = 0;
					fprintf(fp6,"%d  %.4f\n", sample_size, (1.0/(double)max_sample));
					while(counter2 < sample_size){
						fprintf(fp6,"%.4f\n", transform_normal[counter2]);
						counter2++;
					}
				fclose(fp);
				fclose(fp6);
				break;
				default:
					printf("Error!! Missing command given.\n");
					return 0;
				}
			}
			else{
				printf("Wrong format4\n");
			}
		}
	}// end big if
	else{
		if(strcmp(argv[1],"-h") == 0){
			printf("\nUsage: %s -n IntValue\n\n", argv[0]);
			printf("-n: File number (value needed)\n-o: offset value (value needed)\n-s: scale factor (value needed)\n-r: Rename files (name needed)");
			return 0;
		}
		printf("Too few arguments...\n");
	}//end big else
	return 0;
}//end main
int storeData(char* name_of_file, FILE* fp, int** data){
	int size_of_sample, max_value, counter = 0;
	printf("Name of the file: %s\n\n", name_of_file);

	if((fp = fopen(name_of_file, "r")) == NULL){
		printf("File does not exist/file number not given.");
		return 0;
	}
	else{
		fscanf(fp,"%d %d", &size_of_sample, &max_value);
		*data = (int*)malloc((sizeof(int))*(size_of_sample));
		while(counter < size_of_sample){
			fscanf(fp,"%d", (*(data)+counter));
			counter++;
		}
		return counter;
	}
}
double* offsetting(double offset, int* data,int size){
	double *transform = (double*)malloc((sizeof(double))*(size));
	int counter = 0;
	while(counter < size){
		transform[counter] = (double)data[counter]+offset;
		counter++;
	}
	return transform;
}
double* scaling(double offset, int* data,int size){
	double *transform = (double*)malloc((sizeof(double))*(size));
	int counter = 0;
		while(counter < size){
			transform[counter] = (double)data[counter]*offset;
			counter++;
		}
		return transform;
}
double find_average(int* sameples, int size){
	int total = 0;
	int counter = 0;
	double average;
	while(counter < size){
		total += sameples[counter];
		counter++;
	}
	average = (double)total/size;
	return average;
}
int find_max(int* sameples,int size){
	int counter = 0;
	int max = 0;
	while(counter < size){
		if(sameples[counter] >= max){
			max = sameples[counter];
		}
		counter++;
	}
	return max;
}
