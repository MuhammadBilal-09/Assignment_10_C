#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>

int countVowels(FILE *file)
{
	int count = 0;
	int ch;
	
	while((ch = fgetc(file)) != EOF)
	{
		switch (tolower(ch))
		{
			case 'a':
			case 'e':
			case 'i':
			case 'o':
			case 'u':
				count++;
				break;
			default:
				break;
		}
	}	
		return count;
}

int main()
{
	FILE *file;
	char filename[100];
	
	// Get the file name from user
	printf("Enter the file name: ");
	scanf("%s", filename);
	
	// Open the file
	file = fopen(filename, "r");
	
	// Check if the file is opened successfully
	if(file == NULL)
	{
		perror("Error opening file!");
		return 1;
	}
	
	// Count the vowels in the file
	int vowelCount = countVowels(file);
	
	// Close the file
	fclose(file);
	
	// Display the result
	printf("Number of vowels in this file: %d\n", vowelCount);
		return 0;
}