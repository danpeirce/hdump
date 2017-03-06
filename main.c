// modified from http://simplestcodings.blogspot.ca/2010/08/hex-dump-file-in-c.html

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define HEX_OFFSET    1
#define ASCII_OFFSET 51
#define NUM_CHARS    16


void   hexdump(char* prog_name, char * filename);
int output_line(FILE *fileptr);

/* Clear the display line.  */
void   clear_line (char *line, int size);


int main(int argc, char * argv[])
{
    //char *prog_name="hexdump";

    if (argc != 2)
    {
        printf("\n\t%s syntax:\n\n", argv[0]);
        printf("\t\t%s filename\n\n", argv[0]);
        exit(0);
    }

    hexdump( argv[0], argv[1]);

    return (0);
}


void hexdump(char* prog_name, char * filename)
{
    FILE *fptr;      /* Pointer to the file.   */
    int c=' ';      /* Character read from the file */

    /* Open the file    */
    fptr = fopen(filename,"r");
    if ( ferror(fptr) )
    {
        printf("\n\t%s: Unable to open %s\n\n", prog_name, filename);
        exit(0);
    }

    printf("\n\tHex dump of %s\n\n", filename);

    while (c != EOF )
    {
        c = output_line(fptr);
    }

    fclose(fptr);
}

int output_line(FILE *fileptr)
{
    char line[81];        /* O/P line.      */
    int c=' ';      /* Character read from the file */

    char *hex_position;     /* Position of the next character
                                                 * in Hex     */

    char *ascii_position;      /* Position of the next character
                                                       * in ASCII.      */
    clear_line(line, sizeof line);
    hex_position   = line+HEX_OFFSET;
    ascii_position = line+ASCII_OFFSET;

    while ( ascii_position < line+ASCII_OFFSET+NUM_CHARS && (c = fgetc(fileptr)) != EOF  )
    {
        const int shift=3;
        unsigned char print_c;

        sprintf(hex_position, "%02X ", (unsigned char) c); // put hex representation int the line
        hex_position = hex_position + shift;


        // If the character is NOT printable replace it with a '.'
        if (isprint(c)) print_c = c;
        else print_c = '.';
        sprintf(ascii_position++, "%c", print_c);    // Put the character to the line
                                               // so it can be displayed later

    }
    *hex_position = ' '; // remove /0 added by sprintf
    printf("%s\n", line);

    return c;
}


void clear_line(char *line, int size)
{
    int count;

    for  (count=0; count < size; line[count]=' ', count++);
}

