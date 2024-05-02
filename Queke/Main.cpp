// Queke.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}
//system.cpp
static system::p_self = 0;

system::system() : p_abs(0)
{
#ifdef __WINDOWS__
	p_abs = new systemWin;
#endif // __WINDOWS__
	if (p_abs == 0)
		p_abs = new systemWin;
}

system* system::instance()
{
	if (p_self == 0)
		p_self = new system;
	return p_self;
}

void system::sleep(uint32_t ms)
{
	p_abs->sleep(ms);
}




systemWin::sleep(uint32_t ms)
{
	Sleep(ms);
}
/////////////////////
#include <stdint.h>
#include <Windows.h>

// system.h
class cube
{
	uint8_t alfa, red, green, blue;
};

class grid
{
private:
	grid* p_self;
	const uint32_t SIZE_X = 500;
	const uint32_t SIZE_Y = 500;
	const uint32_t SIZE_Z = 500;
	cube[SIZE_Z][SIZE_Y][SIZE_X];
public:
	class iterator
	{
		uint32_t X, Y, Z;
	}
};


class systemAbs
{
public:
	virtual void sleep(uint32_t ms) = 0;
};

class systemWin : public systemAbs
{
	void sleep(uint32_t ms) override;
};

class system
{
private:
	systemAbs* p_abs;
	static system* p_self;
public:
	static system* instance();
	void sleep(uint32_t ms);
protected:
	system();
};
// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
