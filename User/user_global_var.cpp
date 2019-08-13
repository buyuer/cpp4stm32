#include "user_global_var.hpp"

using namespace UPRE;

Robot& robot = *(new Robot_A1(0.0f,0.0f,0.78539815f));

Handle handle;

Motor_CDS& cds1 = *(new Motor_CDS(0X22));
Motor_CDS& cds2 = *(new Motor_CDS(0X31));