#pragma once

template <typename ElementType>
class TSetElement
{
public:
    ElementType Value;
    mutable int32 HashNextId;
    mutable int32 HashIndex;

    TSetElement(ElementType InValue, int32 InHashNextId, int32 InHashIndex)
        : Value(InValue)
        , HashNextId(InHashNextId)
        , HashIndex(InHashIndex)
    {
    }

    FORCEINLINE TSetElement<ElementType>& operator=(const TSetElement<ElementType>& Other)
    {
        Value = Other.Value;
    }

    FORCEINLINE bool operator==(const TSetElement& Other) const
    {
        return Value == Other.Value;
    }
    FORCEINLINE bool operator!=(const TSetElement& Other) const
    {
        return Value != Other.Value;
    }
};