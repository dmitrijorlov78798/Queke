#pragma once

#ifndef SYSTEM
#define SYSTEM

#include "MainHeader.h"

//exch
class bitMapPixel
{
private:
	uint8_t red, green, blue;
public:
	bitMapPixel() : red(0), green(0), blue(0)
	{}
	bitMapPixel(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue)
	{}
	uint8_t red()
	{
		return red;
	}
	uint8_t green()
	{
		return green;
	}
	uint8_t blue()
	{
		return blue;
	}
};


class bitMap
{
private:
	static const uint32_t SIZE_X = 600;
	static const uint32_t SIZE_Y = 400;
	bitMapPixel map[SIZE_Y][SIZE_X];
public:
	class Iterator
	{
	private:
		uint32_t X, Y;
		bitMap* p_map;
	public:
		Iterator() : X(0), Y(0), p_map(0)
		{}
		Iterator(uint32_t X, uint32_t Y, bitMap* p_map) : X(X), Y(Y), p_map(p_map)
		{}
		Iterator& operator++ ()
		{
			if (Y < 600)
				if (++X == 600)
				{
					X = 0; Y++;
				}
			return *this;
		}
		Iterator begin()
		{
			return Iterator(0, 0, p_map);
		}
		Iterator end()
		{
			return Iterator(0, 600, p_map);
		}
		bool operator!= (Iterator& const rValue)
		{
			return Y != rValue.Y || X != rValue.X;
		}
		bitMapPixel& operator * ()
		{
			X = X > SIZE_X || X < 0 ? 0 : X;
			Y = Y > SIZE_Y || Y < 0 ? 0 : Y;
			return p_map->map[Y][X];
		}
		bitMapPixel* operator -> ()
		{
			X = X > SIZE_X || X < 0 ? 0 : X;
			Y = Y > SIZE_Y || Y < 0 ? 0 : Y;
			return &p_map->map[Y][X];
		}
		/*bool operator < (iterator& const rValue)
		{
			bool result = false;

			if (Y == rValue.Y)
				result = X < rValue.X;
			else
				result = Y < rValue.Y;

			return result;
		}*/
	};
	Iterator iterator;
	bitMap() : iterator(0, 0, this)
	{}
};
//end


class cube
{
	uint8_t alfa, red, green, blue;
};


class actor;

typedef uint32_t indexActor;

const indexActor nullIndex = 0;

class grid
{
private:
	grid* p_self;
	static const uint32_t SIZE_X = 50;
	static const uint32_t SIZE_Y = 50;
	static const uint32_t SIZE_Z = 50;
	indexActor massive[SIZE_Z][SIZE_Y][SIZE_X];
public:
	class iterator
	{
		uint32_t X, Y, Z;
	};
};


class systemAbs
{
public:
	virtual void sleep(uint32_t ms) = 0;
	virtual void updateBitMap(bitMap& map) = 0;//exch
};

class systemWin : public systemAbs
{
private://exch 
	HWND hwnd;//exch 
	HDC hdc;//exch 
	bool firstRun;//exch 
	int sizeWindowX;//exch 
	int sizeWindowY;//exch 
public://exch 
	systemWin();//exch
	void sleep(uint32_t ms) override;
	void updateBitMap(bitMap& map) override;//exch
};

class system
{
private:
	systemAbs* p_abs;
	static system* p_self;
public:
	static system* instance();
	void sleep(uint32_t ms);
	void updateBitMap(bitMap& map);//exch
protected:
	system();
	
};

#endif // !SYSTEM

