//
//  main.c
//  csvdb
//
//  Created by Marlon Juntorius on 23.01.23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csvDatabase.h"

FILE* fp;


int main(int argc, const char * argv[]) {
    
    char data[] ="/Users/marlonjuntorius/Desktop/csvdb.csv";
    
    readfile(data);
    writefile(data);
    readfile(data);
}
    
