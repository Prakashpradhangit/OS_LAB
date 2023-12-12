
// #include <stdio.h>

// int main() {
//     int pid[15];
//     int bt[15];
//     int n;

//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     printf("Enter process id of all the processes: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &pid[i]);
//     }

//     printf("Enter burst time of all the processes: ");
//     for (int i = 0; i < n; i++) {
//         scanf("%d", &bt[i]);
//     }

//     int i, wt[15];
//     wt[0] = 0;

//     // for calculating waiting time of each process
//     for (i = 1; i < n; i++) {
//         wt[i] = bt[i - 1] + wt[i - 1];
//     }

//     printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
//     float twt = 0.0;
//     float tat = 0.0;
    // for (int i = 0; i < n; i++) {
    //     printf("%d\t\t%d\t\t%d\t\t%d\n", pid[i], bt[i], wt[i], bt[i] + wt[i]);

    //     // for calculating total waiting time
    //     twt += wt[i];

    //     // for calculating total turnaround time
    //     tat += (wt[i] + bt[i]);
    // }
//     float att, awt;

//     // for calculating average waiting time
//     awt = twt / n;

//     // for calculating average turnaround time
//     att = tat / n;
//     printf("Avg. waiting time= %f\n", awt);
//     printf("Avg. turnaround time= %f\n", att);

//     return 0;
// }









// *lab experiment 1(i)
//  * FCFS Scheduling Program in C
//  */
//  
// #include <stdio.h>
// int main()
// {
//     int pid[15];
//     int bt[15];
//     int n;
//     printf("Enter the number of processes: ");
//     scanf("%d", &n);

//     printf("Enter process id of all the processes: ");
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&pid[i]);
//     }

//     printf("Enter burst time of all the processes: ");
//     for(int i=0;i<n;i++)
//     {
//         scanf("%d",&bt[i]);
//     }

//     int i, wt[15];
//     wt[0]=0;

//     //for calculating waiting time of each process
//     for(i=1; i<n; i++)
//     {
//         wt[i]= bt[i-1]+ wt[i-1];
//     }

//     printf("Process ID     Burst Time     Waiting Time     TurnAround Time\n");
//     float twt=0.0;
//     float tat= 0.0;
//     for(int i=0; i<n; i++)
//     {
//         printf("%d\t\t", pid[i]);
//         printf("%d\t\t", bt[i]);
//         printf("%d\t\t", wt[i]);

//         //calculating and printing turnaround time of each process
//         printf("%d\t\t", bt[i]+wt[i]);
//         printf("\n");

//         //for calculating total waiting time
//         twt += wt[i];

//         //for calculating total turnaround time
//         tat += (wt[i]+bt[i]);
//     }
//     float att,awt;

//     //for calculating average waiting time
//     awt = twt/n;

//     //for calculating average turnaround time
//     att = tat/n;
//     printf("Avg. waiting time= %f\n",awt);
//     printf("Avg. turnaround time= %f",att);
// }








#include<stdio.h>

int main(){
    int pid[15];
    int bt[15];
    int n;


    printf("enter the number of processor: ");
    scanf("%d", &n);

    printf("enter process id for all the process: \n");
    for(int i=0; i<0; i++){
        scanf("%d", &pid[i]);
    }

    printf("enter burst time for all the process: \n");
    for(int i=0; i<n; i++){
        scanf("%d", &bt[i]);
    }

    int i,wt[15];
    wt[0] = 0;

    for(i = 1; i<n; i++){
        wt[i] = bt[i-1] + wt[i-1];
    }

    printf("process ID    Burst time   Waiting Time   Turnaround time \n");

    float twt = 0.0;
    float tat = 0.0;
    for (int i = 0; i<n; i++){
        printf("%d\t\t%d\t\t%d\t\t%d\t", pid[i], bt[i], wt[i], bt[i]+wt[i]);
    }

    float att ,awt;

    awt = twt /n;


    att = tat/n;
    printf("Avg. waiting time = %f\n", awt);
    printf("Avg. turnaround time= %f\n", att);  // the time required to complete a process


    return 0;



}





















