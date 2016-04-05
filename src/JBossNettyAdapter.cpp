#include "JBossNettyAdapter.hpp"

JBossNettyAdapter::JBossNettyAdapter(GPBMessageListener* gpbFrameListener)
{
    this->gpbFrameListener = gpbFrameListener;
    header = true;
    pos = 0;
}

int JBossNettyAdapter::onRead(void* buf, int size, int sliceId, Collector* collector)
{
    if (header)
    {
        return readVarInt32(*((char*)buf));
    }
    else
    {
        gpbFrameListener->onMessage(buf, size, sliceId, collector);

        header = true;
        pos = 0;
        return 1;
    }
}

int JBossNettyAdapter::readVarInt32(char byte)
{
    int pos = this->pos++;

    switch (pos)
    {
    case 0:
        result  = (byte & 0x7F);
        if (!(byte & 0x80))
        {
            header = false;
            return result;
        }
        break;
    case 1:
        result |= (byte & 0x7F) << 7;
        if (!(byte & 0x80))
        {
            header = false;
            return result;
        }
        break;
    case 2:
        result |= (byte & 0x7F) << 14;
        if (!(byte & 0x80))
        {
            header = false;
            return result;
        }
        break;
    case 3:
        result |= (byte & 0x7F) << 21;
        if (!(byte & 0x80))
        {
            header = false;
            return result;
        }
        break;
    case 4:
        result |= byte << 28;
        if (!(byte & 0x80))
        {
            header = false;
            return result;
        }
        break;
    }

    return 1;
}

void JBossNettyAdapter::writeVarInt32(int value, Collector* collector, int sourceId)
{
    while (true)
    {
        if ((value & ~0x7F) == 0)
        {
            char byte = value;
            collector->writeAdapter(&byte, 1, sourceId);
            return;
        }
        else
        {
            char byte = (value & 0x7F) | 0x80;
            collector->writeAdapter(&byte, 1, sourceId);
            value >>= 7;
        }
    }
}

JBossNettyAdapter::~JBossNettyAdapter()
{
}

