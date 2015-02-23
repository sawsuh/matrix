#include <iostream>
#include <algorithm>
#include <time.h>
#include <cstring>
#include <stdexcept>
#include <cstdlib>
void sleep (unsigned int mseconds)
{
  clock_t goal = mseconds + clock();
  while (goal > clock());
}
void randgen (size_t length, char* arr, char *randchar)
{
  for (int i = 0; i != length; i++)
  {
    *(i + arr) = *(randchar + (rand() % 63));           //generate random character in that space
  }
}
int main(int argc, char* argv[])
{
  try{
    if (strlen(argv[1]) >= 8)
    {
      throw std::runtime_error("the program won't complete if the string is 8 characters or greater");
    }     //make it return error and exit if string was greater than 7 chars
  }       //this is because it stuffs up when that happens (i dont know why)
  catch (std::runtime_error err)
  {
    std::cout << err.what() << std::endl;
    exit(1);
  }
  char randchar[] = "0123456789qwertyuiopasdfghjklzxcvbnmQWERTYUIOPASDFGHJKLZXCVBNM ";
  char *targ = (char*)argv[1];
  char *ptr = &targ[0];
  size_t targlen = strlen(ptr);
  char gend[targlen];
  randgen(targlen, gend, randchar);
  char rand[targlen];
  while (strcmp(gend, targ))        //keeps looping until the string has been generated
  {
    randgen (targlen, rand, randchar);
    for ( int i=0; i != targlen; i++)
    {
      if (*(rand + i) == *(targ + i))
      {
        *(gend + i) = *(rand + i);              //locks the character if it is generated in the right spot
        break; 
      }
    }
    for (int i=0; i != targlen; i++)
    {
      if (*(gend + i) == *(targ + i))
        {
          std::cout << *(gend + i);                 //print the locked character if it exists
        }                                           // otherwise print the random character
      else{
        std::cout << *(rand + i);
      }
    }
  sleep(20000);
  std::cout << "\r" << std::flush;
  }
  std::cout << gend << std::endl;
}
