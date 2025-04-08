#include "meanFilter.h"

void MeanFilterInit(MeanFilter_t *filter, uint16_t *buffer, uint8_t size)
{
    filter->buffer = buffer;
    filter->size = size;
    filter->oldest_index = 0;

    for (uint8_t i = 0; i < size; i++)
    {
        filter->buffer[i] = 0;
    }
}

void MeanFilterAddValue(MeanFilter_t *filter, uint16_t value)
{
    filter->buffer[filter->oldest_index] = value;
    filter->oldest_index = (filter->oldest_index + 1) % filter->size;
}

uint16_t MeanFilterGetMean(MeanFilter_t *filter)
{
    uint32_t sum = 0;
    for (uint8_t i = 0; i < filter->size; i++)
    {
        sum += filter->buffer[i];
    }
    return sum / filter->size;
}