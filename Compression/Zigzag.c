#include "Zigzag.h"

const unsigned char zigzagOrder[64][2] =
{
    {0, 0}, {0, 1}, {1, 0}, {2, 0}, {1, 1}, {0, 2}, {0, 3}, {1, 2},
    {2, 1}, {3, 0}, {4, 0}, {3, 1}, {2, 2}, {1, 3}, {0, 4}, {0, 5},
    {1, 4}, {2, 3}, {3, 2}, {4, 1}, {5, 0}, {6, 0}, {5, 1}, {4, 2},
    {3, 3}, {2, 4}, {1, 5}, {0, 6}, {0, 7}, {1, 6}, {2, 5}, {3, 4},
    {4, 3}, {5, 2}, {6, 1}, {7, 0}, {7, 1}, {6, 2}, {5, 3}, {4, 4},
    {3, 5}, {2, 6}, {1, 7}, {2, 7}, {3, 6}, {4, 5}, {5, 4}, {6, 3},
    {7, 2}, {7, 3}, {6, 4}, {5, 5}, {4, 6}, {3, 7}, {4, 7}, {5, 6},
    {6, 5}, {7, 4}, {7, 5}, {6, 6}, {5, 7}, {6, 7}, {7, 6}, {7, 7}
};

void ZIGZAG_Zigzag(int16_t** quantizedBlock, int16_t* output)
{
    for (int i = 0; i < 64; i++)
    {
        int x = zigzagOrder[i][0];
        int y = zigzagOrder[i][1];

        output[i] = quantizedBlock[y][x];
    }
}

void ZIGZAG_ToBlock(int16_t* zigzagBlock, int16_t** outputBlock)
{
    for (int i = 0; i < 64; i++)
    {
        int x = zigzagOrder[i][0];
        int y = zigzagOrder[i][1];

        outputBlock[y][x] = zigzagBlock[i];
    }
}