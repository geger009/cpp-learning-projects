#include <iostream>
#include <stdexcept>
#include <exception>

#include "Database.h"

// Function Prototype
int DisplayMenu();
void DoHire(Records::Database& db);
void DoFire(Records::Database& db);
void DoPromote(Records::Database& db);
void DoDemote(Records::Database& db);

int main() 
{
	Records::Database cEmployeeDB;

	bool isDone = false;

	while (!isDone) 
	{
		int nSelection = DisplayMenu();
		switch (nSelection)
		{
		case 1:
			DoHire(cEmployeeDB);
			break;
		case 2:
			DoFire(cEmployeeDB);
			break;
		case 3:
			DoPromote(cEmployeeDB);
			break;
		case 4:
			DoDemote(cEmployeeDB);
			break;
		case 5:
			cEmployeeDB.DisplayAll();
			break;
		case 6:
			cEmployeeDB.DisplayCurrent();
			break;
		case 7:
			cEmployeeDB.DisplayFormer();
			break;
		case 0:
			isDone = true;
			break;
		default:
			std::cerr << "Unknown Command!" << std::endl;
			break;
		}
	}

	return 0;
}

int DisplayMenu()
{
	int nSelection;
	
	std::cout << std::endl;
	std::cout << "Employee Database" << std::endl;
	std::cout << "-----------------" << std::endl;
	std::cout << "1) Hire a new employee" << std::endl;
	std::cout << "2) Fire an employee" << std::endl;
	std::cout << "3) Promote an employee" << std::endl;
	std::cout << "4) Demote an employee" << std::endl;
	std::cout << "5) List all employees" << std::endl;
	std::cout << "6) List all current employees" << std::endl;
	std::cout << "7) List all former employees" << std::endl;
	std::cout << "0) Quit" << std::endl;
	std::cout << std::endl;
	std::cout << "---> ";
	std::cin >> nSelection;

	return nSelection;
}

void DoHire(Records::Database& db)
{
	std::string strFirstName;
	std::string strLastName;

	std::cout << "First name? ";
	std::cin >> strFirstName;
	std::cout << "Last name? ";
	std::cin >> strLastName;

	try
	{
		db.AddEmployee(strFirstName, strLastName);
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Unable to add new employee: " << exception.what() << std::endl;
	}
}

void DoFire(Records::Database& db)
{
	int nEmployeeNumber;

	std::cout << "Employee number? ";
	std::cin >> nEmployeeNumber;

	try
	{
		Records::Employee& cCurrentEmployee = db.GetEmployee(nEmployeeNumber);
		cCurrentEmployee.Fire();

		std::cout << "Employee " << nEmployeeNumber << " terminated." << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Unable to terminate employee: " << exception.what() << std::endl;
	}
}

void DoPromote(Records::Database& db)
{
	int nEmployeeNumber;
	int nRaiseAmount;

	std::cout << "Employee number? ";
	std::cin >> nEmployeeNumber;
	std::cout << "How much of a raise? ";
	std::cin >> nRaiseAmount;

	try
	{
		Records::Employee& cCurrentEmployee = db.GetEmployee(nEmployeeNumber);
		cCurrentEmployee.Promote(nRaiseAmount);

		std::cout << "Employee " << nEmployeeNumber << " promoted." << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Unable to promote employee: " << exception.what() << std::endl;
	}
}

void DoDemote(Records::Database& db)
{
	int nEmployeeNumber;
	int nDemeritAmount;

	std::cout << "Employee number? ";
	std::cin >> nEmployeeNumber;
	std::cout << "How much of a demerit? ";
	std::cin >> nDemeritAmount;

	try
	{
		Records::Employee& cCurrentEmployee = db.GetEmployee(nEmployeeNumber);
		cCurrentEmployee.Demote(nDemeritAmount);

		std::cout << "Employee " << nEmployeeNumber << " demoted." << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cerr << "Unable to demote employee: " << exception.what() << std::endl;
	}
}
