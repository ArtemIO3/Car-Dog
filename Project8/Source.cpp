#include <iostream>
#include <string>
using namespace std;

struct IPrint
{
	virtual void PrintConsole() = 0;
};

class TransPort :public IPrint
{
protected:
	string model;
	double price;
public:
	TransPort() { price = 0; }
	TransPort(string m, double p) { model = m; price = p; }
};
class Car : public TransPort
{
	string color;
	int weel;
	int seats;
public:
	Car(string m, double p, string c, int w, int s)
	{
		model = m;
		price = p;
		color = c;
		weel = w;
		seats = s;
	}
	virtual void PrintConsole() {
		cout << "Model: " << model << "\nPrice: " << price << "\nColor:" << color << "\nWeel: " << weel << "\nSeats: " << seats << endl;
	}
};
class Airplane : public TransPort
{
	string color;
	int weel;
	int seats;
	int turbine;
public:
	Airplane(string m, double p, string c, int w, int s, int t)
	{
		model = m;
		price = p;
		color = c;
		weel = w;
		seats = s;
		turbine = t;
	}
	virtual void PrintConsole() {
		cout << "Model: " << model << "\nPrice: " << price << "\nColor:" << color << "\nWeel: " << weel << "\nSeats: " << seats << "\nTurbine:" << turbine << endl;
	}
};
class Animal :public IPrint {
protected:
	string name;
	int weight;
	int age;
public:
	Animal() { weight = 0; age = 0; }
	Animal(string n, int w, int a)
	{
		name = n;
		weight = w;
		age = a;
	}
};
class Dog : public Animal
{
	string color;
	string breed;
public:
	Dog(string n, int w, int a, string c, string b)
	{
		name = n;
		weight = w;
		age = a;
		color = c;
		breed = b;
	}
	virtual void PrintConsole() {
		cout << "Name: " << name << "\nWeight: " << weight << "\nAge:" << age << "\nColor: " << color << "\nBreed: " << breed << endl;
	}
};
class Penguin : public Animal
{
	string color;
	int swimSpeed;
public:
	Penguin(string n, int w, int a, string c, int s)
	{
		name = n;
		weight = w;
		age = a;
		color = c;
		swimSpeed = s;
	}
	virtual void PrintConsole() {
		cout << "Name: " << name << "\nWeight: " << weight << "\nAge:" << age << "\nColor: " << color << "\nSwim Speed: " << swimSpeed << endl;
	}

};
int main()
{
	IPrint* iprint = nullptr;
	int choice = 0;
	cout << "1. Car" << endl;
	cout << "2. Airplane" << endl;
	cout << "3. Dog" << endl;
	cout << "4. Penguin" << endl;
	cout << "Make your choice: ";

	cin >> choice;
	switch (choice)
	{
	case 1:
		iprint = new Car("bmw", 2000, "red", 4, 5);
		break;
	case 2:
		iprint = new Airplane("boing", 50000, "white", 6, 300, 2);
		break;
	case 3:
		iprint = new Dog("rex", 20, 3, "black", "shepherd");
		break;
	case 4:
		iprint = new Penguin("pingu", 15, 5, "white-black", 10);
		break;
	}
	iprint->PrintConsole();
}