#include <stdio.h>
#include <omp.h>
int main() {
int i=0;

#pragma omp parallel
{
 int i = omp_get_thread_num();
printf("Hello from thread %d\n", i);
}
}