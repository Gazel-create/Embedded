// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vmac.h for the primary calling header

#ifndef VERILATED_VMAC___024ROOT_H_
#define VERILATED_VMAC___024ROOT_H_  // guard

#include "verilated.h"


class Vmac__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vmac___024root final {
  public:

    // DESIGN SPECIFIC STATE
    VL_IN8(clk,0,0);
    VL_IN8(reset,0,0);
    VL_IN8(data_in,7,0);
    VL_IN8(weight,7,0);
    CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    CData/*0:0*/ __VactPhaseResult;
    CData/*0:0*/ __VnbaPhaseResult;
    VL_OUT16(sum_out,15,0);
    IData/*31:0*/ __VactIterCount;
    VlUnpacked<QData/*63:0*/, 1> __VactTriggered;
    VlUnpacked<QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vmac__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vmac___024root(Vmac__Syms* symsp, const char* namep);
    ~Vmac___024root();
    VL_UNCOPYABLE(Vmac___024root);

    // INTERNAL METHODS
    void __Vconfigure(bool first);
};


#endif  // guard
