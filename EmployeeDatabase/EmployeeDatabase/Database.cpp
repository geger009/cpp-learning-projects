#include <iostream>
#include <stdexcept>
#include "Database.h"

namespace Records {
	Database::Database()
		: m_nNextEmployeeNumber(k_nFirstEmployeeNumber)
	{
	}

	Employee& Database::AddEmployee(const std::string& strFirstName, const std::string& strLastName)
	{
		Employee cEmployee;
		cEmployee.SetFirstName(strFirstName);
		cEmployee.SetLastName(strLastName);
		cEmployee.SetEmployeeNumber(m_nNextEmployeeNumber++);
		cEmployee.Hire();

		m_vEmployee.push_back(cEmployee);

		return m_vEmployee[m_vEmployee.size() - 1];
	}

	Employee& Database::GetEmployee(int nEmployeeNumber)
	{
		for (auto& employee : m_vEmployee)
		{
			if (employee.GetEmployeeNumber() == nEmployeeNumber)
			{
				return employee;
			}
		}

		throw std::runtime_error("No Employee Found.");
	}

	Employee& Database::GetEmployee(const std::string& strFirstName, const std::string& strLastName)
	{
		for (auto& employee : m_vEmployee)
		{
			if (employee.GetFirstName() == strFirstName && employee.GetLastName() == strLastName)
			{
				return employee;
			}
		}

		throw std::runtime_error("No Employee Found.");
	}

	void Database::DisplayAll() const
	{
		for (const auto& employee : m_vEmployee)
		{
			employee.Display();
		}
	}

	void Database::DisplayCurrent() const
	{
		for (const auto& employee : m_vEmployee) 
		{
			if (employee.IsHired()) 
			{
				employee.Display();
			}
		}
	}

	void Database::DisplayFormer() const
	{
		for (const auto& employee : m_vEmployee)
		{
			if (!employee.IsHired())
			{
				employee.Display();
			}
		}
	}
}
