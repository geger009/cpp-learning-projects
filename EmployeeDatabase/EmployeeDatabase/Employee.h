#pragma once

#include <string>

namespace Records {
	const int k_nDefaultStartingSalary = 30000;

	class Employee
	{
	private:
		std::string		m_strFirstName;
		std::string		m_strLastName;

		int				m_nEmployeeNumber;
		int				m_nSalary;

		bool			m_isHired;

	public:
		Employee();

		void Promote(int nRaiseAmount = 1000);
		void Demote(int nDemeritAmount = 1000);
		
		void Hire();
		void Fire();

		void Display() const;

		void SetFirstName(const std::string& strFirstName) { m_strFirstName = strFirstName; }
		const std::string& GetFirstName() const { return m_strFirstName; }

		void SetLastName(const std::string& strLastName) { m_strLastName = strLastName; }
		const std::string& GetLastName() const { return m_strLastName; }

		void SetEmployeeNumber(int nEmployeeNumber) { m_nEmployeeNumber = nEmployeeNumber; }
		int GetEmployeeNumber() const { return m_nEmployeeNumber; }

		void SetSalary(int nNewSalary) { m_nSalary = nNewSalary; }
		int GetSalary() const { return m_nSalary; }

		bool IsHired() const { return m_isHired; }
	};
}
