//===============2021===============//
//===		  Xen & DMDr	     ===//
//===============2021===============//

#ifndef CCURSORCLIPMANAGEMENT_H
#define CCURSORCLIPMANAGEMENT_H
#ifdef _WIN32
#pragma once
#endif

// This clips the cursor to the current window's client rectangle as long as it's active. This will automatically fix some bugs on VGUI too.
class CCursorClipManagement
{
public:
	CCursorClipManagement();
	~CCursorClipManagement();
	void Think();

	static void Init();
protected:
	// Locks the cursor if not locked.
	void UnlockCursor();
	// Unlocks the cursor if locked.
	void LockCursor(bool mouseDown = false);
	bool GetCurrentRECT(long &left, long &top, long &right, long &bottom, bool mouseDown) ;
	
private:
	void* m_HWND;

	bool m_bLockState;
	bool m_bLockStateMouseDown;
	bool m_bToolsMode;
	bool m_bDevMode;
	bool m_bEnabled;
	bool m_bLastMouseDownState;
	bool m_bMouseDownStartedOutside;

	float m_flMouseDownStartedAt;
};

extern CCursorClipManagement *g_pCursorClipManager;

#endif // CCURSORCLIPMANAGEMENT_H