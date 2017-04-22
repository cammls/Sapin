#include <stdlib.h>
#include <stdio.h>

int    my_putchar(char c)
{
  write (1, &c, 1);
}

void	my_true_loop_spaces(unsigned int nbrspaces)
{
  int	counter;

  counter = 0;
  while (nbrspaces > counter)
    {
      my_putchar(' ');
      counter++;
    }
}

void my_true_loop_stars(unsigned int nbrstars)
{
  int counter;
  counter = 0;
  while (nbrstars > counter)
    {
      my_putchar('*');
      counter++;
    }
 my_putchar('\n');
}

int	branchette(int nbrspaces, int nbrstars)
{

  my_true_loop_spaces(nbrspaces);
  my_true_loop_stars(nbrstars);

  return(0);

}

int	firstlineofstars(int size)
{
   int countersize;
  int add;
  int nbrstars;
  int counterstars;
  
  add = 4;
  counterstars = 1;
  countersize = 1;
 
  while (countersize < size)
    {

     if(countersize%2 == 0)
    {
      add += 2;
    }
    countersize++;
     counterstars = counterstars + add;
    }
   
  return(counterstars);
}

int	lastline(int firstline, int sizesapin)
{
  int counter;

  counter = 0;
  while (counter <= (sizesapin + 3))
    {
      firstline += 2;
      counter++;
    }
  return (firstline);
}

int	branche(int actualsize, int sizesapin)
{
   int counter;
  int nbbranchette;
  int spaces;
  int stars;
  int x;
  int maxstars;
  
  counter = 1;
  nbbranchette = actualsize +3;
  stars = firstlineofstars(actualsize); 
  maxstars = lastline(firstlineofstars(sizesapin), sizesapin); 
  
  while(counter <= nbbranchette)
    {
      spaces = ((maxstars - stars)/2) -2;
      branchette(spaces, stars);
      counter++;
      stars = stars + 2;
    }

}

int	brancherecursive(int sizesapin, int counter)
{

  if(counter <= sizesapin)
 {
   branche(counter, sizesapin);
   counter++;
   brancherecursive(sizesapin, counter);
 }
  
}

int	main(int argc, char **argv)
{
  int nbrtyped;
  int countrecursive;

  countrecursive = 1;
  nbrtyped = atoi(argv[1]);
  
  brancherecursive(nbrtyped, countrecursive);
  
  return(0);
}
