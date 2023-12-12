#include <stdio.h>
#include <conio.h> // Note: The conio.h header is not standard and may not be available in all C compilers. It's commonly used for console input/output functions.

void main() {
    // Initialize variables
    int i, NOP, sum = 0, count = 0, y, quant, wt = 0, tat = 0, at[10], bt[10], temp[10];
    float avg_wt, avg_tat;

    // Input: Total number of processes
    printf("Total number of processes in the system: ");
    scanf("%d", &NOP);
    y = NOP; // Assign the number of processes to variable y

    // Input: Arrival time and Burst time for each process
    for (i = 0; i < NOP; i++) {
        printf("\nEnter the Arrival and Burst time of Process[%d]\n", i + 1);
        printf("Arrival time is: ");
        scanf("%d", &at[i]);
        printf("Burst time is: ");
        scanf("%d", &bt[i]);
        temp[i] = bt[i]; // Store the burst time in the temp array
    }

    // Input: Time Quantum
    printf("Enter the Time Quantum for the process: ");
    scanf("%d", &quant);

    // Display column headers
    printf("\nProcess No\tBurst Time\tTAT\tWaiting Time");

    // Round Robin scheduling algorithm
    for (sum = 0, i = 0; y != 0;) {
        if (temp[i] <= quant && temp[i] > 0) {
            sum = sum + temp[i];
            temp[i] = 0;
            count = 1;
        } else if (temp[i] > 0) {
            temp[i] = temp[i] - quant;
            sum = sum + quant;
        }

        if (temp[i] == 0 && count == 1) {
            y--;
            printf("\nProcess No[%d]\t%d\t\t%d\t\t%d", i + 1, bt[i], sum - at[i], sum - at[i] - bt[i]);
            wt = wt + sum - at[i] - bt[i];
            tat = tat + sum - at[i];
            count = 0;
        }

        if (i == NOP - 1) {
            i = 0;
        } else if (at[i + 1] <= sum) {
            i++;
        } else {
            i = 0;
        }
    }

    // Calculate average waiting time and average turnaround time
    avg_wt = (float)wt / NOP;
    avg_tat = (float)tat / NOP;

    // Output average values
    printf("\nAverage Turnaround Time: %f", avg_tat);
    printf("\nAverage Waiting Time: %f", avg_wt);

    getch(); // Pauses the program until a key is pressed (using conio.h)
}
