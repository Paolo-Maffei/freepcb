#ifndef _II_SEG_WIDTH_H /* [ */
#define _II_SEG_WIDTH_H

#include "ii_FreePcb.h"

// Width information for segments
class CSegWidthInfo : public CII_FreePcb
{
protected:
	virtual void OnRemoveParent(CInheritableInfo const *pOldParent)
	{
		m_seg_width.OnRemoveParent();
		m_ca_clearance.OnRemoveParent();

		CII_FreePcb::OnRemoveParent(pOldParent);
	}

public:
	CSegWidthInfo( CInheritableInfo const &from ) :
		CII_FreePcb(from)
	{
		*this = from;
	}

	explicit CSegWidthInfo( int seg_width = E_USE_PARENT, int clearance = E_USE_PARENT )
	{
		FileToItem(seg_width, m_seg_width);

		// Don't need to use FileToItem() for clearance
		m_ca_clearance = clearance;
	}

	CSegWidthInfo &operator = ( CInheritableInfo const &from );
	CSegWidthInfo &operator = ( CSegWidthInfo const &from ) { operator = (static_cast<CInheritableInfo const &>(from)); return *this; }

public:
	// Direct for non-updating version
	Item m_seg_width;
	Item m_ca_clearance;

	// For backwards compatibility with .fpc files, value of 0 means "use_parent".
	static int  ItemToFile(Item const &from)   { int to = from.GetItemAsInt(); if (to == E_USE_PARENT) to = 0; return to; }
	static void FileToItem(int from, Item &to) { if (from == 0) from = E_USE_PARENT; to.SetItemFromInt(from); }

    // Update the current value of ...
	void Update_seg_width();
	void Update_ca_clearance();

	// Update all
	void Update()
	{
		Update_seg_width();
		Update_ca_clearance();
	}

	// Undef all
	void Undef()
	{
		m_seg_width.Undef();
		m_ca_clearance.Undef();
	}

	virtual Item const &GetItem( int item_id ) const;
};


class CConnectionWidthInfo : public CSegWidthInfo
{
protected:
    virtual void GetItemExt( Item &item, Item const &src ) const;

	virtual void OnRemoveParent( CInheritableInfo const *pOldParent )
	{
		m_via_width.OnRemoveParent();
		m_via_hole .OnRemoveParent();

		CSegWidthInfo::OnRemoveParent( pOldParent );
	}

	void ApplyDefWidths(Item *p_via_width, Item *p_via_hole);

public:
	CConnectionWidthInfo() :
		m_via_width(E_USE_PARENT),
		m_via_hole (E_USE_PARENT)
	{
	}

	explicit CConnectionWidthInfo( CInheritableInfo const &from ) :
		CSegWidthInfo( from )
	{
		*this = from;
	}

	CConnectionWidthInfo( int seg_width, int via_width, int via_hole ) :
		CSegWidthInfo( seg_width )
	{
		FileToItem(via_width, m_via_width);
		FileToItem(via_hole,  m_via_hole);

		ApplyDefWidths( &m_via_width, &m_via_hole );
	}

	CConnectionWidthInfo &operator = ( CInheritableInfo const &from );
	CConnectionWidthInfo &operator = ( CConnectionWidthInfo const &from ) { operator = (static_cast<CInheritableInfo const &>(from)); return *this; }

public:
	// Direct for non-updating version
	Item m_via_width;
	Item m_via_hole;

    // Update the current value of ...
	void Update_via_width();
	void Update_via_hole();

	// Update all
	void Update();

	// Undef all
	void Undef()
	{
		CSegWidthInfo::Undef();

		m_via_width.Undef();
		m_via_hole.Undef();
	}

	virtual Item const &GetItem( int item_id ) const;
};

typedef CConnectionWidthInfo CNetWidthInfo;


#endif /* !_II_SEG_WIDTH_H ] */
