#ifndef _DLE_RECT_ROUNDED_H /* [ */
#define _DLE_RECT_ROUNDED_H

#include "dle_rect.h"

// filled rounded rectangle
class CDLE_RRECT : public CDLE_RECT
{
protected:
	virtual void _Draw         (CDrawInfo const &di) const;
	virtual void _DrawClearance(CDrawInfo const &di) const;
};

// rounded rectangle outline
typedef CDLE_RRECT CDLE_HOLLOW_RRECT;

#endif /* !_DLE_RECT_ROUNDED_H ] */
