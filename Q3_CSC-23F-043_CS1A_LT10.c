#include<stdio.h>

int main()
{
		FILE *inputFile, *outputFile;
		char filename[] = "Q3_input.txt";
		char ch;

		// Open input file for reading
		inputFile = fopen(filename, "r");
		if(inputFile == NULL)
		{
			printf("Error opening file %s for reading!\n", filename);
			return 1;
		}
	
		// Open output file for writing
		outputFile = fopen("Q3_output.txt","w");
		if(outputFile == NULL)
		{
			printf("Error opening file Q3_output.txt for writing!\n");
			fclose(inputFile);
			return 1;
		}
		
		// Process each character in the input file
		while((ch = fgetc(inputFile)) != EOF)
		{
			if(ch >= '0' && ch <= '9')
			{
				// Replace number with '$'
				fputc('$', outputFile);
				// Skip the rest of the digits in the number
				while((ch = fgetc(inputFile)) >= '0' && ch <= '9');
			}
			else
			{
				// Copy non-numeric characters as they are
				fputc(ch, outputFile);
			}
		}
		
		// Close both files
		fclose(inputFile);
		fclose(outputFile);
		
		printf("Replacement complete. Check the Q3_output.txt file.\n");
		
	return 0;
}