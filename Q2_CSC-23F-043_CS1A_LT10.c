#include<stdio.h>

int main()
{
	FILE *inputFile, *outputFile;
	int number, digit, sum = 0;
	
	// Open the input file for reading
	if((inputFile = fopen("Q2_input.txt", "r")) == NULL)
	{
		perror("Error opening input file!");
		return 1;
	}
	
	// Open the output file for writing
	if((outputFile = fopen("Q2_output.txt", "w")) == NULL)
	{
		perror("Error opening output file!");
		fclose(inputFile);
		return 1;
	}
	
	// Read the four-digit integer from the input file
	if(fscanf(inputFile, "%4d", &number) != 1)
	{
		fprintf(stderr, "Error reading from input file!");
		fclose(inputFile);
		fclose(outputFile);
		return 1;
	}
	
	// Calculate the sum of digits
	while(number > 0)
	{
		digit = number % 10;
		sum += digit;
		number /= 10;
	}
	
	// Write the sum to the output file
	fprintf(outputFile, "Sum of digits: %d\n", sum);
		
	// Close the files
	fclose(inputFile);
	fclose(outputFile);
	
	printf("Sum of digits has been written to Q2_output.txt\n");
		return 0;
}