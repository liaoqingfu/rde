#include "moduledockitem.h"
/*                                                                                               */
ModuleDockItem::ModuleDockItem()
{
    setParentItem(Dock::column);
    setWidth(parentItem()->width());
    setHeight(72);
}
/*                                                                                               */