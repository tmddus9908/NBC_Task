#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;


class Animal
{
public:
	virtual void makeSound() = 0;
	virtual void makeMove() = 0;
	virtual ~Animal() { cout << "Animal ¼Ò¸êÀÚ È£Ãâ " << endl; };
};

class Dog : public Animal
{
public:
	void makeSound()
	{
		cout << "DogSound" << endl;
	}
	void makeMove()
	{
		cout << "DogMove" << endl;
	}
};

class Cat : public Animal
{
public:
	void makeSound()
	{
		cout << "CatSound" << endl;
	}
	void makeMove()
	{
		cout << "CatMove" << endl;
	}
};

class Cow : public Animal
{
public:
	void makeSound()
	{
		cout << "CowSound" << endl;
	}
	void makeMove()
	{
		cout << "CowMove" << endl;
	}
};

class Zoo
{
private:
	Animal* animals[10] = { nullptr };
public:
	void addAnimal(Animal* animal)
	{
		for (int i = 0; i < 10; i++)
		{
			if (animals[i] == nullptr)
			{
				animals[i] = animal;
				break;
			}
		}
	};
	void performActions()
	{
		for (int i = 0; i < 10; i++)
		{
			if (animals[i] != nullptr)
			{
				animals[i]->makeSound();
				animals[i]->makeMove();
			}
			
		}
	};
	~Zoo()
	{
		cout << "Zoo ¼Ò¸êÀÚ È£Ãâ" << endl;
		for (int i = 0; i < 10; i++)
		{
			if (animals[i] != nullptr)
				delete animals[i];
			else
				break;
		}
	};
};
Animal* createRandomAnimal()
{
	int randomNum = rand() % 3;
	switch (randomNum)
	{
		case 0: return new Dog();
		case 1: return new Cat();
		case 2: return new Cow();
		default:
			break;
	}
}
int main()
{
	vector<Animal*> animals;
	animals.push_back(new Dog());
	animals.push_back(new Cat());
	animals.push_back(new Cow());

	for (size_t i = 0; i < animals.size(); i++)
		animals[i]->makeSound();
	for (size_t i = 0; i < animals.size(); i++)
		delete animals[i];

	Zoo* zoo = new Zoo();
	for (int i = 0; i < 10; i++)
		zoo->addAnimal(createRandomAnimal());
	
	zoo->performActions();

	delete zoo;
}