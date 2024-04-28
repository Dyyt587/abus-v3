#include "t_speed_planning_offline.h"



#define POW2(x)((x)*(x))
//以加速度为限制
void t_speed_planning(float v0, float vt, float vm,float fmacc, float fmdac, float x0,float xt, float outt[3])
{
    /*假设可以达到vm*/
    float delta_x = xt - x0;
    float delta_x1;// = (POW2(vm) - POW2(v0)) / (2 * fmacc);

    if (v0 > vm) {
        /*要先减速*/
        delta_x1 = (POW2(vm) - POW2(v0)) / (2 * -fmdac);
        if (delta_x1 > delta_x) {
            /*纯减速,最大减速度*/
            outt[0] = 0;
            outt[1] = 0;
            outt[2] = (v0 + sqrt(POW(v0) - 2 * fmdac * delta_x)) / fmdac;//已经超时间

        }
        else {
            /*纯减速,减速度*/
            float acc = (v0 - vt) / ;
            outt[0] = 0;
            outt[1] = 0;
            outt[2] = t;
        }

    }
    else {
        delta_x1 = (POW2(vm) - POW2(v0)) / (2 * fmacc);
        if (delta_x1 > delta_x) {
            /*不可以可以达到速度vm*/
            float vm_1 = sqrt(-(fmacc - fmdac) * (fmdac * POW2(v0) - fmacc * POW2(vt) - 2 * fmacc * fmdac * x0 + 2 * fmacc * fmdac * xt)) / (fmacc - fmdac);
            outt[0] = (POW2(vm_1) - POW2(v0)) / (2 * fmacc);
            outt[1] = outt[0] + 0;
            outt[2] = outt[1] + (POW2(vm_1) - POW2(v0)) / (2 * -fmdac);
        }
        else {
            outt[0] = (POW2(vm) - POW2(v0)) / (2 * fmacc);
            outt[1] = outt[0] + (delta_x - delta_x1) / vm;
            outt[2] = outt[1] + (POW2(vm) - POW2(v0)) / (2 * -fmdac);
        }
    }
    
}




void t_speed_planning_t(float v0, float vt, float vm, float fmacc, float fmdac, float x0, float xt,float t, float outt[3])
{
    /*假设可以达到vm*/
    float delta_x = xt - x0;
    float delta_x1;// = (POW2(vm) - POW2(v0)) / (2 * fmacc);
    delta_x1 = (POW2(vm) - POW2(v0)) / (2 * fmacc) + (POW2(vt) - POW2(vm)) / (2 * -fmdac);

    float delta_x2 = v0*t;
        if (delta_x1 > delta_x) {
            /*达不到要求vm*/
        }
        else {

        }

}









void sfun_myc_Outputs_wrapper(float u0,
    float u1,
    float u2,
    float t,
    float* y0,
    float* y1,
    float* y2)
{
    /* %%%-SFUNWIZ_wrapper_Outputs_Changes_BEGIN --- EDIT HERE TO _END */
    /* 此示例设置输出等于输入
          y0[0] = u0[0];
     对于复杂信号使用: y0[0].re = u0[0].re;
          y0[0].im = u0[0].im;
          y1[0].re = u1[0].re;
          y1[0].im = u1[0].im;
    */

    /* %%%-SFUNWIZ_wrapper_Outputs_Changes_END --- EDIT HERE TO _BEGIN */
    int Am = u0;
    int Vm = u1;
    int Pf = u2;
    int T = t;

    int Ta = Vm / Am;
    int Tm = (Pf - Am * Ta * Ta) / Vm;
    int Tf = 2 * Ta + Tm;
    printf("%d\r\n", Tf);
    //梯形
    if (Tm > 0) {
        if (T <= Ta) {
            y0 = 0.5 * Am * T * T;
            y1 = Am * T;
            y2 = Am;
        }
        else if (T <= (Ta + Tm)) {
            y0 = 0.5 * Am * Ta * Ta + Vm * (T - Ta);
            y1 = Vm;
            y2 = 0;
        }
        else if (T <= (Ta + Tm + Ta)) {
            y0 = 0.5 * Am * Ta * Ta + Vm * Tm + 0.5 * Am * (T - Ta - Tm) * (T - Ta - Tm);
            y1 = Vm - Am * (T - Ta - Tm);
            y2 = -Am;
        }
    }
    else {
        //三角形
        Ta = sqrt(Pf / Am);
        if (T < Ta) {
            y0 = 0.5 * Am * T * T;
            y1 = Am * T;
            y2 = Am;
        }
        else {
            y0 = 0.5 * Am * Ta * Ta + 0.5 * Am * (T - Ta) * (T - Ta);
            y1 = Am * Ta - Am * (T - Ta);
            y2 = -Am;
        }
    }
}