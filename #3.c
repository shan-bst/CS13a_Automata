#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;

    /*
        States:
        0 = S (Start)
        1 = C
        2 = A
        3 = B (Final)
    */

    printf("Enter a binary string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {

        if (input[i] != '0' && input[i] != '1') {
            printf("Invalid input! Use only 0 and 1.\n");
            return 1;
        }

        switch (state) {

            // S
            case 0:
                if (input[i] == '0')
                    state = 1;   
                else
                    state = 0;  
                break;

            // C
            case 1:
                if (input[i] == '0')
                    state = 1;   
                else
                    state = 2;  
                break;

            // A
            case 2:
                if (input[i] == '0')
                    state = 1;  
                else
                    state = 3;  
                break;

            // B
            case 3:
                if (input[i] == '0')
                    state = 1;   
                else
                    state = 0;   
                break;
        }
    }

    if (state == 3)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}