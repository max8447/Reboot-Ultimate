#pragma once

template <typename ElementType>
union TSparseArrayElementOrListLink
{
    TSparseArrayElementOrListLink(ElementType& InElement)
        : ElementData(InElement)
    {
    }
    TSparseArrayElementOrListLink(ElementType&& InElement)
        : ElementData(InElement)
    {
    }

    TSparseArrayElementOrListLink(int32 InPrevFree, int32 InNextFree)
        : PrevFreeIndex(InPrevFree)
        , NextFreeIndex(InNextFree)
    {
    }

    TSparseArrayElementOrListLink<ElementType> operator=(const TSparseArrayElementOrListLink<ElementType>& Other)
    {
        return TSparseArrayElementOrListLink(Other.NextFreeIndex, Other.PrevFreeIndex);
    }

    /** If the element is allocated, its value is stored here. */
    ElementType ElementData;

    struct
    {
        /** If the element isn't allocated, this is a link to the previous element in the array's free list. */
        int PrevFreeIndex;

        /** If the element isn't allocated, this is a link to the next element in the array's free list. */
        int NextFreeIndex;
    };
};