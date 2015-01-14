#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
void sleep (unsigned int mseconds)
{
  clock_t goal = mseconds + clock();
  while (goal > clock());
}
std::string random_string (size_t length)
{
  auto randchar = []() -> char
  {
    const char charset[] = 
      "0123456789"
      "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
      " abcdefghijklmnopqrstuvwxyz";
      const size_t max_index = (sizeof(charset) - 1);
      return charset [ rand() % max_index ];
  };
  std::string str(length,0);
  std::generate_n( str.begin(), length, randchar );
  return str;
}
int main(int argc, char* argv[])
{
  std::string targ(argv[1]);
  size_t targlen = targ.length();
  std::string gend = random_string(targlen);
  for (int i=0; i < targlen; i++)
  {
    gend[i]='o';
  }
  std::string rand;
  while (gend != targ)
  {
    rand = random_string (targlen);
    for ( int i=0; i < targlen; i++)
    {
      if (rand[i] == targ[i])
      {
        gend[i] = rand[i];
        break; 
      }
    }
    for (int i=0; i < targlen; i++)
    {
      if (gend[i] != 'o' || gend[i] == ' ')
        {
          std::cout << gend[i];
        }
      else{
        std::cout << rand[i];
      }
    }
  sleep(20000);
  std::cout << "\r" << std::flush;
  }
  std::cout << gend << std::endl;
}
