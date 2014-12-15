// A simple program that computes the square root of a number
#include <iostream>
#include <string>
//#include 
int cal (int argc, char *argv[])
{
  if (argc < 2)
    {
    fprintf(stdout,"Usage: %s number\n",argv[0]);
    return 1;
    }
  double inputValue;
  std::cin >> inputValue;
  /*atof(argv[1])*/
  double outputValue = sqrt(inputValue);
  fprintf(stdout,"The square root of %g is %g\n",
          inputValue, outputValue);
  return 0;
}

int main() {
	char temp = 'a';
	cal(4, *temp);
	return 0;
}