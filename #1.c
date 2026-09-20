#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;

    /*
        States:
        0 = AC (Start State)
        1 = B
        2 = D
        3 = E (Final State)
    */

    printf("Enter a binary string (0s and 1s): ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {

        if (input[i] != '0' && input[i] != '1') {
            printf("Invalid input! Only 0 and 1 are allowed.\n");
            return 1;
        }

        switch (state) {

            // AC
            case 0:
                if (input[i] == '0')
                    state = 1;       
                else
                    state = 0;       
                break;

            // B
            case 1:
                if (input[i] == '0')
                    state = 1;       
                else
                    state = 2;       
                break;

            // D
            case 2:
                if (input[i] == '0')
                    state = 1;       
                else
                    state = 3;       
                break;

            // E
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