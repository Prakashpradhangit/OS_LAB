#include <stdio.h>

// Function to swap two variables
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main() {
    int n;
    printf("Enter Number of Processes: ");
    scanf("%d", &n);

    // Arrays for burst time (b), priority (p), and process index (index)
    int b[n], p[n], index[n];

    for (int i = 0; i < n; i++) {
        printf("Enter Burst Time and Priority Value for Process %d: ", i + 1);
        scanf("%d %d", &b[i], &p[i]);
        index[i] = i + 1;
    }

    // Sort processes by priority (highest priority first)
    for (int i = 0; i < n; i++) {
        int max_priority = p[i];
        int max_priority_index = i;

        // Finding the process with the highest priority
        for (int j = i; j < n; j++) {
            if (p[j] > max_priority) {
                max_priority = p[j];
                max_priority_index = j;
            }
        }

        // Swap processes based on priority
        swap(&p[i], &p[max_priority_index]);
        swap(&b[i], &b[max_priority_index]);
        swap(&index[i], &index[max_priority_index]);
    }

    int t = 0; // Stores the starting time of each process

    printf("\nOrder of Process Execution:\n");
    for (int i = 0; i < n; i++) {
        printf("P%d is executed from %d to %d\n", index[i], t, t + b[i]);
        t += b[i];
    }

    printf("\nProcess ID   Burst Time   Wait Time   Turnaround Time\n");
    int wait_time = 0;
    for (int i = 0; i < n; i++) {
        printf("P%d           %d            %d            %d\n", index[i], b[i], wait_time, wait_time + b[i]);
        wait_time += b[i];
    }

    return 0;
}
