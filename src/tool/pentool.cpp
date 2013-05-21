
#include <QSettings>
#include "pentool.h"


PenTool::PenTool()
{

}

ToolType PenTool::type()
{
    return PEN;
}

void PenTool::loadSettings()
{
    QSettings settings("Pencil","Pencil");
    properties.width = settings.value("penWidth").toDouble();
    properties.colour = Qt::black;
    properties.colourNumber = 0;
    properties.feather = 0;    
    properties.pressure = ON;
    properties.invisibility = OFF;
    properties.preserveAlpha = OFF;

    if ( properties.width <= 0 )
    {
        properties.width = 1.5;
        settings.setValue("penWidth", properties.width);
    }

    if ( properties.feather < 0 )
    {
        properties.feather = 0;
    }
}
