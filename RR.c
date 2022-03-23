/* n= number of process
i =  for looping
qt = quantum time
count = 0 , this count will increment only if one process completely gets executed
temp = temperory variable
sq =second temporary variable
bt[10] = burst time array
wt[10] = waiting time array
tat[10] = turnaround time array
rem_bt[10] = remaining burst time
awt = averag waiitng time
atat = average turnaround time
*/
#include <stdio.h>
#include <conio.h>

int main()
{
    int n, i, qt, count = 0, temp, sq = 0,
                  bt[10], wt[10], tat[10], rem_bt[10];

    float awt = 0, atat = 0;

    printf("Enter the number of process");
    scanf("%d", &n);
    printf("Enter burst time of the process");
    for (i = 0; i < n; i++) // this is becoz to store burst time of different process
    {
        scanf("%d", &bt[i]); // storing burst time
        rem_bt[i] = bt[i];   // this because at very begining no process take resource
    }

    printf("Enter quantum time");
    scanf("%d", &qt);

    while (1)
    {
        for (i = 0, count = 0; i < n; i++)
        {
            temp = qt;
            if (rem_bt[i] == 0)
            {
                count++; // here remaining time is 0 so the process gets complete .. that why we increment count
                continue;
            }
            if (rem_bt[i] > qt) // this means the need some more time for its execution
            {
                rem_bt[i] = rem_bt[i] - qt; // here we simply update the burst time
            }
            else

                if (rem_bt[i] >= 0) // here process will come if its reamaining time is less than quantum time 
            {
                temp = rem_bt[i]; //here we make quantum time qual to remaining time and after execution it remaining become 0 and count will increment
                rem_bt[i] = 0;
            }
            sq = sq + temp; // temp = completion time
            tat[i] = sq;
        }
        if (n == count)//this means all process gets terminated 
        break;
    }
    printf("\nProcess\tBurst Time\tTurnarround time\tWaiting time\n");
    for (i = 0; i < n; i++)
    {
        wt[i] = tat[i] - bt[i]; // calculating waiting time
        awt = awt + wt[i];
        atat = atat + tat[i];
        printf("\n%d\t%d\t\t%d\t\t\t%d", i + 1, bt[i], tat[i], wt[i]);
    }
    awt = awt / n;
    atat = atat / n;
    printf("\n");
    printf("Average waiting time=%f\n", awt);
    printf("Average turnaround time=%f", atat);

    return 0;
}