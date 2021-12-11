#include <iostream>

class CObject
{
public:
	virtual void someMethod() {}
};

class CObjectArray {
private:
	int count;
	CObject** objects;
public:
	CObjectArray(int count) {
		this->count = count;
		objects = new CObject * [count];
		for (int i = 0; i < count; i++) {
			objects[i] = nullptr;
		}
	}
	~CObjectArray() {
		for (int i = 0; i < count; i++) {
			if (objects[i] != nullptr)
				delete (objects[i]);
		}
		delete[] objects;
	}
	void setCObject(int index, CObject* _object) {
		if (objects[index] != nullptr) {
			delete (objects[index]);
			objects[index] = _object;
		}
		else {
			objects[index] = _object;
		}
	}
	CObject* getCObject(int index) {
		return objects[index];
	}
	void delCObject(int index) {
		if (objects[index] != nullptr)
			delete objects[index];
	}
	int getCount() {
		return count;
	}
};

class CCicle : public CObject {
private:
	int rad;
public:
	CCicle() {
		rad = 10;
	}
	virtual void someMethod() override
	{
		printf("\nsomeMethod() : CCicle");
	}
};

class CAnimal : public CObject {
public:
	virtual void someMethod() override
	{
		printf("\nsomeMethod() : CAnimal");
	}
};

class CLizard : public CAnimal {
private:
	const char* name;
	int age;
public:
	CLizard() {
		name = "Vitalya";
		age = 10;
	}
	virtual void someMethod() override
	{
		printf("\nsomeMethod() : CLizard");
	}
};
int main() {
	setlocale(LC_ALL, "");

	CObjectArray myStorage(10);
	for (int i = 0; i < myStorage.getCount(); i++) {
		switch (rand() % 3)
		{
		case 0:
			myStorage.setCObject(i, new CCicle());
			break;
		case 1:
			myStorage.setCObject(i, new CAnimal());
			break;
		default:
			myStorage.setCObject(i, new CLizard());
			break;
		}
	}
	for (int i = 0; i < myStorage.getCount(); i++) {
		myStorage.getCObject(i)->someMethod();
	}
	return 0;
}