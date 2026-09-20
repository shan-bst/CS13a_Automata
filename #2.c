#include <stdio.h>
#include <string.h>

int main() {
    char input[100];
    int state = 0;   // 0 = AB, 1 = CDE, 2 = F

    printf("Enter a binary string: ");
    scanf("%s", input);

    for (int i = 0; i < strlen(input); i++) {

        if (state == 0) {          // AB
            if (input[i] == '0')
                state = 0;
            else if (input[i] == '1')
                state = 1;
            else {
                printf("Invalid input!\n");
                return 0;
            }
        }

        else if (state == 1) {     // CDE
            if (input[i] == '0')
                state = 1;
            else if (input[i] == '1')
                state = 2;
            else {
                printf("Invalid input!\n");
                return 0;
            }
        }

        else {                     // F
            state = 2;
        }
    }

    if (state == 1)
        printf("Accepted\n");
    else
        printf("Rejected\n");

    return 0;
}