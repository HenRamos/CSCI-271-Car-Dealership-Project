#include <iostream>
#include <iomanip>
using namespace std;
/* There are some arithmetic problems and loop logic issues that I ran into with this project. Additionally, sometimes my arithmetic will come out different if I compile on my IDE as opposed to on repl.it so the results may vary.
*/
int main() {

/*Variable Declarations*/
int dealersCut, dealersProfit, userBrandChoice, userModelChoice, userExtraChoice, customers; // Vars with no value that we'll use later
int fordSold = 0, nissanSold = 0, toyotaSold = 0, total = 0;
int extraOptions = 1000, warranty = 0, extrasSold = 0, warrantySold = 0; // Variables with a value that can change

bool isShopOpen = true, isFord = false, isNissan = false, isToyota = false; // Booleans for conditional programming

/*These arrays are the prices of the car models to be used later in the code*/
int Nissan[6] = {42473, 93295, 57761, 20287, 33000, 38299};
int Ford[6] = {37527, 11470, 36334, 36999, 21000, 28148};
int Toyota[6] = {49289, 18145, 63224, 23356, 34629, 65029};

cout << "Welcome to Henry's car dealership!\n";
cout << "We offer three brands of cars, each with six models.\n";

/*Initiating shop loop*/
while(isShopOpen){
  cout << "These brands are Toyota, Nissan and Ford. Please select 1, 2 or 3 respectively: ";
  cin >> userBrandChoice; //Selecting a brand via an integer
  switch(userBrandChoice){ //This switch case outputs which brand you chose and sets a bool of coresponding brand
    case 1: cout << "You've selected Toyota! \nThese are the available models and their prices:\n"; isToyota = true; break;
    case 2: cout << "You've selected Nissan! \nThese are the available models and their prices:\n"; isNissan = true; break;
    case 3: cout << "You've selected Ford! \nThese are the available models and their prices:\n"; isFord = true; break;
    default: cout << "Selection not recognized! Please try again.";
  }

  /*These if statements determine which car menu we will reference and the user will choose a model*/
  if(isToyota){ //menu formatting below
    for(int model = 0; model <= 5; model++){
      cout << setw(2) << model << setw(20) << Toyota[model] << "\n";
    }
    cout << "Please select a model by number: \n";
    cin >> userModelChoice;
    total = total + Toyota[userModelChoice];
    cout << "Your current total is: " << total;
    toyotaSold = toyotaSold + 1; //For some reason when I use toyotaSold++ in this case, the output later on in the code is a huge number. I think this is because of the nature of the while loop
  }else if(isNissan){
    for(int model = 0; model <= 5; model++){
      cout << setw(2) << model << setw(20) << Nissan[model] << "\n";
  }
    cout << "Please select a model by number: \n";
    cin >> userModelChoice;
    total = total + Nissan[userModelChoice];
    cout << "Your current total is: " << total;
    nissanSold = nissanSold + 1;

}else if(isFord){
  for(int model = 0; model <= 5; model++){
    cout << setw(2) << model << setw(20) << Ford[model] << "\n";
  }
  cout << "Please select a model by number: \n";
  cin >> userModelChoice;
  total = total + Ford[userModelChoice];
  cout << "Your current total is: " << total;
  fordSold = fordSold + 1;
  }

  /*Next, the user will select if they want extras*/
  cout << "\nWould you like the extra options or the warranty?\n"
  << "Type in 1 for extra options, 2 for warranty, 3 for both or 4 for neither: ";
  cin >> userExtraChoice;
  if(userExtraChoice == 1){
    total = total + extraOptions;
    extrasSold++;
    cout << "Your new total is: " << total;
  }else if(userExtraChoice == 2){
    warranty = total * (float).5;
    cout << "Your warranty comes out to: \n";
    total = total + warranty;
    warrantySold++;
    cout << "Your new total is: " << total;
  }else if(userExtraChoice == 3){ //Another choice I have here: make a function that calculates warranty price before main()
    total = total + extraOptions;
    warranty = total * (float).5;
    total = total + warranty;
    extrasSold++;
    warrantySold++;
    cout << "Your new total is: " << total;
  }else if (userExtraChoice == 4){
    cout << "Your total is: " << total;
  }else{
    cout << "Unrecognized input!";
  }

  /*Finally, the user will see a recepit and the dealer will see their profit*/
  cout << "\nHere's your recepit: \n";
  cout << "Brand and Model: " << userBrandChoice << ", " << userModelChoice;
  if(isToyota){
    cout << "\nBase price: " << Toyota[userModelChoice];
  }else if(isNissan){
    cout << "\nBase price: " << Nissan[userModelChoice];
  }
  if(userExtraChoice == 1 || userExtraChoice == 3){
    cout << "\nThe cost of your extras: " << warranty + extraOptions;
  }else if(userExtraChoice == 2){
    cout << "\nThe cost of your warranty: " << warranty;
  }
  cout << "\nYour final total is: " << total;
  dealersProfit = total * .05;
  cout << "\nThe dealers profit is: " << dealersProfit;

  //This next line of code determines if the loop continues or not.

  cout << "\nAre there any more customers? Type 1 for yes, 0 for no: ";
  cin >> customers;
  if(customers == 1)
    continue;
  else if(customers == 0)
    isShopOpen = false;
}
  cout << "\nThe shop is now closed! We will now display statistics: \n";
  dealersCut = dealersProfit; //I'm not sure if this line is written logically because of how the loop increments, seems to work on repl.it
  cout << "The dealer made: " << dealersCut << "\n";
  cout << "Ford cars sold: " << fordSold << "\n";
  cout << "Nissan cars sold: " << nissanSold << "\n";
  cout << "Toyota cars sold: " << toyotaSold << "\n"; //As stated earlier, the brandSold variable isn't functioning properly due to how the loop changes the value incrementally
  cout << "Amount of extra packages sold: " << extrasSold << "\n";
  cout << "Amount of warranties sold: " << warrantySold << "\n";
}
