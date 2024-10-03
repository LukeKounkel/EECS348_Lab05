#include <stdio.h>

int main(){
    // initializing initial variables, and letting user know how to end program
    int score = 2;
    int TD, FG, TDFG, TDtpt, Safety;
    printf("Enter 0 or 1 to STOP\n");

    // this program will repeat until the score is less than two
    while (score > 1) {
        // get the inputted score, while validating that the score is a positive integer
        printf("Enter the NFL score: ");
        if (scanf("%d", &score) != 1){
            // clear input cache
            while (getchar() != '\n'); 

            // reset score so that the loop can continue
            score = 2; 

            // tell user they put in bad input and skip the remainder of the loop
            printf("Invalid score entered, please try again\n");
            continue;

        } else if (score < 2) {
            // end the program if an input of less than 2 is entered
            printf("Ending program\n");
            break;
        } 

        // loop through each possible number of safeties (worth 2 points)
        for (int Safety = 0; Safety < (score / 2)+1; Safety++){

            // loop through each possible number of Field Goals that could be scored, accounting for points already scored
            for (int FG = 0; FG < ((score-(Safety*2)) / 3)+1; FG++){

                // loop through each possible number of Touchdowns without extra points that could be scored, accounting for all points already scored
                for (int TD = 0; TD < ((score-(Safety*2)-(FG*3)) / 6)+1; TD++){

                    // loop through each possible number of Touchdowns a Field goal that could be scored, accounting for all points already scored
                    for (int TDFG = 0; TDFG < ((score-(Safety*2)-(FG*3)-(TD*6)) / 7)+1; TDFG++){

                        // loop through each possible number of Touchdowns with two points that could be scored, accounting for all points already scored
                        for (int TDtpt = 0; TDtpt < ((score-(Safety*2)-(FG*3)-(TD*6)-(TDFG*7)) / 8)+1; TDtpt++){

                            // if the combintation of points does not add up to the score, then the combination of points is not valid.
                            if ((score-(Safety*2)-(FG*3)-(TD*6)-(TDFG*7)-(TDtpt*8)) == 0){

                                // print the possible scored combination of points
                                printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", TDtpt, TDFG, TD, FG, Safety);
                            }
                        }
                    }
                }
            }
        }
    }
}