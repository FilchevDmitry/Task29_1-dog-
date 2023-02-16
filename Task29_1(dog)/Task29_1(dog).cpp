#include <iostream>
#include<string>
#include<vector>

class Talent
{
protected:
	std::string talent;
	Talent(std::string inTalent) :talent(inTalent)
	{

	}
public:

	virtual std::string getTalent()=0;
};
class Swimming : virtual public Talent
{
public:
	Swimming() :Talent("swim") 
	{
	}
	virtual std::string getTalent()
	{
		return talent;
	}
};
class Dancing : virtual public Talent
{
public:
	Dancing() :Talent("dance")
	{
	}
	virtual std::string getTalent()
	{
		return talent;
	}
};
class Counting : virtual public Talent
{
public:
	Counting() :Talent("counting")
	{
	}
	virtual std::string getTalent()
	{
		return talent;
	}
};

class Dog
{
protected:
	std::string name;
	std::vector<class Talent*> talent;
public:
	Dog(std::string inName) : name{ inName }
	{

	}
	std::string getName()
	{
		return name;
	}
	void setTalent()
	{
		int num = 0;
		bool end = true;
		while (end)
		{
			std::cout << "Enter Talent 1-Swimming 2-Dancing 3-counting 4-exit : ";
			std::cin >> num;
			switch (num)
			{
			case(1):
			{
				talent.push_back(new Swimming());
				break;
			}
			case(2):
			{
	
				talent.push_back( new Dancing());
				break;
			}
			case(3):
			{
				talent.push_back(new Counting());
				break;
			}
			case(4):
			{
				end = false;
				break;
			}
			default:
			{
				std::cout << "Invalid input" << std::endl;
				break;
			}
			}
		}
	}
	void show_talents()
	{
		std::cout << "This is " << name << " and it has some talents :" << std::endl;
		for (int i = 0; i < talent.size(); i++)
		{
			std::cout << "It can " << talent[i]->getTalent() << std::endl;
		}

	}
	~Dog()
	{
		for (int i = 0; i < talent.size(); i++)
		{
			delete[] talent[i];
		}
		talent.clear();
	}
};


int main()
{
	Dog dog1("Smit");
	dog1.setTalent();
	dog1.show_talents();
	return 0;
}
