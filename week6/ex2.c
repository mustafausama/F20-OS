#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <algorithm>

void swap(int *xp, int *yp)
{
  *xp = *xp ^ *yp;
  *yp = *xp ^ *yp;
  *xp = *xp ^ *yp;
}

int main(int argc, char const *argv[])
{

  int arrTime[50];
  int burTime[50];
  int wTime[50];
  int taTime[50];
  int PID[50];
  int compTime[50];
  int count;

  scanf("%d", &count);

  printf("Arrival times:");
  for (int i = 0; i < count; i++)
    scanf("%d", &arrTime[i]);

  printf("Burst times:");
  for (int i = 0; i < count; i++)
    scanf("%d", &burTime[i]);

  for (int i = 0; i < count; i++)
    for (int j = 0; j < count - i - 1; j++)
      if (arrTime[j] > arrTime[j + 1])
      {
        swap(&PID[j + 1], &PID[j]);
        swap(&arrTime[j + 1], &arrTime[j]);
        swap(&burTime[j + 1], &burTime[j]);
      }

  int currTime;
  int currI;
  int minBurst;

  for (int i = 1; i < count; i++)
  {
    currTime = compTime[i - 1];
    currI = i;
    minBurst = burTime[i];

    for (int j = i + 1; j < count; j++)
    {
      minBurst = minBurst > burTime[j] ? burTime[j] : minBurst;
      currI = minBurst > burTime[j] ? j : currI;
    }

    swap(&PID[i], &PID[currI]);
    swap(&arrTime[i], &arrTime[currI]);
    swap(&burTime[i], &burTime[currI]);

    compTime[i] = currTime + burTime[i];
  }

  int waiTime = 0, tuarTime = 0;

  printf("Completion Time\tTurn Around Time\tWaiting Time\n");
  for (int i = 0; i < count; i++)
  {
    waiTime += wTime[i];
    tuarTime += taTime[i];

    printf("%d\t%d\t%d\n", compTime[i], taTime[i], wTime[i]);
  }

  printf("Average Waiting Time: %d\nAverage Turn Around Time: %d\n", waiTime / count, tuarTime / count);

  return 0;
}