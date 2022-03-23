/* c program to implement prioirity based sceduling algorithm without any arrival time */
/*
i , j = for looping
n= number of processes
t = temp variable for swaping
bt[max]= burst time
wt[max] = waiting time
pr[max]= priority of the processes
tat[max] = turnaround time
pos = position of the processes
awt = average waiting time
atat = average turnaround time
*/
#include <stdio.h>
#include <conio.h>
#define max 30 // declaration of global variable whose value is fixed throughout the program
int main()
{
    int i, j, n, t, bt[max], wt[max], pr[max], tat[max], pos;
    float awt = 0, atat = 0;

    printf("Enter the number of processes");
    scanf("%d", &n);

    printf("Enter the burst time of the processes ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &bt[i]);
    }

    printf("Enter the priority of the processes ");
    for (i = 0; i < n; i++)
    {
        scanf("%d", &pr[i]);
    }
    printf("Highest the priority value highest the priority");
    for (i = 0; i < n; i++)
    {
        pos = i;
        for (j = i+1; j < n; j++) // here we simply change the psition of the process according to the prioirity
        {
            if (pr[j] < pr[pos])
            {
                pos = j;
            }
        }
        t = pr[i]; // sorting the position accoring to the priority
        pr[i] = pr[pos];
        pr[pos] = t;

        t = bt[i]; // sorting the burst time according to position
        bt[i] = bt[pos];
        bt[pos] = t;
    }
    wt[0] = 0;
    printf("\nProcess\tBurst Time\tPriority\tWaiting time\tTurnaround time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = 0;
        tat[i] = 0;
        for (j = i+1; j < n; j++)
        {
            wt[i] = wt[i] + bt[j]; // actual waiting time = previous process waiting time + it actual burst time
        }
        tat[i] = wt[i] + bt[i];
        awt = awt + wt[i];    // sum of observation
        atat = atat + tat[i]; // sum of observation
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d\n", i + 1, bt[i], pr[i], wt[i], tat[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("\n");
    printf("Average waiting time%f\n", awt);
    printf("Average turnaround time%f", atat);

    return 0;
}