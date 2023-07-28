#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * infinite_while - infinite while loop
 * Return: 0
 */
int infinite_while(void)
{
  while (1)
    sleep(1);

  return (0);
}

/**
 * main - main
 * Return: 0
 */
int main(void)
{
  pid_t pids[5];
  int i;

  for (i = 0; i < 5; i++)
  {
    pids[i] = fork();
    if (pids[i] > 0)
    {
      printf("Zombie process created, PID: %d\n", pids[i]);
      sleep(1);
    }
    else
      exit(0);
  }

  infinite_while();
  return (0);
}

