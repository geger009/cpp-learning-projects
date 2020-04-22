#pragma once

#include <iostream>
#include <vector>
#include "Employee.h"

namespace Records {
	const int k_nFirstEmployeeNumber = 1000000;

	class Database
	{
	private:
		std::vector<Employee>	m_vEmployee;
		int						m_nNextEmployeeNumber;

	public:
		Database();

		Employee& AddEmployee(const std::string& strFirstName, const std::string& strLastName);
		Employee& GetEmployee(int nEmployeeNumber);
		Employee& GetEmployee(const std::string& strFirstName, const std::string& strLastName);

		void DisplayAll() const;
		void DisplayCurrent() const;
		void DisplayFormer() const;
	};
}
