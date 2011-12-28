#ifndef STACKTABLECELL
#define STACKTABLECELL

#include "TEComponentStack.h"

class StackTableCell : public TEComponentStack {
private:
	bool mClear;

public:
    StackTableCell(StackType stackType);

    virtual void update();
	virtual int getStackOffset(bool isFirst);
	virtual bool doesAccept(TEComponentStack* stack);
	virtual void pushStack(TEComponentStack* stack);
	virtual void popStack(TEComponentStack* stack);

	void setClear();
	bool getClear() const;
};
    
#endif