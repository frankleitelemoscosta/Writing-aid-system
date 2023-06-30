#include"Readtext.hpp"

using namespace std;

int main()
{
  
  double time_of_usage_CPU;
  float start = 0;
  float end = 0;

  srand(time(NULL));

	// collect the start time of use of the CPU
  start = clock();

    Read();

  // collect the time of use of the CPU
		end = clock();

		time_of_usage_CPU = ((double) (end - start)) / CLOCKS_PER_SEC; // Calcula o tempo de execução em segundos

		printf("Tempo de execução: %.8f segundos\n", time_of_usage_CPU);

  return 0;
}
