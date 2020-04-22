#include <iostream>
#include "Employee.h"

namespace Records {
	Employee::Employee()
		: m_strFirstName("")
		, m_strLastName("")
		, m_nEmployeeNumber(-1)
		, m_nSalary(k_nDefaultStartingSalary)
		, m_isHired(false)
	{
	}

	void Employee::Promote(int nRaiseAmount)
	{
		SetSalary(GetSalary() + nRaiseAmount);
	}

	void Employee::Demote(int nDemeritAmount)
	{
		SetSalary(GetSalary() - nDemeritAmount);
	}

	void Employee::Hire()
	{
		m_isHired = true;
	}

	void Employee::Fire()
	{
		m_isHired = false;
	}

	void Employee::Display() const
	{
		std::cout << "Employee: " << GetLastName() << ", " << GetFirstName() << std::endl;
		std::cout << "-----------------------" << std::endl;
		std::cout << (m_isHired ? "Current Employee" : "Former Employee") << std::endl;
		std::cout << "Employee Number: " << GetEmployeeNumber() << std::endl;
		std::cout << "Salary: $" << GetSalary() << std::endl;
		std::cout << std::endl;
	}

}