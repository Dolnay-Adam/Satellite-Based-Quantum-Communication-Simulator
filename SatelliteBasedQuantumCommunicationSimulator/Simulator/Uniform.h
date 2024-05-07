#pragma once

#include "Program.h"
#include <iostream>
#include <any>

class Uniform
{
public:
	virtual Uniform& setValue(const std::any value) = 0;
	virtual Uniform& commit(Program& program) = 0;

	std::string getName() const {
		return m_name;
	}

protected:

	explicit Uniform(const std::string& name) : m_name(name) {}

private:
	std::string m_name;

	Uniform() = default;
};

