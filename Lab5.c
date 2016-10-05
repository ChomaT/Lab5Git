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
	char str[15], outstr[25];
	double factor, avg;
	FILE *fp;


	printf("\nSTART\n");
	//OPENING FILE
	for(i = 0; i < argc; i++)
	{
		if(argv[i][1] == 'n')
		{
			//File opening
			numfile = argv[i+1][0];
				if(numfile > 9)
					sprintf(str, "Raw_data_%d.txt", numfile);
				else
					sprintf(str, "Raw_data_0%d.txt", numfile);
			fp = fopen(str, "r");
			if(fp == NULL)
			{
				perror("\n!!!Error opening file!!!\n");
			}

			printf("\nFile opened successfully\n");

			//data parsing
			fscanf(fp, "%d", &numdata);
			fscanf(fp, "%d", &maxdata);
			for(i = 0; i < numdata; i++)
			{
				fscanf(fp, "%d", &array[i]);
			}
			fclose(fp);
		}
	}



	//OFFSET CASE
	for(i = 1; i < argc; i++)
	{
		if(argv[i] == "-o")
		{
		factor = (double)argv[i+1][0];
		offset(numdata, array, factor, numfile);
		}
	}



	//SCALE CASE
	for(i = 1; i < argc; i++)
	{
		if(argv[i] == "-s")
		{
		factor = (double)argv[i+1][0];
		scale(numdata, array, factor, numfile);
		}
	}



	//STATS CASE
	for(i = 1; i < argc; i++)
	{
		if(argv[i] == "-S")
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
	for(i = 1; i < argc; i++)
	{
		if(argv[i] == "-C")
		{
			center(numdata, array, avg, numfile);
		}
	}


	//NORMALIZING CASE
	for(i = 1; i < argc; i++)
	{
		if(argv[i] == "-N")
		{
			normal(numdata, array, max, numfile);
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
