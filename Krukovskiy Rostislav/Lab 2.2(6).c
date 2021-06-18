//task 2.2 Var 6

#ifndef CALCULATION_H
#define CALCULATION_H
#include <math.h>
int Calculation(double arg, double inaccuracy)
{
  double left_value = sin(arg);
  double right_value = arg;
  int iteration = 1;
  double tmp = right_value;
  for (int i = 1; fabs(right_value - left_value) > inaccuracy; i += 2, ++iteration)
  {
    tmp *= ((arg * arg) / ((i + 1) * (i + 2)));
    right_value = right_value + pow(-1, (double)iteration) * tmp;
  }
  return iteration;
}
#endif
---------------------------
#include <stdio.h>
#include <math.h>
#include "calculation.h"
int main()
{
  double arg;
  double inaccuracy;
  printf("enter argument and inaccuracy\n");
  if(!scanf("%lf %lf\n", &arg, &inaccuracy)){
    return 1;
  }
  printf("%d", Calculation(arg, inaccuracy));

  return 0;
}