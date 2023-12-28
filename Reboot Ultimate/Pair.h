#pragma once

template <typename KeyType, typename ValueType>
class TPair
{
public:
    KeyType First;
    ValueType Second;

    FORCEINLINE KeyType& Key()
    {
        return First;
    }
    FORCEINLINE const KeyType& Key() const
    {
        return First;
    }
    FORCEINLINE ValueType& Value()
    {
        return Second;
    }
    FORCEINLINE const ValueType& Value() const
    {
        return Second;
    }
};