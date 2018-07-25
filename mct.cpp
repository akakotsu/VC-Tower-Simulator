#include<iostream>
#include<random>
#include<algorithm>

using namespace std;

double random(int min, int max) //Divine Loli Goddess, decides your fate in this game
{
 random_device rd;
 mt19937 gn(rd());
 uniform_real_distribution<double> dis(min, max);
 return dis(gn);
}


int main()
{
 int n = 10000; //number of trials
 vector<unsigned long int> Floors(n,0);
 int Crystals = 10;
 double RuneBossAppearChance = 0.35;
 int num1,num2,num3;
 for (int i = 0; i < n; i++)
 {
  int Runes = 0;
  int Count = 5 * Crystals; //total bp
  int RuneTime = 0; //when rune time activates, this value becomes 15 and will decrease for every bp used
  while (Count >= 0)
  {
   Count -= 1;
   if (RuneTime > 0) { num1 = 10; RuneTime -= 1; }
   else num1 = 1;
   Floors[i] += 20 * (19*num1 + floor(random(0, 1+2*num1)));
   //cout << floors[i] << endl;
   if (RuneBossAppearChance > random(0, 1)&&0<Count)
   {
    Count -= 1;
    if (0.5 < random(0, 1))
    {
     if (RuneTime > 0) { num2 = 16; RuneTime -= -1; }
     else { num2 = 3; Runes += floor(random(1, 3)); }
     Floors[i] += 20 * (19*num2 + floor(random(0, 1+2*num2)));
    }
    else
    {
     if (RuneTime > 0) { num3 = 16; RuneTime -= -1; }
     else { num3 = 3; Runes += 2; }
     Floors[i] += 20 *(23*num3+ floor(random(0, 1+2*num3)));
    }
    if (Runes > 4) { RuneTime = 15; Runes = 0; }
   }
   
  }
 }
 unsigned long int TF = 0; //total floors
 for (auto &i : Floors){ 
 TF += i;
     //cout << TF << endl;
 }
 sort(Floors.begin(),Floors.end());
 cout << "Min: " << endl;
 for(int i=0;i<500;i++) cout << Floors[i] <<endl;
 cout << "Max: " << Floors[n-1] << endl;
 cout << "Average Total Floors: " << TF/double(n) << endl;
 cout << "Average Floors/Crystal: "<< TF / double(Crystals*n) << endl; //average floors per 5 bp used
 return 0;
}
