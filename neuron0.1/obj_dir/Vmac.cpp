// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vmac__pch.h"
#include "verilated_vcd_c.h"

//============================================================
// Constructors

Vmac::Vmac(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vmac__Syms(contextp(), _vcname__, this)}
    , clk{vlSymsp->TOP.clk}
    , reset{vlSymsp->TOP.reset}
    , data_in{vlSymsp->TOP.data_in}
    , weight{vlSymsp->TOP.weight}
    , sum_out{vlSymsp->TOP.sum_out}
    , rootp{&(vlSymsp->TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vmac::Vmac(const char* _vcname__)
    : Vmac(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vmac::~Vmac() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vmac___024root___eval_debug_assertions(Vmac___024root* vlSelf);
#endif  // VL_DEBUG
void Vmac___024root___eval_static(Vmac___024root* vlSelf);
void Vmac___024root___eval_initial(Vmac___024root* vlSelf);
void Vmac___024root___eval_settle(Vmac___024root* vlSelf);
void Vmac___024root___eval(Vmac___024root* vlSelf);

void Vmac::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vmac::eval_step\n"); );
#ifdef VL_DEBUG
    // Debug assertions
    Vmac___024root___eval_debug_assertions(&(vlSymsp->TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
    if (VL_UNLIKELY(!vlSymsp->__Vm_didInit)) {
        VL_DEBUG_IF(VL_DBG_MSGF("+ Initial\n"););
        Vmac___024root___eval_static(&(vlSymsp->TOP));
        Vmac___024root___eval_initial(&(vlSymsp->TOP));
        Vmac___024root___eval_settle(&(vlSymsp->TOP));
        vlSymsp->__Vm_didInit = true;
    }
    VL_DEBUG_IF(VL_DBG_MSGF("+ Eval\n"););
    Vmac___024root___eval(&(vlSymsp->TOP));
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

//============================================================
// Events and timing
bool Vmac::eventsPending() { return false; }

uint64_t Vmac::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vmac::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

void Vmac___024root___eval_final(Vmac___024root* vlSelf);

VL_ATTR_COLD void Vmac::final() {
    contextp()->executingFinal(true);
    Vmac___024root___eval_final(&(vlSymsp->TOP));
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vmac::hierName() const { return vlSymsp->name(); }
const char* Vmac::modelName() const { return "Vmac"; }
unsigned Vmac::threads() const { return 1; }
void Vmac::prepareClone() const { contextp()->prepareClone(); }
void Vmac::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vmac::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vmac___024root__trace_decl_types(VerilatedVcd* tracep);

void Vmac___024root__trace_init_top(Vmac___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedVcd* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vmac___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vmac___024root*>(voidSelf);
    Vmac__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vmac___024root__trace_decl_types(tracep);
    Vmac___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vmac___024root__trace_register(Vmac___024root* vlSelf, VerilatedVcd* tracep);

VL_ATTR_COLD void Vmac::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedVcdC* const stfp = dynamic_cast<VerilatedVcdC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vmac::trace()' called on non-VerilatedVcdC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->TOP), name(), false, 5);
    Vmac___024root__trace_register(&(vlSymsp->TOP), stfp->spTrace());
}
