#include "MainHeader.h"

static system* system::p_self = 0;

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


//exch 
void system::updateBitMap(bitMap& map)
{
	p_abs->updateBitMap(map);
}
//exch end


//exch 
systemWin::systemWin() : firstRun(true), sizeWindowX(0), sizeWindowY(0)
{

	hwnd = GetConsoleWindow();
	hdc = GetDC(hwnd);
}
//exch end

systemWin::sleep(uint32_t ms)
{
	Sleep(ms);
}
//exch 
void systemWin::updateBitMap(bitMap& map) //добавить const iter
{
	if (!firstRun)
	{
		bitMap::Iterator iter = map.iterator.begin();
		COLORREF color;

		for (int y = 0; y < sizeWindowY && iter != map.iterator.end(); ++y, ++iter)// убрать iterator в map.iterator.end() 
			for (int x = 0; x < sizeWindowX && iter != map.iterator.end(); ++x, ++iter)
				SetPixel(hdc, x, y, RGB(iter->red(), iter->green(), iter->blue());
	}
}