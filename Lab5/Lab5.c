/*
 ============================================================================
 Name        : Lab5.c
 Author      : Choma, Theodore, D
 Version     : 1.0
 Copyright   : Your copyright notice
 Description : Lab 5
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


void offset(int numdata, int* array, double factor, int numfile);
void center(int numdata, int* array, double avg, int numfile);
void normal(int numdata, int* array, int max, int numfile);
void scale(int numdata, int* array, double factor, int numfile);
double average(int numdata, int* array);
int maximum(int numdata, int* array);


int main(int argc, char** argv) {
	int numfile = 0, numdata, maxdata, i, array[50], max;
	char str[25], outstr[25];
	double factor, avg;
	FILE *fp;


	printf("\nSTART\n");
        printf("ARGC == %d", argc);
        
	//OPENING FILE
	for(i = 0; i < argc; i++)
	{
		if(argv[i][1] == 'n')
		{
			//File opening
                        printf("\nBEGIN FILE OPENING");
                        fflush(stdout);
			numfile = atoi(argv[i+1]);
                            printf("\n numfile is %d", numfile);
                            fflush(stdout);
                                if(numfile > 9)
                                {
                                    printf("\nFILE > 10");
                                    fflush(stdout);
                                    sprintf(str, "Raw_data_%d.txt", numfile);
                                }
				else
                                {
                                    printf("\nFILE < 10");
                                    fflush(stdout);
                                    sprintf(str, "Raw_data_0%d.txt", numfile);
                                }
                        printf("\nFILE NAME: %s", str);
                        fflush(stdout);
			fp = fopen(str, "r");
			if(fp == NULL)
			{
				perror("\n!!!Error opening file!!!\n");
                                return 0;
			}
                        else
                        {
                                printf("\nFile opened successfully\n");
                        }
			
                        //data parsing
                        printf("\nBEGIN DATA PARSING");
                        fflush(stdout);
			fscanf(fp, "%d", &numdata);
                        printf("\nnumdata = %d", numdata);
			fflush(stdout);
                        fscanf(fp, "%d", &maxdata);
                        printf("\nmaxdata = %d", maxdata);
			fflush(stdout);
                        for(i = 0; i < numdata; i++)
			{
				fscanf(fp, "%d", &array[i]);
			}
                        printf("\nCLOSE POINTER");
                        fflush(stdout);
			fclose(fp);
		}
	}



	//OFFSET CASE
	for(i = 0; i < argc; i++)
	{
		if(argv[i][1] == 'o')
		{
                    printf("\nOFFSET CASE");
                    fflush(stdout);
                    factor = (double)argv[i+1][0];
                    offset(numdata, array, factor, numfile);
		}
	}



	//SCALE CASE
	for(i = 0; i < argc; i++)
	{
		if(argv[i][1] == 's')
		{
		factor = (double)argv[i+1][0];
		scale(numdata, array, factor, numfile);
		}
	}



	//STATS CASE
	for(i = 0; i < argc; i++)
	{
		if(argv[i][1] == 'S')
		{
		//Gather Statistics
		avg = average(numdata, array);
		max = maximum(numdata, array);

		sprintf(outstr, "Statistics_data_%d.txt", numfile);
        fp = fopen(outstr, "w");
        if(fp == NULL)
        {
                perror("\n!!!Error opening writing file!!!\n");
        }
        else
        {
                fprintf(fp, "%lf %d\n", avg, max);
        }
        fclose(fp);

		}
	}



	//CENTERING CASE
	for(i = 0; i < argc; i++)
	{
		if(argv[i][1] == 'C')
		{
			center(numdata, array, avg, numfile);
		}
	}


	//NORMALIZING CASE
	for(i = 0; i < argc; i++)
	{
		if(argv[i][1] == 'N')
		{
			normal(numdata, array, max, numfile);
		}
	}

        
        //RENAMING CASE
	for(i = 0; i < argc; i++)
	{
		if(argv[i][1] == '-r')
		{
			rename(str, argv[i+1]);
		}
	}
        
        //help case
        for(i = 0; i < argc; i++)
        {
            if(argv[i][1] == 'h')
            {
                printf("\nCommands are as follows:\n----------\n-n (number) --- opens file n\n-o (number) --- offsets data by input value\n-s (number) --- scales data by input value\n-S --- gets statistics\n-N --- normalizes data\n-C --- centers data\n-r (name) --- rename file\n-h --- help\n\n");
            }
        }
	return EXIT_SUCCESS;
}





double average(int numdata, int* array)
{
    double out = 0;
    int i = 0;

    for(i = 0; i < numdata; i++)
    {
        out = out + (double)array[i];
    }
    out = out / (double)numdata;

    return out;

}





int maximum(int numdata, int* array)
{
    int out = array[0];
    int i = 0;
    for(i = 0; i < numdata; i++)
    {
        if(out < array[i])
            out = array[i];
    }

    return out;

}





void offset(int numdata, int *array, double factor, int numfile)
{
	double outarray[50];
	int i;
	char outstr[50];
	FILE *fp;

	for(i = 0; i < numdata; i++)
	{
		outarray[i] = (double)array[i] + factor;
	}

	//saving
	sprintf(outstr, "Offset_data_%d.txt", numfile);
	fp = fopen(outstr, "w");
	if(fp == NULL)
	{
		perror("\n!!!Error opening writing file!!!\n");
	}
	else
	{
		fprintf(fp, "%d %lf\n", numdata, factor);
		for(i = 0; i < numdata; i++)
		{
			fprintf(fp, "%lf\n", outarray[i]);
		}
	}
	fclose(fp);
}





void scale(int numdata, int *array, double factor, int numfile)
{
	double outarray[50];
	int i;
	char outstr[50];
	FILE *fp;

	for(i = 0; i < numdata; i++)
	{
		outarray[i] = (double)array[i] * factor;
	}

	//saving
	sprintf(outstr, "Scaled_data_%d.txt", numfile);
	fp = fopen(outstr, "w");
	if(fp == NULL)
	{
		perror("\n!!!Error opening writing file!!!\n");
	}
	else
	{
		fprintf(fp, "%d %lf\n", numdata, factor);
		for(i = 0; i < numdata; i++)
		{
			fprintf(fp, "%lf\n", outarray[i]);
		}
	}
	fclose(fp);
}





void center(int numdata, int *array, double avg, int numfile)
{
	double outarray[50];
	int i;
	char outstr[50];
	FILE *fp;

	for(i = 0; i < numdata; i++)
	{
		outarray[i] = (double)array[i] - avg;
	}

	//saving
	sprintf(outstr, "Centered_data_%d.txt", numfile);
	fp = fopen(outstr, "w");
	if(fp == NULL)
	{
		perror("\n!!!Error opening writing file!!!\n");
	}
	else
	{
		fprintf(fp, "%d %lf\n", numdata, avg);
		for(i = 0; i < numdata; i++)
		{
			fprintf(fp, "%lf\n", outarray[i]);
		}
	}
	fclose(fp);
}





void normal(int numdata, int *array, int max, int numfile)
{
	double outarray[50];
	int i;
	char outstr[50];
	FILE *fp;

	for(i = 0; i < numdata; i++)
	{
			outarray[i] = (double)array[i] / (double) max;
	}

	//saving Normal
	sprintf(outstr, "Normalized_data_%d.txt", numfile);
	fp = fopen(outstr, "w");
	if(fp == NULL)
	{
			perror("\n!!!Error opening writing file!!!\n");
	}
	else
	{
			fprintf(fp, "%d %d\n", numdata, max);
			for(i = 0; i < numdata; i++)
			{
					fprintf(fp, "%lf\n", outarray[i]);
			}
	}
	fclose(fp);
}
