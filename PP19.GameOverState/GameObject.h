#pragma once
#include"LoaderParams.h"
#define zero 0
class GameObject
{
public:
	virtual void draw() = zero;
	virtual void update() = zero;
	virtual void clean() = zero;
protected:
	GameObject(const LoaderParams* pParams) {}
	virtual ~GameObject() {}
};