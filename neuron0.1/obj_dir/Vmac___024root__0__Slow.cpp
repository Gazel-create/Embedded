// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vmac.h for the primary calling header

#include "Vmac__pch.h"

VL_ATTR_COLD void Vmac___024root___eval_static(Vmac___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___eval_static\n"); );
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.clk;
}

VL_ATTR_COLD void Vmac___024root___eval_initial(Vmac___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___eval_initial\n"); );
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmac___024root___eval_final(Vmac___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___eval_final\n"); );
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vmac___024root___eval_settle(Vmac___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___eval_settle\n"); );
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vmac___024root___trigger_anySet__act(const VlUnpacked<QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vmac___024root___dump_triggers__act(const VlUnpacked<QData/*63:0*/, 1> &triggers, const std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (IData)(Vmac___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vmac___024root___ctor_var_reset(Vmac___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vmac___024root___ctor_var_reset\n"); );
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->reset = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 9928399931838511862ull);
    vlSelf->data_in = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 10574596302020702150ull);
    vlSelf->weight = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14629473433807880010ull);
    vlSelf->sum_out = VL_SCOPED_RAND_RESET_I(16, __VscopeHash, 10482379372276599054ull);
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VactTriggered[__Vi0] = 0;
    }
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        vlSelf->__VnbaTriggered[__Vi0] = 0;
    }
}
