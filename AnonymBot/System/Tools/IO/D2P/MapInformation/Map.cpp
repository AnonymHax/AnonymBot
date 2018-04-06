#include "Map.h"

QByteArray Map::m_encryptionKey("649ae451ca33ec53bbcbcc33becf15f4");

Map::Map():
    m_isInit(false)
{
}

Map::Map(CompressedMap *compressedMap)
{
    if(compressedMap != NULL)
    {
        initializeMap(compressedMap);
        m_isInit = true;
    }

    else
        m_isInit = false;
}

bool Map::isInit() const
{
    return m_isInit;
}

void Map::initializeMap(CompressedMap *compressedMap)
{
    Reader reader(compressedMap->getPath());
    reader.setPosition(compressedMap->getOffset());
    QByteArray data = reader.readBytes(compressedMap->getByteCount());

    QByteArray result = gUncompress(data);
    reader.setBuffer(result);

    uchar header = reader.readByte();
    if (header != 77)
        qDebug()<<"ERREUR - Map - Format de la carte incorrect"<<header;

    m_mapVersion = reader.readByte();
    m_mapId = reader.readUInt();

    if (m_mapVersion >= 7)
    {
        bool encrypted = reader.readBool();
        uchar encryptionVersion = reader.readByte();
        int dataLen = reader.readInt();
        if (encrypted)
        {
            if (m_encryptionKey.isEmpty())
                qDebug()<<"ERREUR - Map - Decryptage de la carte sans clef";

            QByteArray encryptedData(reader.readBytes(dataLen), dataLen);

            for (int i = 0; i < encryptedData.size(); i++)
                encryptedData[i] = encryptedData[i] ^ m_encryptionKey[i % m_encryptionKey.size()];

            reader.setBuffer(encryptedData);

        }
    }

    m_position.setId(reader.readUInt());
    uchar maptype = reader.readByte();
    m_subAreaId = reader.readInt();
    m_topMapId = reader.readInt();
    m_bottomMapId = reader.readInt();
    m_leftMapId = reader.readInt();
    m_rightMapId = reader.readInt();
    int shadowBonusOnEntities = reader.readInt();

    if(m_mapVersion >= 9)
    {
        int readColor = reader.readInt();

        int backgroundAlpha = (readColor & 4278190080) >> 32;
        int backgroundRed = (readColor & 16711680) >> 16;
        int backgroundGreen = (readColor & 65280) >> 8;
        int backgroundBlue = readColor & 255;

        readColor = reader.readUInt();

        int gridAlpha = (readColor & 4278190080) >> 32;
        int gridRed = (readColor & 16711680) >> 16;
        int gridGreen = (readColor & 65280) >> 8;
        int gridBlue = readColor & 255;
        int gridColor = (gridAlpha & 255) << 32 | (gridRed & 255) << 16 | (gridGreen & 255) << 8 | gridBlue & 255;
    }

    else if (m_mapVersion >= 3)
    {
        uchar backgroundred = reader.readByte();
        uchar backgroundgreen = reader.readByte();
        uchar backgroundblue = reader.readByte();
    }

    if (m_mapVersion >= 4)
    {
        ushort zoomscale = static_cast<ushort>(reader.readUShort() / 100);
        short zoomoffsetx = reader.readShort();
        short zoomoffsety = reader.readShort();

    }

    bool uselowpassfilter = reader.readByte() == 1;
    bool usereverb = reader.readByte() == 1;

    if (usereverb)
        int pressetid = reader.readInt();

    uchar backgroundcount = reader.readByte();

    for (int i = 0; i < backgroundcount; i++)
        Fixture fixture(&reader);

    uchar foregroundcount = reader.readByte();

    for (int i = 0; i < foregroundcount; i++)
        Fixture fixture(&reader);

    reader.readInt();
    int groundCRC = reader.readInt();
    uchar layerscount = reader.readByte();
    for (int i = 0; i < layerscount; i++)
        Layer(&reader, this);

    for (int i = 0; i < 560; i++)
        m_cellData<<CellData(i, &reader, this);
}

uint Map::getMapId() const
{
    return m_mapId;
}

int Map::getRightMapId() const
{
    return m_rightMapId;
}

int Map::getLeftMapId() const
{
    return m_leftMapId;
}

int Map::getTopMapId() const
{
    return m_topMapId;
}

int Map::getBottomMapId() const
{
    return m_bottomMapId;
}


int Map::getSubAreaId() const
{
    return m_subAreaId;
}

QList<CellData> Map::getCellData() const
{
    return m_cellData;
}

WorldPoint Map::getPosition() const
{
    return m_position;
}

int Map::getMapVersion() const
{
    return m_mapVersion;
}

int Map::getInteractiveElementCellID(int elementId) const
{
    if(m_interactiveElements.contains(elementId))
        return m_interactiveElements[elementId];

    else
        qDebug()<<"ERREUR - Map - Ne connait pas l'interactiveElement d'id :"<<elementId;
}

QList<uint> Map::getFixedMapChanger() const
{
    return m_fixedMapChangers;
}

QList<uint> Map::getTopArrowCells() const
{
    return m_topArrowCells;
}

QList<uint> Map::getBottomArrowCells() const
{
    return m_bottomArrowCells;
}

QList<uint> Map::getRightArrowCells() const
{
    return m_rightArrowCells;
}

QList<uint> Map::getLeftArrowCells() const
{
    return m_leftArrowCells;
}

void Map::addTopArrowCell(uint cellId)
{
    m_topArrowCells << cellId;
}

void Map::addBottomArrowCell(uint cellId)
{
    m_bottomArrowCells << cellId;
}

void Map::addLeftArrowCell(uint cellId)
{
    m_leftArrowCells << cellId;
}

void Map::addRightArrowCell(uint cellId)
{
    m_rightArrowCells << cellId;
}
