/*Programmer: Kyle Krick
Class: CS570 Operating Systems
Professor: John Carroll
Semester: Fall 2016
Due Date: 09/21/16*/
#include "getword.h"

#define SPACE ' '
#define NEWLINE '\n'
#define LSSR '<'
#define GRTR '>'
#define PIPE '|'
#define DLLR '$'
#define AMP '&'

/* The getword() function gets one word from the input stream.
* It returns -1 if end-of-file is encountered;
* otherwise, it returns the number of characters in the word
*
* INPUT: a pointer to the beginning of a character string
* OUTPUT: the number of characters in the word (or the negative of that number)
* SIDE EFFECTS: bytes beginning at address w will be overwritten.
*   Anyone using this routine should have w pointing to an
*   available area at least STORAGE bytes long before calling getword().
*/
int getword(char *w){
	/*numletters is the number of chars in current word*/
	int curchar = 0, numletters = 0;

	while ( (curchar = getchar()) != EOF ){
		/*Processing word, newline delimeter encountered - 
		return size*/
		if( (char)curchar == NEWLINE ){
			ungetc(NEWLINE, stdin);
			return numletters;
		}
		/*size > 0 means not leading blank, blank delimeter 
		encountered - return size*/
		else if( ((char)curchar == SPACE) && (numletters > 0) ){
			return numletters;
		}
		else{
			/*leading blank, do not add to string*/
			if( ((char)curchar == SPACE) && (numletters == 0) ){
				;
			}
			/*curchar not a delimeter - add curchar to string*/
			else{
				*w++ = curchar;
				*w = '\0';
				numletters++;				
			}
		}
	}/*while*/

	/*EOF encountered, null terminate string at beginning of 
	current word - return -1*/
	*(w - numletters) = '\0';
	return -1;
}