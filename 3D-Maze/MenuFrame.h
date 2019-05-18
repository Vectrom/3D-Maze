#ifndef __MenuFrame__
#define __MenuFrame__

/**
@file
Subclass of BaseMenuFrame, which is generated by wxFormBuilder.
*/

#include "BaseMenuFrame.h"

//// end generated include

/** Implementing BaseMenuFrame */
class MenuFrame : public BaseMenuFrame
{
	protected:
		// Handlers for BaseMenuFrame events.
		void _playButtonOnButtonClick( wxCommandEvent& event );
		void _loadBoardButtonOnButtonClick( wxCommandEvent& event );
		void _createBoardButtonOnButtonClick( wxCommandEvent& event );
		void _exitButtonOnButtonClick( wxCommandEvent& event );
	public:
		/** Constructor */
		MenuFrame( wxWindow* parent );
	//// end generated class members

};

#endif // __MenuFrame__
