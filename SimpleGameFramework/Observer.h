#pragma once

class Observee;

class Observer
{
public:
	Observer();
	~Observer();

	void OnSawEnemy(Observee* observeePtr);
};

