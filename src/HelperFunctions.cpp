#include "HelperFunctions.hpp"

unsigned int linear_system::NchooseK(unsigned int N, unsigned int K)
{
    double ret = 1;
    for (unsigned int i = 1; i <= K; i++)
        ret *= (N + 1 - i)/(double)i;
    return (unsigned int)ret;
}

void linear_system::wrap2pi(double & ang)
{
    ang = std::fmod(ang,2*M_PI);
    if (ang > M_PI)
        ang -= 2*M_PI;
    else if (ang <= -M_PI)
        ang += 2*M_PI;
}

void linear_system::wrap2pi(Eigen::VectorXd &ang)
{
    for (unsigned int i = 0; i < ang.size(); ++i)
        wrap2pi(ang(i));
}

double linear_system::resonant2cutoff(double w, double damp)
{
    w = w*w;
    double b = 2*w*(2*damp*damp - 1);
    return std::sqrt( -b/2 + sqrt(b*b/4 + w*w) );
}

double linear_system::cutoff2resonant(double w, double damp)
{
    w = w*w;
    double b = 2*w*(1 - 2*damp*damp);
    return std::sqrt( -b/2 + sqrt(b*b/4 + w*w) );
}
