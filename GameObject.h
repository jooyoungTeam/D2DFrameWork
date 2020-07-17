#pragma once
class GameObject
{
protected:
	string    mName;
	Vector2   mPosition;
	Vector2   mSize;
	FloatRect mRect;
	bool      mActive;

public:
	GameObject();
	virtual ~GameObject();

	virtual void Init()    = 0;
	virtual void Release() = 0;
	virtual void Update()  = 0;
	virtual void Render()  = 0;

	string    GetName()     { return mName; }
	Vector2   GetPosition() { return mPosition; }
	Vector2   GetSize()     { return mSize; }
	FloatRect GetRect()     { return mRect; }
	bool      GetActive()   { return mActive; }
};

