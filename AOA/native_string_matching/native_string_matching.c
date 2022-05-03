#include<stdio.h>
#include<string.h>

void native_string_matcher(char text[],char pat[]) {

    char temp[100];
    int n = strlen(text);
    int m = strlen(pat);

    int i,j,s,k, count =0;
    for (s = 0; s <= n; s++){
        for (j = s, k = 0; j < m; j++, k++)
            temp[k] = text[s + k];
        temp[k] = '\0';
        if(strcmp(pat, temp) == 0) {
            printf("\n Pattern occurs with shift: %d", s);
            count++;
        }
        m++;
    }
    printf("\n\n No of times pattern occurs %d:", count);
}

int main() {
    char text[100], pat[100];
    printf("\n ENTER THE TEXT:");
    gets(text);
    printf("\n ENTER THE PATTERN:");
    gets(pat);
    native_string_matcher(text, pat);
    return 0;
}

/*
 *  ENTER THE TEXT:AAAAABBCCA

 ENTER THE PATTERN:CC

 Pattern occurs with shift: 7

 No of times pattern occurs 1:
 */