#include <iostream.h>
#include <conio.h>
class greatest
{
  float a, b;

public:
  void getdata();
  void comparing();
};
inline void greatest ::getdata()
{
  cout << "Enter two numbers:";
  cin >> a >> b;
}
void greatest ::comparing()
{
  if (a > b)
    cout << "Greatest=" << a;
  else if (a < b)
    cout << "Greatest=" << b;
  else
    cout << "Both are equal";
}
int main()
{
  clrscr();
  greatest g;
  g.getdata();
  g.comparing();
  getch();
  return 0;
}