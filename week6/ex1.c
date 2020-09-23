#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <algorithm>

int main(int argc, char const *argv[])
{
  int arrTime[50];
  int burTime[50];
  int wTime[50];
  int taTime[50];
  int sTime[50];
  int count;

  scanf("%d", &count);

  printf("Arrival times:");
  for (int i = 0; i < count; i++)
    scanf("%d", &arrTime[i]);

  printf("Burst times:");
  for (int i = 0; i < count; i++)
    scanf("%d", &burTime[i]);

  for (int i = 1; i < count; i++)
  {
    sTime[i] = sTime[i - 1] + burTime[i - 1];
    wTime[i] = sTime[i] - arrTime[i] > 0 ? sTime[i] - arrTime[i] : 0;
  }

  for (int i = 0; i < count; i++)
    taTime[i] = burTime[i] + wTime[i];

  int waiTime = 0, tuarTime = 0;

  printf("Completion Time\tTurn Around Time\tWaiting Time\n");
  for (int i = 0; i < count; i++)
  {
    waiTime += wTime[i];
    tuarTime += taTime[i];
    printf("%d\t%d\t%d\n", arrTime[i] + taTime[i], taTime[i], wTime[i]);
  }

  printf("Average Waiting Time: %d\nAverage Turn Around Time: %d\n", waiTime / count, tuarTime / count);

  return 0;
}