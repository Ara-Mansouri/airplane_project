#include<iostream>
#include<string>
using namespace std;
class airplane
{
private:
int counter =0;
public:
bool count();
void increaser();
int counter_getter();
};
bool airplane::count()
{
if (counter < 30)
{
return true;
}
else
return false;
}

void airplane::increaser()
{
counter += 1;
}

int airplane::counter_getter()
{
return (counter-1);
}


class passenger
{
private:
string name, last;
int ID = 0;
public:
void input(string ,string, int);
friend ostream& operator<<(ostream&, passenger&);


};
void passenger::input(string n, string l, int j)
{
name = n;
last = l;
ID = j;

}
ostream& operator <<(ostream& out, passenger& ob1)
{
out << ob1.ID << "_" << ob1.name << " " << ob1.last<<endl;
return out;
}
void print_options(string, string);
void print_option(string);
bool ask();
int ask_again(string);
void print_reservation(string);
int main()
{
airplane  first, business, economy;//objects for checking how many seats are currently available using a counter for each section.
passenger pass_name[30][3];//object for restoring names and last names of passengers.
string f = "first class", second = "business class", third = "economy class";//for printing functions.
string section;//for getting the chosen section
string name,lastname;//for getting the passenger's name and last name.
string final=" ";//for getting chosen section after asking again.
string answer2;
for (int i = 0;  ; i++)
{
bool flag=false;//final chosen section.
if ((first.count() || business.count() || economy.count()) == false)
{
cout << "sorry no section is available right now!"<<endl;
break;
}
cout << "Hi please Enter Your Full Name: ";
cin >> name;
cin.get();
getline(cin, lastname);
cout << "welcome " << name << "!" << endl << "Which service level are you interested in(your options are first ,business and economy class):";
cin >> section;

if (section == "first")
{
if (first.count())
{
print_reservation(f);
first.increaser();
flag=true;
final = "first";
}


else

{
if (ask() == false)
{
i -= i;
cout << "sorry we didn't meet your needs." << endl;
continue;

}
else
{
if (business.count() && economy.count())
print_options(second, third);
else
{
if (business.count())
print_option(second);
else
{
if (economy.count())
print_option(third);
}

}

}
}
}

if (section == "business")
{
if (business.count())
{

print_reservation(second);
business.increaser();
flag=true;
final = "business";
}
else
{
if (ask() == false)
{
i -= i;
cout << "sorry we didn't meet your needs." << endl;
continue;

}
else
{
if (first.count() && economy.count())
print_options(f, third);
else
{
if (first.count())
print_option(f);
else
{
if (economy.count())
print_option(third);
}

}

}
}
}
if (section == "economy")
{
if (economy.count())
{

print_reservation(third);
economy.increaser();
flag=true;
final = "economy";
}
else
{

if (ask() == false)
{
i -= i;
cout << "sorry we didn't meet your needs." << endl;
continue;

}
else
{
if (first.count() && business.count())
print_options(f, second);
else
{
if (first.count())
print_option(f);
else
{
if (business.count())
print_option(second);
}

}

}
}


}
if (flag == false)
{
cout << "are you interested in any of the remaining options(yes/no)?";
cin >> answer2;
if (ask_again(answer2) == 1)
{
cout << "enter your chosen section:";
cin >> final;
}
if (final == "first")
{
print_reservation(f);
pass_name[first.counter_getter()][0].input(name, lastname,i);
first.increaser();
}
if (final == "business")
{
print_reservation(second);
pass_name[business.counter_getter()][1].input(name, lastname,i);
business.increaser();
}
if (final == "economy")
{
print_reservation(third);
economy.increaser();
pass_name[economy.counter_getter()][2].input(name, lastname,i);
}

if(ask_again(answer2)==0)
{


cout << "sorry we didn't meet your needs!"<<endl;
i -= 1;
continue;

}
}
cout << endl;

}
cout << "FIRST CLASS" << endl;
for (int k = 0; k <= 29; k++)
{
cout << pass_name[k][0];
}
cout << "BUSINESS CLASS" << endl;
for (int d = 0; d<= 29; d++)
{
cout << pass_name[d][1];
}
cout << "ECONOMY CLASS"<<endl;
for (int p= 0; p <= 29; p++)
{
cout << pass_name[p][2];
}




}
void print_options(string one, string two)
{
cout << one << " section and " << two << " sections are available!"<<endl;
}
void print_option(string one)
{
cout  << one << " section is available!"<<endl;
}
bool ask()
{
string answer;
cout << "sorry your chosen option is not available right now, Are you interested in hearing other options(yes/no)?";
cin>> answer;
if (answer == "yes")
return true;
else
return false;

}
int ask_again(string javab)
{

if (javab== "yes")
return 1;
else
return 0;
}
void print_reservation(string seat)
{
cout << "your reservation is made at the " << seat << " level.";

}