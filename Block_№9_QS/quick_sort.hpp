#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
#include <concepts>
#include "Exception.hpp"


template<typename RandomAccessIterator>
constexpr bool Iter = std::is_same_v<std::random_access_iterator_tag,
    typename std::iterator_traits<RandomAccessIterator>::iterator_category>;

template<typename RandomAccessIterator, typename Compare>
constexpr bool Comporator = std::is_invocable_r_v<bool, Compare,
    typename std::iterator_traits<RandomAccessIterator>::value_type,
    typename std::iterator_traits<RandomAccessIterator>::value_type>;

template<typename RanAccIter, typename Compare>
typename std::enable_if_t<Iter<RanAccIter> && Comporator<RanAccIter, Compare>, void >
quick_sort(RanAccIter first, RanAccIter last, Compare comp)
{
    if (first > last) 
    {
        throw Invalid_value_exception();
    }

    size_t size = std::distance(first, last);

    if (size < 2)
    {
        return;
    }


    RanAccIter head = first;
    RanAccIter tail = std::prev(last);
    auto pivot = first[size / 2];

    while (true)
    {
        while (comp(*head, pivot))
            ++head;
        while (comp(pivot, *tail))
            --tail;
        if (head >= tail)
        {
            break;
        }
        std::iter_swap(head++, tail--);
    }

    quick_sort(first, head, comp);
    quick_sort(head, last, comp);
}

template<typename RanAccIter>
typename std::enable_if_t<Iter<RanAccIter>, void >
quick_sort(RanAccIter first, RanAccIter last)
{
    quick_sort(first, last, std::less< typename std::iterator_traits< RanAccIter >::value_type >());
}