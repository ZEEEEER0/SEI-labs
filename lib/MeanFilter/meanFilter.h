#ifndef MEANFILTER_H
#define MEANFILTER_H

#include <stdint.h>

typedef struct
{
    uint16_t *buffer;
    uint8_t size;
    uint8_t oldest_index;
} MeanFilter_t;

void MeanFilterInit(MeanFilter_t *filter, uint16_t *buffer, uint8_t size);
void MeanFilterAddValue(MeanFilter_t *filter, uint16_t value);
uint16_t MeanFilterGetMean(MeanFilter_t *filter);

#endif // MEANFILTER_H