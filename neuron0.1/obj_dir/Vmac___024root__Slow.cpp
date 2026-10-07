// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmac.h for the primary calling header

#include "Vmac__pch.h"

void Vmac___024root___ctor_var_reset(Vmac___024root* vlSelf);

Vmac___024root::Vmac___024root(Vmac__Syms* symsp, const char* namep)
 {
    vlSymsp = symsp;
    vlNamep = strdup(namep);
    // Reset structure values
    Vmac___024root___ctor_var_reset(this);
}

void Vmac___024root::__Vconfigure(bool first) {
    (void)first;  // Prevent unused variable warning
}

Vmac___024root::~Vmac___024root() {
    VL_DO_DANGLING(std::free(const_cast<char*>(vlNamep)), vlNamep);
}
