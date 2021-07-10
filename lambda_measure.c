#include "lambda_measure.h"

void Calculate_Lambda_Dominant()
{
    double x1 = 0.3333, y1 = 0.3333, x2, y2, triangle_p1, triangle_p2, triangle_p3,
           triangle_out, distance_divider, d_min, distance_d[D_SIZE]= {0};

    x2 = colorimetry_xy1931[0];
    y2 = colorimetry_xy1931[1];

    triangle_p1 = (((x2 - x34_dominant[0])*(y34_dominant[0] - y1) + (y2 - y34_dominant[0])*(x1 - x34_dominant[0]))>0) ? 1 : -1;
    triangle_p2 = (((x2-x1)*(y1 - y34_dominant[D_SIZE-1])+(y2-y1)*(x34_dominant[D_SIZE-1]-x1))>0) ? 1 : -1;
    triangle_p3 = (((x2-x34_dominant[D_SIZE-1])*(y34_dominant[D_SIZE-1] - y34_dominant[0])+(y2 - y34_dominant[D_SIZE-1])*(x34_dominant[0]-x34_dominant[D_SIZE-1]))>0) ? 1 : -1;

    triangle_out = (triangle_p1 < 0 && triangle_p2 < 0 && triangle_p3 <0) ? 1 : 0;

    distance_divider = sqrt(((x2-x1)*(x2-x1))+((y2-y1)*(y2-y1)));

    for(int i = 0; i < D_SIZE; i++)
    {
        distance_d[i] = fabs(((y1-y2)*x34_dominant[i] + (x2-x1)*y34_dominant[i] + (x1*y2 - x2*y1))/distance_divider);
    }

    d_min = distance_d[0];

    if(triangle_out)
    {
        if(x2 <= x1)
        {
            for(int i = START_POINT; i < D_SIZE; i++)
            {
                if(d_min  > distance_d[i])
                {
                    d_min = distance_d[i];
                }
            }
        }
        else
        {
            for(int i = 0; i < START_POINT; i++)
            {
                if(d_min  > distance_d[i])
                {
                    d_min = distance_d[i];
                }
            }
        }
    }
    else
    {
        if(x2 <= x1)
        {
            for(int i = 0; i < START_POINT; i++)
            {
                if(d_min  > distance_d[i])
                {
                    d_min = distance_d[i];
                }
            }
        }
        else
        {
            for(int i = START_POINT; i < D_SIZE; i++)
            {
                if(d_min  > distance_d[i])
                {
                    d_min = distance_d[i];
                }
            }
        }
    }
}
