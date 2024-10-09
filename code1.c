#include <stdio.h>
#include <stdlib.h>
#include <string.h>




int main() {
    // initialize file data and sales list
    float sales[12];
    FILE *file = fopen("input.txt", "r");

    // defining array of months to be used in formatting outputs
    const char *months[] = {
    "January", "February", "March", "April", "May", "June", 
    "July", "August", "September", "October", "November", "December"
    };
    
    // handle case of file not found
    if (file == NULL) {
        printf("Error: Unable to open the file.\n");
        return 1;
    }

    // Read sales data from file
    for (int i = 0; i < 12; i++) {
        fscanf(file, "%f", &sales[i]);
    }
    fclose(file);

    // Generate the reports

    // monthly sales Report
    printf("Monthly Sales Report for 2024\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\t$%.2f\n", months[i], sales[i]);
    }
    printf("\n");

    // sales summary report
    // initialize min and max as well as the total to find the average later
    float min = sales[0];
    float max = sales[0];
    float total = 0;
    int min_month = 0;
    int max_month = 0;

    // find the minimum and maximum and add all months to the total
    for (int i = 0; i < 12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            min_month = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            max_month = i;
        }
        total += sales[i];
    }
    // find average
    float average = total / 12;

    // print out sales summary report
    printf("Sales Summary Report:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[min_month]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[max_month]);
    printf("Average sales: $%.2f\n\n", average);

    // six month moving average report
    // for each section of six months, add those months together and take the average. 
    printf("Six-Month Moving Average Report:\n");
    for (int i = 0; i <= 6; i++) {
        float sum = 0;
        for (int j = i; j < i + 6; j++) {
            sum += sales[j];
        }
        printf("%s-%s: $%.2f\n", months[i], months[i + 5], sum / 6);
    }
    printf("\n");

    // sales report highest to lowest
    // Create a copy of the sales and months arrays for sorting
    float sorted_sales[12];
    int sorted_month_indices[12];
    
    for (int i = 0; i < 12; i++) {
        sorted_sales[i] = sales[i];
        sorted_month_indices[i] = i;
    }

    // Sort sales using a simple selection sort
    for (int i = 0; i < 11; i++) {
        for (int j = i + 1; j < 12; j++) {
            if (sorted_sales[i] < sorted_sales[j]) {
                // Swap sales
                float temp_sales = sorted_sales[i];
                sorted_sales[i] = sorted_sales[j];
                sorted_sales[j] = temp_sales;

                // Swap month indices to maintain order
                int temp_index = sorted_month_indices[i];
                sorted_month_indices[i] = sorted_month_indices[j];
                sorted_month_indices[j] = temp_index;
            }
        }
    }

    // Print the sorted sales report
    printf("Sales Report (Highest to Lowest):\n");
    printf("Month\t\tSales\n");
    for (int i = 0; i < 12; i++) {
        printf("%s\t$%.2f\n", months[sorted_month_indices[i]], sorted_sales[i]);
    }

    return 0;
}
