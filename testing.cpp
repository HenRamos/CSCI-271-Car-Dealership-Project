#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;

/*
The following is a testing file that I used as a model for main.cpp.
Here, I test things or changes to see if they work or not.

The main.cpp program has more in depth comments.

*/
int main() {
  int total, dealersCut, userBrandChoice, userModelChoice, userExtraChoice, warranty;
  int extraOptions = 1000;
  bool isShopOpen = false, isUserShopping = true, isFord = false, isNissan = false, isToyota = false;
  int Nissan[6] = {42473, 93295, 57761, 20287, 33000, 38299};
  int Ford[6] = {37527, 11470, 36334, 36999, 21000, 28148};
  int Toyota[6] = {49289, 18145, 63224, 23356, 34629, 65029};

  cout << "Welcome to Henry's car dealership!\n";
  cout << "We offer three brands of cars, each with six models.\n";
  //Find alternative to sleep func
  cout << "These brands are Toyota, Nissan and Ford. Please select 1, 2 or 3 respectively: ";
  cin >> userBrandChoice;
  switch(userBrandChoice){
    case 1: cout << "You've selected Toyota! \nThese are the available models and their prices:\n"; isToyota = true; break;
    case 2: cout << "You've selected Nissan! \nThese are the available models and their prices:\n"; isNissan = true; break;
    case 3: cout << "You've selected Ford! \nThese are the available models and their prices:\n"; isFord = true; break;
    default: cout << "Selection not recognized! Please try again.";
  }
  if(isToyota){
    for(int model = 0; model <= 5; model++){
      cout << setw(2) << model << setw(20) << Toyota[model] << "\n";
    }
    cout << "Please select a model by number: \n";
    cin >> userModelChoice;
    total = total + Toyota[userModelChoice];
    cout << "Your current total is: " << total;
  }else if(isNissan){
    for(int model = 0; model <= 5; model++){
      cout << setw(2) << model << setw(20) << Nissan[model] << "\n";
  }
    cout << "Please select a model by number: \n";
    cin >> userModelChoice;
    total = total + Nissan[userModelChoice];
    cout << "Your current total is: " << total;

}else if(isFord){
  for(int model = 0; model <= 5; model++){
    cout << setw(2) << model << setw(20) << Ford[model] << "\n";
  }
  cout << "Please select a model by number: \n";
  cin >> userModelChoice;
  total = total + Ford[userModelChoice];
  cout << "Your current total is: ";
}
  cout << "\nWould you like the extra options or the warranty?\n"
  << "Type in 1 for extra options, 2 for warranty, 3 for both or 4 for neither";
  cin >> userExtraChoice;







}
