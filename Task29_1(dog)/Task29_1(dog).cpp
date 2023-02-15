#include <iostream>
#include<string>
#include<vector>

class Talent
{
public:

	virtual std::string getTalent() = 0;

};
class Swimming : virtual public Talent
{
public:

	virtual std::string getTalent()
	{
		return "swim";
	}
};
class Dancing : virtual public Talent
{
public:
	virtual std::string getTalent()
	{
		return "dance";
	}
};
class Counting
{
public:
	virtual std::string getTalent()
	{
		return "counting";
	}
};

class Dog
{
protected:
	std::string name;

	std::vector<std::string> talent;
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
				Swimming swim;
				talent.push_back(swim.getTalent());
				break;
			}
			case(2):
			{
				Dancing dance;
				talent.push_back(dance.getTalent());
				break;
			}
			case(3):
			{
				Counting counting;
				talent.push_back(counting.getTalent());
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
			std::cout << "It can " << talent[i] << std::endl;
		}

	}

};


int main()
{
	Dog dog1("Steve");
	dog1.setTalent();
	dog1.show_talents();
	return 0;
}
