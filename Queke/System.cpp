#include "MainHeader.h"

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