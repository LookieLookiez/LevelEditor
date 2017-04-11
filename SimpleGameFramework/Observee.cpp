#include "stdafx.h"
#include "Observee.h"
#include "Observer.h"


Observee::Observee()
{
}


Observee::~Observee()
{
}

void Observee::Update()
{

	//some criteria here (eg. vision system)

	for (Observer* observerPtr : Obsevers)
	{
		observerPtr->OnSawEnemy(this);
	}
}

void Observee::Register(Observer * toRegister)
{
	Obsevers.push_back(toRegister);
}

void Observee::DeRegister(Observer * toDeregister)
{
	Obsevers.remove(toDeregister);
}
