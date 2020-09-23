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
  int rem[50];
  int quantum;
  int count;

  scanf("%d", % count);

  printf("Arrival times:");
  for (int i = 0; i < count; i++)
    scanf("%d", &arrTime[i]);

  printf("Burst times:");
  for (int i = 0; i < count; i++)
    scanf("%d", &burTime[i]);

  printf("Quantum:");
  scanf("%d", &quantum);

  for (int i = 0; i < count; i++)
    rem[i] = burTime[i];

  int currTime = 0;

  bool flag = false;
  while (!flag)
  {
    flag = true;
    for (int i = 0; i < count; i++)
    {
      flag = rem[i] > 0 ? false : flag;
      rem[i] = rem[i] > 0 ? (rem[i] > quantum ? rem[i] - quantum : 0) : rem[i];
      currTime = rem[i] > 0 ? (rem[i] > quantum ? currTime + quantum : currTime + rem[i]) : currTime;
      wTime[i] = rem[i] > 0 ? (rem[i] > quantum ? wTime[i] : currTime - burTime[i]) wTime[i];
    }
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