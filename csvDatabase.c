//
//  csvDatabase.c
//  csvdb
//
//  Created by Marlon Juntorius on 23.01.23.
//

#include "csvDatabase.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


// "/Users/marlonjuntorius/Desktop/csvdb.csv"

FILE* fp;

int readfile(char* file)
{
    fp = fopen(file , "r");
    
    // prüfen, ob der file geöffnet werden kann.
    
    if(!fp)
        {
        printf("file could not be opened \n !");
        return 1;
        }
    
    else {
        // Here we have taken size of
        // array 1024 you can modify it
        char buffer[1024];
        
        int row = 0;
        int column = 0;
        
        while (fgets(buffer, 1024, fp)) {
            column = 0;
            row++;
            
            // To avoid printing of column
            // names in file can be changed
            // according to need
            if (row == 1)
                continue;
            
            // Splitting the data
            char* value = strtok(buffer, "; ");
            
            while (value) {
                // Column 1
                if (column == 0) {
                    printf("Name :");
                }
                
                // Column 2
                if (column == 1) {
                    printf("\t URL :");
                }
                
                // Column 3
                if (column == 2) {
                    printf("\t Description :");
                }
                
                printf("%s", value);
                value = strtok(NULL, "; ");
                column++;
            }
            
            printf("\n");
        }
        
        // Close the file
        fclose(fp);
    }
    return 0;
}




int writefile(char* file)
    {
    // Substitute the file_path string
    // with full path of CSV file
    FILE* fp = fopen(file, "a+");
    
    char name[20];
    char url[25];
    char desc[50];
    
    if (!fp) {
        // Error in file opening
        printf("Can't open file\n");
        return 0;
    }
    
    // Asking user input for the
    // new record to be added
    printf("\nEnter Name: \n");
    scanf("%s", name);
    printf("\nEnter URL: \n");
    scanf("%s", url);
    printf("\nEnter description: \n");
    scanf("%s", desc);
    
    // Saving data in file
    fprintf(fp, "%s; %s; %s\n", name,
            url, desc);
    
    printf("\nNew Account added to record");
    
    fclose(fp);
    return 0;
    
    }
