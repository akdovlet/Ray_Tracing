#include "data_file.h"

double _clamp(double x, double upr, double lowr)
{
    return (fmin(upr, fmax(x, lowr)));
}

t_data_vec3 vec3_clamp(t_data_vec3 v, double upr, double lowr)
{
    return ((t_data_vec3) {
            v.x = _clamp(v.x, upr, lowr),
            v.y = _clamp(v.y, upr, lowr),
            v.z = _clamp(v.z, upr, lowr) });
}
