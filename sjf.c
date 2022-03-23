/*
i , j = looping variable
n = number of process
t= temp variable
p[max] = for sorting the process
bt[max]=burst time
wt[max]= waiting time
tat[max]= turn around time
awt = average waiting time
atat = average waiting time
*/
#include <stdio.h>
#include <conio.h>
#define max 30
int main()
{
    int i, j, n, t, p[max], bt[max], wt[max], tat[max];
    float awt = 0, atat = 0;
    printf("Enter the number of process");
    scanf("%d", &n);
    printf("Enter the process number");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &p[i]);
    }
    printf("Enter the burst time of the process");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }
    // Applying bubble sort to sort the process according to the CPU burst time
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n - i - 1; j++)
        {
            if (bt[j] > bt[j + 1])
            {
                t = bt[j]; // sorting according to the burst time
                bt[j] = bt[j + 1];
                bt[j + 1] = t;

                t = p[j]; // sorting the position of the process accoring to the burst time
                p[j] = p[j + 1];
                p[j + 1] = t;
            }
        }
    }
    printf("\nProcess\t Burst time\t Waiting time\t Turnaround time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = 0; j < i; j++)
        {
            wt[i] = wt[i] + bt[j];
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("\n%d\t%d\t\t%d\t\t%d\n", p[i], bt[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("\n");
    printf("Average waiting time%f\n", awt);
    printf("Average turnaround time%f", atat);

    return 0;
}
