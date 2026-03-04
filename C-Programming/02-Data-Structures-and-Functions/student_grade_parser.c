#include <stdio.h>
#include <string.h>

/**
 * Parses student marks from a formatted string and calculates the weighted average.
 * Input Format: #midterm1#midterm2#final#
 * Weights: 30% Midterm1, 30% Midterm2, 40% Final
 */
int grade(char s[]) {
    int m1, m2, fnl;
    
    /* 
       sscanf is a powerful function to parse data from a string.
       It looks for the pattern #num#num#num# and extracts the integers.
    */
    sscanf(s, "#%d#%d#%d#", &m1, &m2, &fnl);
    
    // Calculate the overall marks based on weights
    float overall_marks = (m1 * 0.30) + (m2 * 0.30) + (fnl * 0.40);
    
    // Returning as integer as requested by the function signature
    return (int)overall_marks;
}

int main() {
    char s[40];
    
    printf("Enter student's information:\n");
    /* Read the formatted string (e.g., #66#75#90#) */
    scanf("%s", s);
    
    /* Print the final result in #marks# format */
    printf("#%d#\n", grade(s));
    
    return 0;
}
