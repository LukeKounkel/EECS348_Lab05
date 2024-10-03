#include <stdio.h>

float celsius_to_fahrenheit(float celsius){
    // Converts Celsius to Fahrenheit using the formula: F = (9/5)C + 32
    return (9.0/5.0)*celsius + 32;
}

float fahrenheit_to_celsius(float fahrenheit){
    // Converts Fahrenheit to Celsius using the formula: C = (5/9)(F - 32)
    return (fahrenheit - 32)*(5.0/9.0);
}
    
float celsius_to_kelvin(float celsius){
    // Converts Celsius to Kelvin using the formula: K = C + 273.15
    return celsius + 273.15;
}
    
float kelvin_to_celsius(float kelvin){
    // Converts Kelvin to Celsius using the formula: C = K - 273.15
    return kelvin - 273.15;
}
    
float fahrenheit_to_kelvin(float fahrenheit){
    // Converts Fahrenheit to Kelvin using the formula: C = (5/9)(F - 32) and C + 273.15
    return celsius_to_kelvin((fahrenheit - 32)*(5.0/9.0));
}

float kelvin_to_fahrenheit(float kelvin){
    // Converts Kelvin to Fahrenheit using the formula: C = K - 273.15 and F = (9/5)C + 32
    return celsius_to_fahrenheit(kelvin - 273.15);
}

void categorize_temperature(float celsius){
    /* check if the celsius temp falls within any of the given ranges in order to give a weather advisory
    Freezing is any negative temp
    Cold is any temp above 0 but below 10
    Comfortable is any temp above 10 but below 25
    Hot is any temp above 25 but below 35
    Extreme Heat is any temp above 35
    */
    if (celsius < 0){
        printf("\nTemperature category: Freezing\n");
        printf("Weather advisory:  Wear winter protection.");
    } else if (celsius < 10) {
        printf("\nTemperature category: Cold\n");
        printf("Weather advisory:  Wear a jacket.");
    } else if (celsius < 25) {
        printf("\nTemperature category: Comfortable\n");
        printf("Weather advisory:  Go outside and enjoy the weather!");
    } else if (celsius < 35) {
        printf("\nTemperature category: Hot\n");
        printf("Weather advisory:  Stay in the shade or go to the pool.");
    } else {
        printf("\nTemperature category: Extreme Heat\n");
        printf("Weather advisory:  Stay inside today.");
    }
}

int main(){
    // initialize neccesary variables
    float temp, convertedTemp, celsiusTemp;
    int inScale, tarScale;

    // get temp, and if the input is not valid, continue prompting user until the input is valid.
    printf("Enter the temperature: ");
    while (scanf("%f", &temp) != 1){
        // clear input cache
        while (getchar() != '\n'); 

        printf("Invalid input, please try again: ");
    }

    // get the input temp scale, and if the input is not valid, continue prompting user until the input is valid.
    printf("Choose the current scale (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    while (scanf("%d", &inScale) != 1){
        // clear input cache
        while (getchar() != '\n'); 
        
        printf("Invalid input, please try again: ");
    } 

    // checking edge case
    while (temp < 0 && inScale == 3) {
        printf("Kelvin values cannot be less than 0, please enter new temp: ");
        scanf("%f", &temp);
    }

    // get the conversion temp scale, and if the input is not valid, continue prompting user until the input is valid.
    printf("Convert to (1) Celsius, (2) Fahrenheit, (3) Kelvin: ");
    while (scanf("%d", &tarScale) != 1){
        // clear input cache
        while (getchar() != '\n'); 
        
        printf("Invalid input, please try again: ");
    }

    // conversion cannot between the same scale, continue prompting user until conversion scale is different from input scale
    while (inScale == tarScale){
        printf("Conversion cannot be done between the same scale, please try again: ");
        while (scanf("%d", &tarScale) != 1){
            // clear input cache
            while (getchar() != '\n'); 
        
            printf("Invalid input, please try again: ");
    } 
    }

    printf("\n");

    // using a nested switch case structre, go through each possible conversion and call the needed functions.
    switch (inScale) {
        // case 1 is for celsius conversions
        case 1:
            // set celsius temp for later weather advisory
            celsiusTemp = temp;
            switch (tarScale) {
                // case 1-2 is celsius to fahrenheit
                case 2:
                    printf("%.2fF", celsius_to_fahrenheit(temp));
                    break;
                // case 1-3 is celsius to kelvin
                case 3:
                    printf("%.2fK", celsius_to_kelvin(temp));
                    break;
                default:
                    printf("Invalid input scale.\n");
                    return 1; // Exit with an error
            }
            break;
        // case 2 is for fahrenheit conversions
        case 2:
            // set celsius temp for weather advisory later 
            celsiusTemp = fahrenheit_to_celsius(temp);
            switch (tarScale) {
                // case 2-1 is for fahrenheit to celsius
                case 1:
                    printf("%.2fC", fahrenheit_to_celsius(temp));
                    break;
                // case 2-3 is for fahrenheit to kelvin
                case 3:
                    printf("%.2fK", fahrenheit_to_kelvin(temp));
                    break;
                default:
                    printf("Invalid input scale.\n");
                    return 1; // Exit with an error
            }

            break;
        // case 3 is for all kelvin conversions
        case 3:
            // set celsius temp for weather advisory later
            celsiusTemp = kelvin_to_celsius(temp);
            switch (tarScale) {
                // case 3-1 is for kelvin to celsius
                case 1:
                    printf("%.2fC", kelvin_to_celsius(temp));
                    break;
                // case 3-2 is for kelvin to fahrenheit
                case 2:
                    printf("%.2fF", kelvin_to_fahrenheit(temp));
                    break;
                default:
                    printf("Invalid input scale.\n");
                    return 1; // Exit with an error
            }

            break;
        default:
            printf("Invalid input scale.\n");
            return 1; // Exit with an error
    }
    
    categorize_temperature(celsiusTemp);
}
