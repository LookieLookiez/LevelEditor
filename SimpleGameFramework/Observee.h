#pragma once

#include <list>


class Observer;

class Observee
{
public:
	Observee();
	~Observee();

	void Update();

	void Register(Observer* toRegister);
	void DeRegister(Observer* toDeregister);

protected:
	std::list <Observer*> Obsevers;
};

