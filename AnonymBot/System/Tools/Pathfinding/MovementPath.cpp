#include "MovementPath.h"

MovementPath::MovementPath()
{
    m_pathTime = 0;
}

uint MovementPath::getPathTime() const
{
    return m_pathTime;
}

uint MovementPath::getPathSize() const
{
    return m_Path.size();
}

MapPoint MovementPath::getStart() const
{
    return m_Start;
}

MapPoint MovementPath::getEnd() const
{
    return m_End;
}

QList<PathElement> MovementPath::getPath() const
{
    return m_Path;
}

void MovementPath::setStart(MapPoint val)
{
    m_Start = val;
}

void MovementPath::setEnd(MapPoint val)
{
    m_End = val;
}

void MovementPath::fillFromCellIds(QVector<uint> cellIds)
{
    uint a = 0;
    while(a < cellIds.size())
    {
        PathElement element((MapPoint::fromCellId(cellIds[a])));
        m_Path.append(element);
        a++;
    }

    a = 0;
    while(a < cellIds.size())
    {
        PathElement(m_Path[a]).setOrientation(PathElement(m_Path[a]).getStep().orientationTo(PathElement(m_Path[a + 1]).getStep()));
        a++;
    }

    if(m_Path.contains(m_Path[0]))
    {
        m_Start = m_Path[0].getStep();
        m_End = m_Path[m_Path.size() - 1].getStep();
    }
}

void MovementPath::addPoint(PathElement element)
{
    m_Path.append(element);
}

PathElement MovementPath::getPointAtIndex(uint i)
{
    return m_Path[i];
}

void MovementPath::deletePoint(uint start, uint end)
{
    if (!end)
        m_Path.mid(start);
    else
        m_Path.mid(start, end);
}

void MovementPath::compress()
{
    uint a = 0;
    if(m_Path.size() > 0)
    {
        a = m_Path.size() - 1;
        while (a > 0)
        {
            if (m_Path[a].getOrientation() == m_Path[a - 1].getOrientation())
            {
                m_Path.removeAt(a);
                a--;
            }
            else
                a--;
        }
    }
}

int MovementPath::getCellVelocity(PathElement pE, bool mount, bool walking)
{
    if (!mount)
    {
        if (pE.getOrientation() % 2 == 0)
        {
            if (pE.getOrientation() % 4 == 0)
            {
                if (walking)
                    return 510;
                else
                    return 255;
            }

            else
            {
                if (walking)
                    return 425;
                else
                    return 150;
            }
        }

        else
        {
            if (walking)
                return 480;
            else
                return 170;
        }
    }

    else
    {
        if (pE.getOrientation() % 2 == 0)
        {
            if (pE.getOrientation() % 4 == 0)
            {
                if (walking)
                    return 510;
                else
                    return 200;
            }

            else
            {
                if (walking)
                    return 425;
                else
                    return 120;
            }
        }

        else
        {
            if (walking)
                return 480;
            else
                return 135;
        }
    }

    return 0;
}

void MovementPath::processTime(bool mount)
{
    m_pathTime = 0;
    bool walking = m_Path.size() < 4 ? true : false;

    for (int i = 0; i < m_Path.size(); i++)
        m_pathTime += getCellVelocity(m_Path.at(i), mount, walking);
}

void MovementPath::removeLastCell()
{
    m_Path.removeLast();
}

void MovementPath::fill()
{
    int elem = 0;
    PathElement pFinal;
    PathElement pe;

    if (m_Path.size() >= 2)
    {
        pFinal.setOrientation(0);
        pFinal.setStep(m_End);
        m_Path.append(pFinal);

        while (elem < m_Path.size() - 1)
        {
            //((abs(m_Path[elem].getStep().getX() - m_Path[(elem + 1)].getStep().getX()) > 1) || (abs(m_Path[elem].getStep().getY() - m_Path[(elem + 1)].getStep().getY()) > 1))
            if ((abs(m_Path[elem].getStep().getX() - m_Path[(elem + 1)].getStep().getX()) > 1) || (abs(m_Path[elem].getStep().getY() - m_Path[(elem + 1)].getStep().getY()) > 1))
            {
                pe.setOrientation(m_Path[elem].getOrientation());
                switch (pe.getOrientation())
                {
                case DirectionEnum::RIGHT_DIR:
                    pe.setStep(MapPoint::fromCoords((m_Path[elem].getStep().getX() + 1), (m_Path[elem].getStep().getY() + 1)));
                    break;
                case DirectionEnum::DOWN_RIGHT_DIR:
                    pe.setStep(MapPoint::fromCoords((m_Path[elem].getStep().getX() + 1), m_Path[elem].getStep().getY()));
                    break;
                case DirectionEnum::DOWN_DIR:
                    pe.setStep(MapPoint::fromCoords((m_Path[elem].getStep().getX() + 1), (m_Path[elem].getStep().getY() - 1)));
                    break;
                case DirectionEnum::DOWN_LEFT_DIR:
                    pe.setStep(MapPoint::fromCoords(m_Path[elem].getStep().getX(), (m_Path[elem].getStep().getY() - 1)));
                    break;
                case DirectionEnum::LEFT_DIR:
                    pe.setStep(MapPoint::fromCoords((m_Path[elem].getStep().getX() - 1), (m_Path[elem].getStep().getY() - 1)));
                    break;
                case DirectionEnum::UP_LEFT_DIR:
                    pe.setStep(MapPoint::fromCoords((m_Path[elem].getStep().getX() - 1), m_Path[elem].getStep().getY()));
                    break;
                case DirectionEnum::UP_DIR:
                    pe.setStep(MapPoint::fromCoords((m_Path[elem].getStep().getX() - 1), (m_Path[elem].getStep().getY() + 1)));
                    break;
                case DirectionEnum::UP_RIGHT_DIR:
                    pe.setStep(MapPoint::fromCoords(m_Path[elem].getStep().getX(), (m_Path[elem].getStep().getY() + 1)));
                    break;
                default:
                    break;
                }

                m_Path.insert(elem+1, pe);
                elem++;
            }
            else
                elem++;

            if (elem > 100)
                qDebug() << "Path error maybe an orientation problem!";
        }
        m_Path.removeLast();
    }
}

QVector<uint> MovementPath::getCells()
{
    uint i = 0;
    MapPoint point;
    QVector<uint> idList;

    while(i < m_Path.size())
    {
        point = m_Path[i].getStep();
        idList.append(point.getCellId());
        i++;
    }

    idList.append(m_End.getCellId());
    return idList;
}

void MovementPath::replaceEnd(MapPoint point)
{
    m_End = point;
}
