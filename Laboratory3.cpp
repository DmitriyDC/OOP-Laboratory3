#include <iostream>

class CObject //Абстракный класс
{
public:
	virtual void someMethod() {} //вызов метода класса
};

class CObjectArray { //массив объектов
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
				delete (objects[i]); //удаление объектов массива
		}
		delete[] objects; //удаление массива
	}
	void setCObject(int index, CObject* _object) { //добавление объекта
		if (index < 0 && index >= count) return;
		if (objects[index] != nullptr) {
			objects[index] = _object;
		}
		else {
			objects[index] = _object;
		}
	}
	CObject* getCObject(int index) { //получение объекта
		if (index < 0 && index >= count || objects[index] == nullptr)
			return new CObject();
		else
			return objects[index];
	}
	void delCObject(int index) { //удаление объекта
		if (index < 0 && index >= count) return;
		if (objects[index] != nullptr)
			objects[index] = nullptr;
	}
	int getCount() {
		return count;
	}
};

class CKruh : public CObject {
private:
	int radius;
public:
	CKruh() {
		radius = 10;
	}
	virtual void someMethod() override
	{
		printf("\nsomeMethod() : CKruh");
	}
};

class CZvire : public CObject {
public:
	virtual void someMethod() override
	{
		printf("\nsomeMethod() : CZvire");
	}
};

class CJesterka : public CZvire {
private:
	const char* name;
	int age;
public:
	CJesterka() {
		name = "Andrey";
		age = 45;
	}
	virtual void someMethod() override
	{
		printf("\nsomeMethod() : CJesterka");
	}
};
int main() {
	setlocale(LC_ALL, "");

	CObjectArray myStorage(1000);
	for (int i = 0; i < myStorage.getCount(); i++) {
		int a = (rand() % myStorage.getCount());
		switch (rand() % 5)
		{
		case 0:
			myStorage.setCObject(i, new CKruh());
			break;
		case 1:
			myStorage.setCObject(i, new CZvire());
			break;
		case 2:
			myStorage.setCObject(i, new CJesterka());
			break;
		case 3:
			myStorage.delCObject(a);
			break;
		default:
			break;
		}
	}
	for (int i = 0; i < myStorage.getCount(); i++) {
		myStorage.getCObject(i)->someMethod();
	}
	return 0;
}