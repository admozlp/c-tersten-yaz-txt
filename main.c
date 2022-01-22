#include <stdio.h>
#include <stdlib.h>
#include <string.h>  //We added it to use strlen function

int main() 
{
	char character[100];
	char charac[100];
	char arr[20];
	int lenc=0;
	int i,j,a=0,b=0,v,h,y,flak,z,q;
	
	FILE *p, *p1;
	p = fopen("input.txt","r+");// Text file opened with read permission
	
	for(i=0;i<100;i++) // extract data from file to 'character'
	{
		fscanf(p,"%c",&character[i]);
		if(character[i] == '\n')// If the sentence is over, exit
		{
			break;
		}
	}
	fclose(p);// close file
	int uzunluk = strlen(character);//we found the length of the series where we shot the characters
	
	if(character[0]>=65 && character[0]<=90)//We checked if the first word starts with a capital letter.
		b++;
	for(z=0;z<uzunluk;z++)// move towards the end of the text
	{
		if(character[z] == ' ')//every space is a word
		{
			a++;
			if(character[z +1]>=65 && character[z+1]<=90)//does the new word start with a capital letter after the space?
			{
				b++;				//The ASCII table contains between 65 and 90 uppercase letters.
			}	
		}	
	}
	
	flak=0;
	h=0;
	for(v =0; v<a+1;v++)// Let's continue by word count
	{
		q=0;
		while(character[h]!=' ' && character[h]!='\n')//up to the blank (so a word)
		{
			arr[q] = character[h];	
			q++;	
			h++;
		}
		h++;
		lenc = strlen(arr);//We found the length of the word with the strlen function
		for(y=0;y<lenc;y++)
		{
			if((arr[y] == 'Ý' )|| (arr[y] == 'ý' )|| (arr[y] == 'ç' )||(arr[y] == 'Ç' )||(arr[y] == 'ð' )||(arr[y] == 'Ð' )||
			(arr[y] == 'ö' )||( arr[y] == 'Ö' )|| (arr[y] == 'þ' )|| (arr[y] == 'Þ' )||(arr[y] == 'ü' )||(arr[y] == 'Ü'))
			{//If the word contains any of these letters, it is not English.
				flak++;//Increase the number of non-English words
				break;
			}
		}
	}
	
	// console output
	printf("Console Output\n\n");
	printf("- %d words\n",a+1);//print word count on screen
	printf("- %d words starting with a capital letter\n",b);//we printed the number of words starting with capital letters 
																//on the screen
	printf("- %d words which contain no characters other than English letters",(a+1) - flak);
	//We subtracted the number of non-English words from the full word count and found the number of English words and
	// printed it on the screen.
																			
	
	// We print the reverse text to the output file
	p1 = fopen("output.txt","w");	
	for(j=0;j<=uzunluk;j++) // reverse the data.
	{
		charac[j] = character[i];// i end j points towards the head
		fputc(charac[j],p1);//Let's write the data to the file with the fputc function
		i--;	
	}	
	fclose(p1);//close file
	return 0;
}
