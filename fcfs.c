/*
 i , j = looping variable
 n = number of process
 bt[max] = burst time
 wt[max] =waiting time
 tat[max]= turnaround time
 awt = average waiting time
 atat = average turn around time
*/
#include <stdio.h>
#include <conio.h>
#define max 30

int main()
{
    int i, j, n, bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;

    printf("Enter the number of process");
    scanf("%d", &n);
    printf("Enter the burst time of the process");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    printf("\nProcess\t Burst time\t waiting time\t Turnaround time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;//i=0
        tat[i] = 0;//i=0
        for (j = 0; j < i; j++) //i=1//j=0 this loop one step back then upper loop 
        {
            wt[i] = wt[i] + bt[j]; // actual waiting time = previous process waiting time + its actual burst time
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];    // sum of observation
        atat = atat + tat[i]; // sum of observation
        printf("\n%d\t%d\t\t%d\t\t%d\n", i + 1, bt[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("\n");
    printf("Average waiting time%f\n", awt);
    printf("Average turnaround time%f", atat);
    return 0;
}
